#include "ArduinoManager.h"

using namespace std;

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
int ArduinoManager::handleClientRequest(std::string raw) {
    /* Regex for Motor Yaw command */
    regex clientPattern { "^MR-?[0-9]{1,3}(\.[0-9]{1,2})?;MY-?[0-9]{1,3}(\.[0-9]{1,2})?$" };


    if(raw=="H" || raw == "G") {
        this->send(raw);
        return 0;
    } 
    else if(regex_match(raw, clientPattern)) {
        /*create a vector containing each command, thanks to explode function wich use a separator to split string. */
        vector<string> cmds{explode(raw, ',')};
        
        for(const string &cmd : cmds) {
            this->send(cmd);
        }
        return 0;
    } 
    else if( raw == "scan") {
        return 1;
    } 
    else {
        return -1;
    }
}

/**
 * Method to send command to arduino, sleep 1s to wait reply.
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
 * Connect to arduino through serial port.
 *
 */
void ArduinoManager::connect() {
    std::cout << RS232_OpenComport(m_cport_nr, m_bdrate, m_mode) ? "Can not open comport" : "Comport open";
    usleep(2000000);  /* waits 2000ms for stable condition */
}

/**
 *  Listen if arduino return message.
 *
 * @return response string or error message.
 */
std::string ArduinoManager::receive() {
    int n = RS232_PollComport(m_cport_nr, str_recv, (int)BUF_SIZE);
    if(n > 0){
        cout << "Message send to client " << str_recv << endl;
        str_recv[n] = 0;   /* always put a "null" at the end of a string! */
        std::string resp;
        for(char a : str_recv) {
            resp+=a;
        }
        return resp;
    } else {
        return "Position can't be send.";
    }
}

/**
 * Split a string with a separator
 * @param string s to be parsed
 * @param char c separator
 * @return vector containing each splited string
 */
const vector<string> ArduinoManager::explode(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}
