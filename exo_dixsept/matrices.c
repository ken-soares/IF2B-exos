#include <stdio.h>
#include <stdlib.h>

int det2x2(int matrice[2][2]){
    return (matrice[0][0]*matrice[1][1])-(matrice[0][1]*matrice[1][0]);
}

void m_v(int n, int matrice[n][n], int vecteur[n]){
    int resultat[n];

    for(int i = 0; i < n; i++){
        resultat[i] = 0;
        for(int j = 0; j < n;j++){
            resultat[i] += vecteur[j] * matrice[i][j];
        }
    }
    for(int i = 0; i < 2; i++){
        printf("|%d|\n", resultat[i]);
    }
}

int main(void){

    int vec_test[2] = {8,7};
    int mat_2x2[2][2] = {{1,5},
                         {4,2}};

    printf("%d\n", det2x2(mat_2x2));

    m_v(2, mat_2x2, vec_test);


    return 0;
}
