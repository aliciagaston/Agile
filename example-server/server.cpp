#include <iostream>
#include "../src/TCPServer.h"

#include "../src/ArduinoManager.h"

TCPServer tcp;

/*Test Arduino Card Values */
const int CPORT_NR=16;  /* /dev/ttyUSB0 */
const int BDRATE=115200; /* 9600 baud */

/*Arduino instructions */
const std::string HOME="H";
const std::string H_MOTOR="MY";
const std::string V_MOTOR="MR";
const std::string POS="G";

enum AduinoIntructions {
    
};

/**
 * get message from client
 */
void handleClientRequest() {
    string client_msg = tcp.getMessage();
}

/**
 * server start
 * @param m
 * @return
 */
void * loop(void * m)
{
    char mode[4]={'8','N','1',0};
    pthread_detach(pthread_self());
    auto * arduino = new ArduinoManager(CPORT_NR, BDRATE);
    arduino->connect();
    string str = "";
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

    delete arduino;
    tcp.detach();
}

int main()
{
    pthread_t msg;
    tcp.setup(11999);
    if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
    {
        tcp.receive();
    }
    return 0;
}