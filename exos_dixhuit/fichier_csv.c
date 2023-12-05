#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *f = fopen("test.csv", "r");

    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buffer = (char*)malloc(filesize+1);
    fread(buffer, filesize, 1, f);

    char *ptr = strtok(buffer, "\n");
    
    while(ptr != NULL){
        printf("%s\n", ptr);
        ptr = strtok(NULL, "\n");
    }

    return 0;
}
