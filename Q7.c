/*
============================================================================
Name : 7.c
Author : parva parmar
Description : 
Write a program to copy file1 into file2 ($cp file1 file2).
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    char buffer[1024];
    int fd1, fd2, n;
    fd1 = open("input.txt", O_RDONLY);
    fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
 

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        if (write(fd2, buffer, n) != n) {
            perror("Error writing to output file");
            close(fd1);
            close(fd2);
            return 1;
        }
    }

    printf("File copied successfully: %s -> %s\n", "input.txt", "output.txt");

    close(fd1);
    close(fd2);

    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q7$ gcc Q7.c -o Q7
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q7$ ./Q7
File copied successfully: input.txt -> output.txt

*/