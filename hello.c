#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1)
        printf("Hello, %s!\n", argv[1]);
    else
        printf("Hello, World!\n");
    return 0;
}


/*

deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ gcc hello.c
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ gcc Q26.c -o Q26
deku@Parva-Parmar:/media/deku/Data/Software systems/hands-on-1/Q26$ ./Q26
Now executing another program...
Hello, Parva!

*/