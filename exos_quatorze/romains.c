#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int valeur_romain(char chiffre){
    switch(chiffre){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            exit(1);
    }
}

int main(){
    int taille;
    printf("entrer une taille de nombre romain");
    scanf("%d", &taille);
    scanf("%c", (char*)stdin);

    printf("entrer un nombre romain");
    char* nombre = (char*)malloc(sizeof(char)*taille);
    fgets(nombre,taille+1,stdin);

    for(int i = 0; i < taille; i++){
        toupper(nombre[i]);
    }

    printf("%s\n", nombre);

    int total = 0;

    for(int i = 0; i < taille; i++){

        if(i+1 < taille){
            if(valeur_romain(nombre[i]) < valeur_romain(nombre[i+1])){
                total -= valeur_romain(nombre[i]);
            }
            else{
                total += valeur_romain(nombre[i]);
            }
        }else{
            total += valeur_romain(nombre[i]);
        }
    }

    printf("valeur chiffre:%d\n", total);
    
    return 0;
}
