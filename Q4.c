/*
============================================================================
Name : 4.c
Author : parva parmar
Description : 
Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    fd = open("file2.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    printf("File opened successfully with file descriptor: %d\n", fd);
    close(fd);
    return 0;
}

/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q4$ gcc Q4.c -o Q4
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q4$ ./Q4
File opened successfully with file descriptor: 3
*/