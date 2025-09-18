/*
============================================================================
Name : 18a.c
Author : parva parmar
Description : 
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Train {
    int train_num;
    int ticket_count;
};

int main() {
    int i, fd;
    struct Train db[3];

    for (i = 0; i < 3; i++) {
        db[i].train_num = i + 1;
        db[i].ticket_count = 0;
    }

    fd = open("record.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
    write(fd, db, sizeof(db));
    close(fd);

    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q18$ gcc Q18a.c -o init
gcc Q18b.c -o lock
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q18$ ./init
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q18$ ./lock
Select train number (1-3): 1
1. Read ticket count
2. Book a ticket
2
Ticket booked. New count: 1
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q18$ ./lock                      
Select train number (1-3): 1
1. Read ticket count
2. Book a ticket
2
Ticket booked. New count: 2
*/