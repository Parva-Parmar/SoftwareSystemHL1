/*
============================================================================
Name : 24.c
Author : parva parmar
Description : 
Write a program to create an orphan process.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();    

   
    if (pid == 0) {
         
        sleep(5);    
        printf("I am child, my parent is gone so I am orphan now!\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else {
         
        printf("I am parent, exiting now...\n");
        exit(0);    
    }

    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q24$ gcc Q24.c -o Q24
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q24$ ./Q24 &
[1] 11590
I am parent, exiting now...
[1]+  Done                    ./Q24
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q24$ ps -ef | grep orphan
deku       11607    6940  0 15:54 pts/1    00:00:00 grep --color=auto orphan
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q24$ I am child, my parent is gone so I am orphan now!
Child PID: 11592, Parent PID: 2502

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q24$ 
*/