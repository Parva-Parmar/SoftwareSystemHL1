/*
============================================================================
Name : 1.c
Author : Parva Parmar
Description :
Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // ---- Soft Link ----
    if (symlink("test.txt", "softlink.txt") == 0) {
        printf("Soft Link created successfully: %s -> %s\n", "softlink.txt", "test.txt");
    } else {
        perror("Error creating Soft Link");
    }

    // ---- Hard Link ----
    if (link("test.txt", "hardlink.txt") == 0) {
        printf("Hard Link created successfully: %s -> %s\n", "hardlink.txt", "test.txt");
    } else {
        perror("Error creating Hard Link");
    }

    // ---- FIFO ----
    if (mkfifo("myfifo", 0666) == 0) {
        printf("FIFO created successfully: %s\n", "myfifo");
    } else {
        perror("Error creating FIFO");
    }

    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q1$ gcc Q1.c -o Q1
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q1$ ./Q1
Soft Link created successfully: softlink.txt -> test.txt
Hard Link created successfully: hardlink.txt -> test.txt
FIFO created successfully: myfifo
*/