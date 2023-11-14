#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char code[5];
    int prix;
    int qt;
} fleur;


int verif_code(char code[5], char l_codes[3][5]){
    for(int i = 0; i < 3; i++){
        if(strncmp(code, l_codes[i],5) == 0){
            return 1;
        }
    }
    return 0;
}

int main(void){
    char l_codes[3][5] = {"tulip", "roses", "pisen"};
    int n = 0;

    printf("entrer un n: ");
    scanf("%d", &n);
    
    fleur *f = malloc(sizeof(fleur) * n);

    for(int i = 0; i < n; i++){
        fleur fa;
        char code[5];
        printf("entrer un code: ");
        scanf("%s", (char*)&code);
        if(verif_code(code, l_codes) == 1){
            strcpy(fa.code, code);
        }else{
            puts("erreur de code");
            exit(1);
        }

        printf("entrer une qt: ");
        scanf("%d", &fa.qt);

        fa.prix = (i+2)*3; // formule arbitraire pour le prix pour éviter d'avoir a assigner un prix a chaque item de base
       
        f[i] = fa;
    }


    int total_ht = 0;
    puts("\n\n---FACTURE---"); // sans libellés parce que c'est useless, le code est assez descriptif
    for(int i = 0; i < n; i++){
        total_ht += f[i].prix * f[i].qt;
        printf("code: %s, qt: %d, prix unitaire: %d sous total: %d\n", f[i].code, f[i].qt, f[i].prix, f[i].prix * f[i].qt);
    }

    float total_ttc = (float)total_ht * 0.2 + (float)total_ht; // +20% sur tout le panier hahahahaha quelle taxe méchante

    printf("------------\n");
    printf("TOTAL HT: %d€\n", total_ht);
    printf("TOTAL TTC: %.2f€\n", total_ttc);
    return 0;
}
