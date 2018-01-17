//
// Created by macouta on 1/16/18.
//

#include "ArduinoManager.h"

/**
 *
 */
ArduinoManager::ArduinoManager(int cport_nr, int bdrate) {
    m_cport_nr = cport_nr;
    m_bdrate = bdrate;
}

/**
 *
 * @param string msg, message sent to Arduino
 */
void ArduinoManager::send(std::string str) {
    char msg[BUF_SIZE];
    RS232_cputs(m_cport_nr, strcpy(msg, str.c_str())); // sends string on serial
    std::cout << "Sent to Arduino : " << msg << std::endl;
    usleep(1000000);  /* waits for reply 1000ms */
}

/**
 *
 */
void ArduinoManager::connect() {
    std::cout << RS232_OpenComport(m_cport_nr, m_bdrate, m_mode) ? "Can not open comport" : "Comport open";
    usleep(2000000);  /* waits 2000ms for stable condition */
}

/**
 *
 */
std::string ArduinoManager::receive() {
    int n = RS232_PollComport(m_cport_nr, str_recv, (int)BUF_SIZE);
    if(n > 0){
        str_recv[n] = 0;   /* always put a "null" at the end of a string! */
        std::string resp;
        resp = str_recv;
        return resp;
    } else {
        return "Position can't be send.";
    }
}

