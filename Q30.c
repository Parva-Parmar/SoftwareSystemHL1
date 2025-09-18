/*
============================================================================
Name : 30.c
Author : Parva parmar
Description :30. Write a program to run a script at a specific time using a Daemon process.
Date: 
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        
        printf("Parent: Child created with PID %d\n", pid);
        exit(EXIT_SUCCESS); 
    } else {
        
        if (setsid() < 0) {
            perror("setsid failed");
            exit(EXIT_FAILURE);
        }

        printf("Child: Running as daemon (PID %d)\n", getpid());

        while (1) {
            time_t cur_time = time(NULL);
            struct tm *t = localtime(&cur_time);

            if (t->tm_hour == 16 && t->tm_min == 17) {
                printf("Child: OPEN DAEMON PROCESS...\n");
                system("./file.sh");
                break;
            }
            sleep(30);
        }
    }

    return 0;
}

/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q30$ ./Q30
Parent: Child created with PID 14276
Child: Running as daemon (PID 14276)
Child: OPEN DAEMON PROCESS...
This is Parva Parmar
MT2025085
 
*/