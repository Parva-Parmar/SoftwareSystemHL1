/*
============================================================================
Name : 18b.c
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
#include <sys/types.h>
#include <sys/stat.h>

struct Train {
    int train_num;
    int ticket_count;
};

int main() {
    int fd, input, choice;
    struct Train db;
    struct flock lock;

    fd = open("record.txt", O_RDWR);

    printf("Select train number (1-3): ");
    scanf("%d", &input);

    printf("1. Read ticket count\n");
    printf("2. Book a ticket\n");
    scanf("%d", &choice);

    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(struct Train);
    lock.l_len = sizeof(struct Train);
    lock.l_pid = getpid();

    if (choice == 1) {
        lock.l_type = F_RDLCK;
        fcntl(fd, F_SETLKW, &lock);

        lseek(fd, (input - 1) * sizeof(struct Train), SEEK_SET);
        read(fd, &db, sizeof(db));
        printf("Train %d tickets: %d\n", db.train_num, db.ticket_count);

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
    }
    else if (choice == 2) {
        lock.l_type = F_WRLCK;
        fcntl(fd, F_SETLKW, &lock);

        lseek(fd, (input - 1) * sizeof(struct Train), SEEK_SET);
        read(fd, &db, sizeof(db));
        db.ticket_count++;
        lseek(fd, (input - 1) * sizeof(struct Train), SEEK_SET);
        write(fd, &db, sizeof(db));
        printf("Ticket booked. New count: %d\n", db.ticket_count);

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
    }

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