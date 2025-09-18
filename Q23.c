/*
============================================================================
Name : 23.c
Author : parva parmar
Description : 
Write a program to create a Zombie state of the running program.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    pid_t pid;

    pid = fork();    

    if (pid == 0) {
         
        printf("Child process running...\n");
        exit(0);    
    }
    else {
         
        printf("Parent process sleeping, child is zombie now...\n");
        sleep(20);  
        
    return 0;
}

/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q23$ ./Q23 &
[1] 11330
Parent process sleeping, child is zombie now...
Child process running...
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q23$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    6940    6892  0  80   0 -  3145 do_wai pts/1    00:00:00 bash
0 S  1000   11330    6940  0  80   0 -   695 hrtime pts/1    00:00:00 Q23
1 Z  1000   11332   11330  0  80   0 -     0 -      pts/1    00:00:00 Q23 <defunct>
4 R  1000   11352    6940  0  80   0 -  2500 -      pts/1    00:00:00 ps
*/