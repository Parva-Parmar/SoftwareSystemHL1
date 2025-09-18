/*
============================================================================
Name : 17a.c
Author : parva parmar
Description : 
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
============================================================================
*/

#include <stdio.h>       
#include <unistd.h>     
#include <fcntl.h> 

int main(){
	struct {
		int ticket_no;
	} db;

	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);

	printf("before entering into cretical section");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");

	read(fd,&db,sizeof(db));
	printf("Current ticket number: %d\n", db.ticket_no);
	db.ticket_no++;
	
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	
	printf("Press enter to unlock\n");
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Exited critical section\n");	
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ gcc ticketInfo.c -o tInfo
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ gcc ticketInc.c -o tInc
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInfo
Ticket no: 0
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInc
before entering into cretical sectionInside the critical section
Current ticket number: 0
Press enter to unlock

Exited critical section
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInc
before entering into cretical sectionInside the critical section
Current ticket number: 1
Press enter to unlock
^[[A
Exited critical section
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInc
before entering into cretical sectionInside the critical section
Current ticket number: 2
Press enter to unlock

Exited critical section
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInc
before entering into cretical sectionInside the critical section
Current ticket number: 3
Press enter to unlock

Exited critical section
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ ./tInc
before entering into cretical sectionInside the critical section
Current ticket number: 4
Press enter to unlock

Exited critical section
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q17$ 
*/