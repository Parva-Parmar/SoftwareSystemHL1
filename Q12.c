/*
============================================================================
Name : 12.c
Author : parva parmar
Description : 
Write a program to find out the opening mode of a file. Use fcntl.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, flags, accmode;

     
    fd = open("testfile.txt", O_RDWR | O_APPEND);

     
    flags = fcntl(fd, F_GETFL);

    accmode = flags & O_ACCMODE;

    printf("File opened in: ");
    if (accmode == O_RDONLY)
        printf("read only");
    else if (accmode == O_WRONLY)
        printf("write only");
    else if (accmode == O_RDWR)
        printf("read/write");

    if (flags & O_APPEND)
        printf(", append mode");
    if (flags & O_NONBLOCK)
        printf(", non-blocking mode");
    if (flags & O_SYNC)
        printf(", synchronous writes");

    printf("\n");

    close(fd);
    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q12$ gcc Q12.c -o Q12
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q12$ ./Q12
File opened in: , append mode, non-blocking mode, synchronous writes
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q12$ gcc Q12.c -o Q12
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q12$ ./Q12
File opened in: read/write, append mode

*/