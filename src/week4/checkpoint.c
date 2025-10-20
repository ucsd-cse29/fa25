#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc < 2) { 
        printf("Needs at least one argument\n"); 
        return 1; //error
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)  {

        char *match = strstr(buffer, argv[1]);
        if(match != NULL) { // if we found argv[1] in the input line
            printf("%s", buffer);
        }
    }

    return 0; //success!
}
