#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "rs232.h"

#define BUF_SIZE 128


int main() {
    int i=0;

    char mode[4]={'8','N','1',0}; // 8 data bits, no parity, 1 stop bit
    char str_send[2][BUF_SIZE]; // send data buffer
    unsigned char str_recv[BUF_SIZE]; // recv data buffer
    strcpy(str_send[0], "H");
    strcpy(str_send[1], "MY45.2");

    }
}

