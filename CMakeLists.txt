cmake_minimum_required(VERSION 3.8)
project(Agile)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        client/client.cpp
        server/server.cpp
        src/ArduinoManager.cpp
        src/ArduinoManager.h
        src/TCPClient.cpp
        src/TCPClient.h
        src/TCPServer.cpp
        src/TCPServer.h
        src/rs232.c
        src/rs232.h clientudp/client_udp.cpp clientudp/UDPClient.cpp clientudp/UDPClient.h)

add_executable(Agile ${SOURCE_FILES})