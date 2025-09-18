/*
============================================================================
Name : 14.c
Author : parva parmar
Description : 
Write a program to find the type of a file.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat fileStat;
    stat("test.txt", &fileStat);

    printf("File: %s\n", "test.txt");
    printf("Type: ");

    if (S_ISREG(fileStat.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO/pipe\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic link\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown type\n");

    return 0;
}


/*


deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q14$ ./Q14
File: test.txt
Type: Regular file


*/