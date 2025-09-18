/*
============================================================================
Name : 13.c
Author : parva parmar
Description : 
Write a program to wait for STDIN for 10 seconds using select.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);  

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN (10 seconds)...\n");

    ret = select(1, &readfds, NULL, NULL, &timeout);

    if (ret == 0) {
        printf("Timeout: No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            char buf[100];
            int n = read(0, buf, sizeof(buf) - 1);
            buf[n] = '\0';
            printf("You entered: %s\n", buf);
        }
    }

    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q13$ gcc Q13.c -o Q13
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q13$ ./Q13
Waiting for input on STDIN (10 seconds)...
Timeout: No data within 10 seconds.

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q13$ ./Q13
Waiting for input on STDIN (10 seconds)...
hi
You entered: hi

*/