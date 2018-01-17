#ifndef AGILE_ADRUINOMANAGER_H
#define AGILE_ADRUINOMANAGER_H

#include <iostream>
#include <unistd.h>
#include <regex>
#include "rs232.h"


#define BUF_SIZE 128

/**
 * @class - Manage communication between raspberry and arduino
 */
class ArduinoManager {
private:
    char m_mode[4]={'8','N','1',0};
    int m_cport_nr;
    int m_bdrate;
    unsigned char str_recv[BUF_SIZE]; // recv data buffer
public:
    ArduinoManager(int cport_nr, int bdrate);
    void connect();
    int handleClientRequest(std::string raw);
    void send(std::string str);
    std::string receive();
};


#endif //AGILE_ADRUINOMANAGER_H
