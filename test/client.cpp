#include <iostream>
#include <regex>
#include "../src/TCPClient.h"

int main(int argc, char *argv[])
{
    TCPClient tcp;
    tcp.setup("10.0.0.1",11999);
    string msg = "G";
    regex test { "^Cur_position: [0-9]{1,3}\.[0-9]+,[0-9]{1,3}\.[0-9]+,[0-9]{1,3}\.[0-9]+$" };
    regex test2 { "^New_position: [0-9]{1,3}\.[0-9]+,[0-9]{1,3}\.[0-9]+,[0-9]{1,3}\.[0-9]+$" };
    tcp.Send(msg);
    string rec = tcp.receive();
    if( regex_match(rec, test))
    {
        cout << "send G : Ok receive : " << rec << endl;
    }
    else
        cout << "ERR G: " << rec << endl;

    usleep(1000);


    msg = "H";
    tcp.Send(msg);
    rec = tcp.receive();
    if( regex_match(rec, test))
    {
        cout << "send H : Ok receive : " << rec << endl;
    }
    else
        cout << "ERR H : " << rec << endl;
    usleep(1000);


    msg = "MR15";
    tcp.Send(msg);
    rec = tcp.receive();
    if( regex_match(rec, test))
    {
        cout << "send MR15 : Ok receive : " << rec << endl;
    }
    else
        cout << "ERR MR15 : " << rec << endl;
    usleep(1000);


    msg = "MY30";
    tcp.Send(msg);
    rec = tcp.receive();
    if( regex_match(rec, test))
    {
        cout << "send MY30 : Ok receive : " << rec << endl;
    }
    else
        cout << "ERR MY30: " << rec << endl;
    usleep(1000);

    msg = "MR25;MY15";
    tcp.Send(msg);
    rec = tcp.receive();
    if( regex_match(rec, test))
    {
        cout << "send MR25;MY15 : Ok receive : " << rec << endl;
    }
    else
        cout << "ERR MR25;MY15 : " << rec << endl;
    usleep(1000);
    return 0;
}

