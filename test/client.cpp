#include <iostream>
#include "../src/TCPClient.h"

int main(int argc, char *argv[])
{

    TCPClient tcp;
    tcp.setup("10.0.0.1",11999);
    string msg = "H";
    tcp.Send(msg);
    string rec = tcp.receive();
    if( rec != "0000000000000000000000000000000000")
    {
        cout << "send H : Ok receive : " << rec << endl;
    }
    sleep(1);
    msg = "G";
    tcp.Send(msg);
    rec = tcp.receive();
    if( rec != "0000000000000000000000000000000000")
    {
        cout << "send H : Ok receive : " << rec << endl;
    }
    sleep(1);
    msg = "G";
    tcp.Send(msg);
    rec = tcp.receive();
    if( rec != "0000000000000000000000000000000000")
    {
        cout << "send H : Ok receive : " << rec << endl;
    }
    sleep(1);
    return 0;
}

