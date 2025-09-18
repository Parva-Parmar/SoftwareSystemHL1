/*
============================================================================
Name : 27.c
Author : parva parmar
Description : 
Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
============================================================================
*/

 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int choice;
    char *args[] = {"ls", "-Rl", NULL};
    char *envp[] = {NULL};   

    while (1) {
        printf("\n--- Exec Menu ---\n");
        printf("1. execl\n");
        printf("2. execlp\n");
        printf("3. execle\n");
        printf("4. execv\n");
        printf("5. execvp\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Using execl...\n");
                execl("/bin/ls", "ls", "-Rl", NULL);
                perror("execl failed");
                break;

            case 2:
                printf("Using execlp...\n");
                execlp("ls", "ls", "-Rl", NULL);
                perror("execlp failed");
                break;

            case 3:
                printf("Using execle...\n");
                execle("/bin/ls", "ls", "-Rl", NULL, envp);
                perror("execle failed");
                break;

            case 4:
                printf("Using execv...\n");
                execv("/bin/ls", args);
                perror("execv failed");
                break;

            case 5:
                printf("Using execvp...\n");
                execvp("ls", args);
                perror("execvp failed");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/*
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q27$ gcc Q27.c -o Q27
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q27$ ./Q27

--- Exec Menu ---
1. execl
2. execlp
3. execle
4. execv
5. execvp
6. Exit
Enter choice: 1
Using execl...
.:
total 20
-rwxrwxrwx 1 deku deku 16344 Sep  7 16:02 Q27
-rwxrwxrwx 1 deku deku  1559 Sep  7 16:01 Q27.c
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q27$ ./Q27

--- Exec Menu ---
1. execl
2. execlp
3. execle
4. execv
5. execvp
6. Exit
Enter choice: 4
Using execv...
.:
total 20
-rwxrwxrwx 1 deku deku 16344 Sep  7 16:02 Q27
-rwxrwxrwx 1 deku deku  1559 Sep  7 16:01 Q27.c
*/