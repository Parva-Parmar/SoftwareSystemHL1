/*
============================================================================
Name : 11.c
Author : parva parmar
Description : 
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    char buf1[] = "Written using original FD\n";
    char buf2[] = "Written using duplicated FD\n";
    fd1 = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    printf("Original FD: %d\n", fd1);

    // Using dup  
    fd2 = dup(fd1);
    printf("FD duplicated with dup: %d\n", fd2);

    write(fd1, buf1, sizeof(buf1) - 1);
    write(fd2, buf2, sizeof(buf2) - 1);

    // Using dup2  
    fd2 = dup2(fd1, 100);   
    printf("FD duplicated with dup2: %d\n", fd2);

    write(fd1, "Again using original FD\n", 24);
    write(fd2, "Again using dup2 FD\n", 21);

    // Using fcntl  
    fd2 = fcntl(fd1, F_DUPFD, 50);    
    printf("FD duplicated with fcntl: %d\n", fd2);

    write(fd1, "Write via original FD (fcntl test)\n", 34);
    write(fd2, "Write via fcntl duplicated FD\n", 30);

    close(fd1);
    close(fd2);
    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q11$ gcc Q11.c -o Q11
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q11$ ./Q11
Original FD: 3
FD duplicated with dup: 4
FD duplicated with dup2: 100
FD duplicated with fcntl: 50
*/