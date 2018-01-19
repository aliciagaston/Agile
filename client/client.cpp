#include <iostream>
#include "../src/TCPClient.h"

int main(int argc, char *argv[])
{
    if(argc >= 1)
    {
        string msg = argv[1];
        cout << "argument receive : " << msg << endl;
        TCPClient tcp;
        tcp.setup("10.0.0.1",11999);
        tcp.Send(msg);
        string rec = tcp.receive();
        if( rec != "" )
        {
            cout << rec << endl;
        }
        sleep(1);
        return 0;
    }
    else cout << "Error: message num-request" << endl;
}

