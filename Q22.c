/*
============================================================================
Name : 22.c
Author : parva parmar
Description : 
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	int fd;

	fd = open("newfile", O_WRONLY);

	if(!fork()){
		write(fd, "This is child process.. \n",26);
	}
	else{
		write(fd, "This is parent process.. \n",27);
	}
	wait(0);
}


/*

This is parent process..
^@This is child process..
^@
~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~       

*/