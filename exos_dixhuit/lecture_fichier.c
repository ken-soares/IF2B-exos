#include <stdio.h>
#include <stdlib.h>

int main(void){

    char c[1000];
    FILE *p;

    if((p = fopen("test.txt", "r")) == NULL){
        printf("file cannot be opened\n");
        exit(1);
    }

    fscanf(p, "%[^\n]", c);
    printf("data: %s\n", c);

    fclose(p);
    return 0;
}
