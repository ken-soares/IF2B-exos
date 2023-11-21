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
    int hit;
} Fruit;

typedef struct {
    int taille;
    int dx;
    int dy;
    Position tete;
} Serpent;

/* DECLARATION DE FONCTION */

void verif_depl(char depl, Serpent *s){
    switch(depl){
        case 'w':
            s->dy = -1;
            s->dx = 0;
            break;
        case 's':
            s->dy = 1;
            s->dx = 0;
            break;
        case 'a':
            s->dx = -1;
            s->dy = 0;
            break;
        case 'd':
            s->dx = 1;
            s->dy = 0;
            break;
        default:
            break;
    }
}

void depl_s(char t[TAILLE_JEU][TAILLE_JEU], Serpent *s){
    if(s->tete.x + s->dx >= TAILLE_JEU || s->tete.x + s->dx < 0){
        exit(1);
    }else if(s->tete.y + s->dy >= TAILLE_JEU || s->tete.y + s->dy < 0){
        exit(1);
    }else{
        printf("%d %d\n", s->dy, s->dx);
        s->tete.x += s->dx;
        s->tete.y += s->dy;
    }
}

void pos_s(char t[TAILLE_JEU][TAILLE_JEU], Serpent *s){
    printf("pos_s: %d %d\n", s->tete.y, s->tete.x);
    t[s->tete.y][s->tete.x] = 'H';
}

void remplir_t(char t[TAILLE_JEU][TAILLE_JEU]){
    for(int i = 0; i < TAILLE_JEU; i++){
        for(int j = 0; j < TAILLE_JEU; j++){
            t[i][j] = '.';
        }
    }
}

void pos_cible(char t[TAILLE_JEU][TAILLE_JEU], Fruit *f){
    if(f->hit == 1){
        int x = rand() % 20;
        int y = rand() % 20;
        f->x = x;
        f->y = y;
    }

    t[f->y][f->x] = 'x';

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
    char deplacement;

    Serpent s = {
        1,
        0,
        0,
        {10,10},
    };

    Fruit f;
    f.hit = 1;
    pos_cible(t, &f);
    f.hit = 0;

    /* APPEL DES FONCTIONS */
    srand(time(0));


    while(1){
        remplir_t(t);
        pos_cible(t, &f);

        pos_s(t, &s);
        afficher_t(t);
        scanf("%c", &deplacement);
        verif_depl(deplacement, &s);
        depl_s(t, &s);

        
    }

    return 0;
}
