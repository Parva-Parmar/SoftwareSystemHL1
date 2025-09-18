/*
============================================================================
Name : 29.c
Author : parva parmar
Description : 
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
============================================================================
*/

#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

struct sched_param p;

int main(){
	p.sched_priority = 10;
	printf(" ret = %d\n", sched_setscheduler(0,SCHED_FIFO,&p));
	printf("\nThe scheduling policy is = %d\n",sched_getscheduler(getpid()));
	printf(" ret = %d\n",sched_setscheduler(0,SCHED_RR,&p));
	printf("\nThe scheduling policy is = %d\n",sched_getscheduler(getpid()));
}

/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q29$ gcc Q29.c -o Q29
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q29$ ./Q29
 ret = -1

The scheduling policy is = 0
 ret = -1

The scheduling policy is = 0

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q29$ sudo ./Q29
[sudo] password for deku: 
 ret = 0

The scheduling policy is = 1
 ret = 0

The scheduling policy is = 2

*/