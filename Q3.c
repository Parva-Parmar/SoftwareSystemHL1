
/*
============================================================================
Name : 3.c
Author : Parva Parmar
Description :
Write a program to create a file and print the file descriptor value. Use creat() system call
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>    
#include <unistd.h>   
#include <stdlib.h>   

int main() {
    int fd;    
    fd = creat("test.txt", 0644);
    int fd2 = creat("test1.txt", 0644);
    printf("File created successfully. File descriptor: %d\n", fd);
    printf("File created successfully. File descriptor: %d\n", fd2);
    close(fd);
    close(fd2);
    return 0;
}

/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q3$ gcc Q3.c -o Q3
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q3$ ./Q3
File created successfully. File descriptor: 3
File created successfully. File descriptor: 4

*/