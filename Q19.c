/*
============================================================================
Name : 19.c
Author : parva parmar
Description : 
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(){
	int i,nano;
	unsigned long long int start,end;
	start = rdtsc();
	for(i=0; i<=10 ; i++){
		getppid();
	}
	end = rdtsc();
	nano = (end - start)/2.40;
	printf("The function take %d nano sec\n", nano);
}

/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q19$ gcc Q19.c -o Q19
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q19$ ./Q19
The function take 22565 nano sec
*/