/*
============================================================================
Name : 21.c
Author : parva parmar
Description : 
Write a program, call fork and print the parent and child process id.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(!pid){
		printf("Child process: PID = %d\n",getpid());
	}
	else{
		printf("Parent process: PPID = %d\n",getppid());
	}
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q21$ gcc Q21.c -o Q21
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q21$ ./Q21
Parent process: PPID = 6940
Child process: PID = 11012
*/