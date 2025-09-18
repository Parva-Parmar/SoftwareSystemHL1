/*
============================================================================
Name : 25.c
Author : parva parmar
Description : 
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int i,j,k;
	if(!(i=fork())){
		sleep(1);
	}
	else if(!(j=fork())){
		sleep(3);
	}
	else if(!(k=fork())){
		sleep(10);
	}	
	else
		waitpid(k,NULL,0);
	perror("ret: ");
}

/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q25$ ./Q25
ret: : Success
ret: : Success
ret: : Success
ret: : Success
*/