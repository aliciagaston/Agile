//
// Created by macouta on 1/16/18.
//
using namespace std;

#include "ArduinoManager.h"

/**
 * ArduinoManager constructor
 *
 * @param cport_nr value to link Arduino with the program, used in rs232.h functions.
 * @param bdrate value to link Arduino with the program, used in rs232.h functions.
 */
ArduinoManager::ArduinoManager(int cport_nr, int bdrate) {
    m_cport_nr = cport_nr;
    m_bdrate = bdrate;
}

/**
 * Check what client sent to server and send the right command to arduino.
 *
 * @param string raw, client message sent to server.
 * @return 0, for normal arduino command, 1 for scan and -1 if not recognized command.
 */
 int ArduinoManager::handleClientRequest(string raw) {
    /* Regex for Motor Yaw command */
    regex horizontalPattern { "^MY-?[0-9]{1,3}(\.[0-9]{1,2})?$" };

    /* Regex for Motor Roll command */
    regex verticalPattern { "^MR-?[0-9]{1,3}(\.[0-9]{1,2})?$" };

    if(raw=="H" || raw == "G" || regex_match(raw, horizontalPattern) || regex_match(raw, verticalPattern) ) {
        this->send(raw);
        return 0;
    } else if( raw == "scan") {
        return 1;
    } else {
        return -1;
    }
}

/**
 * Method to send command to arduino, sleep 1s to wait reply.
 *
 * @param string msg, message sent to Arduino
 */
void ArduinoManager::send(string str) {
    char msg[BUF_SIZE];
    RS232_cputs(m_cport_nr, strcpy(msg, str.c_str())); // sends string on serial
    cout << "Sent to Arduino : " << msg << endl;
    usleep(1000000);  /* waits for reply 1000ms */
}

/**
 * Connect to arduino through serial port.
 *
 */
void ArduinoManager::connect() {
    if(RS232_OpenComport(m_cport_nr, m_bdrate, m_mode)) {
        cout << "Comport open, Arduino serial connexion done. "  << endl;
        usleep(2000000);  /* waits 2000ms for stable condition */
    } else {
        cout << "Can not open Comport, Arduino serial connexion failed." << endl;
    }

}

/**
 *  Listen if arduino return message.
 *
 * @return response string or error message.
 */
string ArduinoManager::receive() {
    string resp;
    int n = RS232_PollComport(m_cport_nr, str_recv, (int)BUF_SIZE);
    if(n > 0){
        str_recv[n] = 0;   /* always put a "null" at the end of a string! */
        for(char a : str_recv) {
            resp+=a;
        }
        cout << "REPONSE ARDUINO " << resp << endl;
        return resp;
    } else {
        return "Position can't be send.";
    }
}

