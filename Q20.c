/*
============================================================================
Name : 20.c
Author : parva parmar
Description : 
Find out the priority of your running program. Modify the priority with nice command.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<stdlib.h>

int main(){
	printf("The priority of the current proce is = %d\n", getpriority(PRIO_PROCESS,0));
	nice(-4);
	perror("nice: ");
	printf("The modified priority = %d\n",getpriority(PRIO_PROCESS,0));

	setpriority(PRIO_PROCESS,0,5);
	printf("The modified priority = %d\n",getpriority(PRIO_PROCESS,0));
}

/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q20$ gcc Q20.c -o Q20


deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q20$ ./Q20
The priority of the current proce is = 0
nice: : Operation not permitted
The modified priority = 0
The modified priority = 5


deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q20$ sudo ./Q20
[sudo] password for deku: 
The priority of the current proce is = 0
nice: : Success
The modified priority = -4
The modified priority = 5

*/