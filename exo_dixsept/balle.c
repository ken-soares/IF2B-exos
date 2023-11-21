#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} balle;

void placer_balle(int tableau[8][8], balle *b){
    int x = rand() % 8;
    int y = rand() % 8;
    b->x = x;
    b->y = y;
    tableau[x][y] = 'o';

}

void affichage(int tableau[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(j == 0) { printf("| %c ", tableau[i][j]);}
            else if(j == 7) {printf(" %c |\n", tableau[i][j]);}
            else { printf(" %c ", tableau[i][j]);}
        }
    }
}

void remp_init(int tableau[8][8]){
    srand(time(0));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tableau[i][j] = 'x';
        }
    }
}

void deplacer(int tableau[8][8], balle *b){
    if(b->x+b->dx > 7 || b->x+b->dx < 0) b->dx = -b->dx;
    if(b->y+b->dy > 7 || b->y+b->dy < 0) b->dy = -b->dy;

    tableau[b->x][b->y] = 'x';

    tableau[b->x+b->dx]
           [b->y+b->dy] = 'o';

    b->x = b->x+b->dx;
    b->y = b->y+b->dy;
}
int main(void){
    char entree[100];
    int tableau[8][8];
    balle b;
    b.dx = 1;
    b.dy = 1;

    remp_init(tableau);
    placer_balle(tableau, &b);

    while(1){
        deplacer(tableau, &b);
        affichage(tableau);
        printf("dx_b: %d, dy_b: %d\n", b.dx, b.dy);
        fflush(stdin);
        fgetc(stdin);
    }

    return 0;
}
