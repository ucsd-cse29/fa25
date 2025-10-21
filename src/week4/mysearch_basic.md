```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[1024];

    if(argc < 2) { 
        printf("Needs at least one argument\n"); 
        return 1; //error
    }

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)  {

        // Let's find pattern
        char *match = strstr(buffer, argv[1]);
        if(match != NULL) {
            printf("%s", buffer);
        }
    }

    return 0; //success!
}
```