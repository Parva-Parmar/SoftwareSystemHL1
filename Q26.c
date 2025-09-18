/*
============================================================================
Name : 26.c
Author : parva parmar
Description : 
Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Now executing another program...\n");
    execl("./a.out", "./a.out", "Parva", NULL);
    return 0;
}



/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ gcc hello.c
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ gcc Q26.c -o Q26
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ ./Q26
Now executing another program...
Hello, Parva!

*/