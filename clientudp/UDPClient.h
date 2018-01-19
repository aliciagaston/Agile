//
// Created by macouta on 1/18/18.
//

#ifndef AGILE_UDPCLIENT_H
#define AGILE_UDPCLIENT_H

#include <iostream>
#include <netdb.h>
#include <zconf.h>
#include <cstring>

class udp_client_server_runtime_error : public std::runtime_error
{
public:
    explicit udp_client_server_runtime_error(const char *w) : std::runtime_error(w) {}
};

class UDPClient {
public:
    UDPClient(const std::string& addr, int port);
    ~UDPClient();

    int                 get_socket() const;
    int                 get_port() const;
    std::string         get_addr() const;

    int                 send(const char *msg, size_t size);
    std::string receive();

private:
    int                 f_socket;
    int                 f_port;
    std::string         f_addr;

    struct addrinfo *   f_addrinfo;
};


#endif //AGILE_UDPCLIENT_H
