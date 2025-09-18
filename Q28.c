/*
============================================================================
Name : 28.c
Author : parva parmar
Description : 
Write a program to get maximum and minimum real time priority.
============================================================================
*/
 
#include<stdio.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("The max real time priority(FIFO) = %d\n",sched_get_priority_max(SCHED_FIFO));
	printf("The min real time priority(FIFO) = %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("The max real time priority(RR) = %d\n",sched_get_priority_max(SCHED_RR));
	printf("The min real time priority(RR) = %d\n",sched_get_priority_min(SCHED_RR));
	printf("The max real time priority(OTHER) = %d\n",sched_get_priority_max(SCHED_OTHER));
	printf("The min real time priority(OTHER) = %d\n",sched_get_priority_min(SCHED_OTHER));
}


/*
Output:

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q28$ gcc Q28.c -o Q28

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q28$ ./Q28
The max real time priority(FIFO) = 99
The min real time priority(FIFO) = 1
The max real time priority(RR) = 99
The min real time priority(RR) = 1
The max real time priority(OTHER) = 0
The min real time priority(OTHER) = 0

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q28$ chrt -max
SCHED_OTHER min/max priority	: 0/0
SCHED_FIFO min/max priority	: 1/99
SCHED_RR min/max priority	: 1/99
SCHED_BATCH min/max priority	: 0/0
SCHED_IDLE min/max priority	: 0/0
SCHED_DEADLINE min/max priority	: 0/0

*/