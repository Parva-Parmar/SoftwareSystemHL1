/*
============================================================================
Name : 5.c
Author : parva parmar
Description : 
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
 
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];
    char filename[20];
    for (int i = 0; i < 5; i++) {
        sprintf(filename, "file%d.txt", i+1);
        fd[i] = open(filename, O_CREAT | O_RDWR, 0644);
        printf("Opened %s with fd = %d\n", filename, fd[i]);
    }

    for(;;);
         
    for (int i = 0; i < 5; i++) {
        close(fd[i]);
    }

    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q5$ gcc files_bg.c -o files_bg
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q5$ ./files_bg &
[1] 9915
Opened file1.txt with fd = 3
Opened file2.txt with fd = 4
Opened file3.txt with fd = 5
Opened file4.txt with fd = 6
Opened file5.txt with fd = 7
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q5$ ls -l /proc/9915/fd
total 0
lrwx------ 1 deku deku 64 Aug 20 10:10 0 -> /dev/pts/1
lrwx------ 1 deku deku 64 Aug 20 10:10 1 -> /dev/pts/1
lr-x------ 1 deku deku 64 Aug 20 10:10 103 -> /snap/code/204/usr/share/code/v8_context_snapshot.bin
lrwx------ 1 deku deku 64 Aug 20 10:10 2 -> /dev/pts/1
lrwx------ 1 deku deku 64 Aug 20 10:10 3 -> '/media/deku/Data/Software systems/hands-on-1/Q5/file1.txt'
lrwx------ 1 deku deku 64 Aug 20 10:10 4 -> '/media/deku/Data/Software systems/hands-on-1/Q5/file2.txt'
l-wx------ 1 deku deku 64 Aug 20 10:10 40 -> /home/deku/.config/Code/logs/20250820T093522/ptyhost.log
lrwx------ 1 deku deku 64 Aug 20 10:10 41 -> 'socket:[52490]'
lrwx------ 1 deku deku 64 Aug 20 10:10 5 -> '/media/deku/Data/Software systems/hands-on-1/Q5/file3.txt'
lrwx------ 1 deku deku 64 Aug 20 10:10 6 -> '/media/deku/Data/Software systems/hands-on-1/Q5/file4.txt'
lrwx------ 1 deku deku 64 Aug 20 10:10 7 -> '/media/deku/Data/Software systems/hands-on-1/Q5/file5.txt'
*/