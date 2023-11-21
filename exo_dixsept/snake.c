#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_JEU 20

/* DECLARATION DE STRUCTURES */
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int x;
    int y;
} Fruit;

typedef struct {
    int taille;
    int dx;
    int dy;
    Position tete;
} Serpent;

/* DECLARATION DE FONCTION */

void pos_s(char t[TAILLE_JEU][TAILLE_JEU], Serpent *s){
    t[s->tete.x][s->tete.y] = 'H';
}

void remplir_t(char t[TAILLE_JEU][TAILLE_JEU]){
    for(int i = 0; i < TAILLE_JEU; i++){
        for(int j = 0; j < TAILLE_JEU; j++){
            t[i][j] = '.';
        }
    }
}

void pos_cible(char t[TAILLE_JEU][TAILLE_JEU], Fruit *f){
    int x = rand() % 8;
    int y = rand() % 8;
    f->x = x;
    f->y = y;

    t[x][y] = 'x';
}

void afficher_t(char t[TAILLE_JEU][TAILLE_JEU]){
    for(int i = 0; i < TAILLE_JEU; i++){
        for(int j = 0; j < TAILLE_JEU; j++){
            if(j == 0) printf("| %c ",t[i][j]);
            else if(j == TAILLE_JEU - 1) printf(" %c |\n", t[i][j]);
            else printf(" %c ", t[i][j]);
        }
    }
}


int main(int argc, char **argv){
    
    char t[TAILLE_JEU][TAILLE_JEU];

    Serpent s = {
        1,
        1,
        1,
        {10,10},
    };

    Fruit f;

    /* APPEL DES FONCTIONS */
    srand(time(0));

    remplir_t(t);
    pos_cible(t, &f);
    pos_s(t, &s);
    afficher_t(t);

    return 0;
}
