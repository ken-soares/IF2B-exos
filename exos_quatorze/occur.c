#include <stdio.h>
#include <stdlib.h>

int maxim(int *occurences){
    int m = 0;
    for(int i = 0; i < 26; i++){
        if(occurences[i] > m)
            m = occurences[i];
    }

    return m;
}

int dernier_libre(char* lettres){
    for(int i = 0; i < 26; i++){
        if(lettres[i] == '-')
            return i;
    }
    return 0;
}

void entrer_mot(char *chaine, int t_mot){
    printf("entrer un mot:");
    fgets(chaine,t_mot+1, stdin);
    
    for(int i = 0; i < t_mot;i++){
        chaine[i] -= 32;
    }
}

void remplir_lettres(char* lettres){
    for(int i = 0; i < 26; i++){
        lettres[i] = '-';
    }
}

int est_present(char lettre, char *lettres){
    for(int i = 0; i < 26; i++){
        if(lettres[i] == lettre){
            return i;
        }
    }

    return 0;
}

int main(void){

    // on groupe chaque lettre et son nombre d'occurences
    char lettres[26];
    int occurences[26];

    remplir_lettres(lettres);

    int nb_mot = 0;
    printf("nombre de mots");
    scanf("%d", &nb_mot);


    for(int i = 0; i < nb_mot;i++){
        int t_mot = 0;

        printf("entrer la taille de votre mot");

        scanf("%d", &t_mot);
        scanf("%c", (char *) stdin);

        if(t_mot < 6) exit(1);

        char* chaine = (char*)malloc(t_mot * sizeof(char));

        entrer_mot(chaine, t_mot);

        for(int i = 0; i < t_mot; i++){
            int rang = est_present(chaine[i], lettres);
            if(rang != 0){
                occurences[rang]++;
            }else{
                int dl = dernier_libre(lettres);
                lettres[dl] = chaine[i];
                occurences[dl] = 1;
            }
        }

        free(chaine);
    }

    for(int i = 0; i < 26; i ++){
        if(lettres[i] != '-'){
            if(occurences[i] == maxim(occurences)){
                printf("%c:%d\n",lettres[i],occurences[i]);
            }
        }
    }


    return 0;
}
