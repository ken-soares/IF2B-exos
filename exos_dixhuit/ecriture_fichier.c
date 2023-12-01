#include <stdio.h>
#include <stdlib.h>


int main(void){
    int a;
    printf("taille du buffer:\n");
    scanf("%d", &a);

    char *buffer = malloc(sizeof(char)*a);


    printf("texte a bufferer:\n");
    scanf("%*[^\n]");
    scanf("%*c");
    fgets(buffer, a+1, stdin);

    FILE *p = fopen("test.txt", "w+");

    fprintf(p, "%s", buffer);

    fclose(p);

    system("cat test.txt");

    return 0;
}
