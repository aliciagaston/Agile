#include <iostream>
#include "../src/TCPServer.h"

#include "../src/ArduinoManager.h"

TCPServer tcp;

/* Test Arduino Card Values */
const int CPORT_NR=16;  /* /dev/ttyUSB0 */
const int BDRATE=115200; /* 9600 baud */


void handleClientRequest() {
    string client_msg = tcp.getMessage();

}


/**
 * Handle inputs and outputs
 *
 * @param ArduinoManager arduino, handle link with arduino.
 * @param string str, raw string sent by client.
 */
void IOHandler(ArduinoManager * arduino, const string &str) {
    cout << "===============================" << endl;
    cout << "Message from client : " << str << endl;
    if(arduino->handleClientRequest(str) == -1) {
        tcp.Send("ERROR");

    } else {
        //Receive positions from Arduino and send it to client
        arduino->send("G");
        tcp.Send(arduino->receive());
    }
    tcp.clean();
}

/**
 * Main loop for the TCP/IP server, connect to arduino and handle input and output.
 */
void * loop(void * m)
{
    char mode[4]={'8','N','1',0};
    pthread_detach(pthread_self());
    auto * arduino = new ArduinoManager(CPORT_NR, BDRATE);
    arduino->connect();
    string str = "";
    cout << "start loop" << endl;
    while(str != "quit") {
        str = tcp.getMessage();
        if( str != "" )
        {
            cout << "Message : " << str << endl;

            //Sent instruction to Arduino
            arduino->send(str);

            //Receive positions from Arduino and send it to client
            tcp.Send(arduino->receive());

            tcp.clean();
        }
        usleep(1000);
    }
    cout << "end loop" << endl;
    delete arduino;
    tcp.detach();
}

/**
 * Launching TCP/IP server in a thread.
 * @return 0
 */
int main()
{
    cout << "Server on." << endl;
    pthread_t msg;
    tcp.setup(11999);
    if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
    {
        tcp.receive();
    }
    return 0;
}