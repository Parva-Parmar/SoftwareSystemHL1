/*
============================================================================
Name : 8.c
Author : parva parmar
Description : 
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;
    char buffer[256];
    int n;   
    fd = open("input.txt", O_RDONLY);
    while ((n = read(fd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0';        
        write(1, buffer, n);     
    }
    close(fd);
    printf("\n");
    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q8$ gcc Q8.c -o Q8
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q8$ ./Q8
this is input.txt!
*/