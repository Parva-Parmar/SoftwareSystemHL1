/*
============================================================================
Name : 16.c
Author : parva parmar
Description : 
Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct flock lock;
    int fd, choice;

    fd = open("testLock.txt", O_RDWR);

    while (1) {
        printf("1. Write Lock\n");
        printf("2. Read Lock\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                lock.l_type = F_WRLCK;
                lock.l_whence = SEEK_SET;
                lock.l_start = 0;
                lock.l_len = 0;
                lock.l_pid = getpid();

                printf("Trying for write lock...\n");
                fcntl(fd, F_SETLKW, &lock);
                printf("Write lock acquired. Press Enter to unlock...\n");
                getchar();

                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Write lock released.\n");
                break;

            case 2:
                lock.l_type = F_RDLCK;
                lock.l_whence = SEEK_SET;
                lock.l_start = 0;
                lock.l_len = 0;
                lock.l_pid = getpid();

                printf("Trying for read lock...\n");
                fcntl(fd, F_SETLKW, &lock);
                printf("Read lock acquired. Press Enter to unlock...\n");
                getchar();

                lock.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lock);
                printf("Read lock released.\n");
                break;

            case 3:
                close(fd);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q16/a$ ./Q16
1. Write Lock
2. Read Lock
3. Exit
Enter choice: 1
Trying for write lock...
Write lock acquired. Press Enter to unlock...

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q16/a$ ./Q16
1. Write Lock
2. Read Lock
3. Exit
Enter choice: 1
Trying for write lock...



*/