/*
============================================================================
Name : 6.c
Author : parva parmar
Description : 
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
 
============================================================================
*/
#include <unistd.h>

int main() {
    char buf[100];
    int n;

    write(1, "Enter some text: ", 17);
    n = read(0, buf, sizeof(buf));
    write(1, "You entered: ", 13);
    write(1, buf, n);

    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q6$ ./Q6
Enter some text: hello
You entered: hello

*/