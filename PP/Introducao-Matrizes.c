//Ler uma matriz 8x8 com valores aleatórios e imprimir com identificação de linhas e colunas:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int matriz[8][8];
    int i; //linha
    int j; //coluna

    srand(time(NULL));
    
    printf("\n MATRIZ 8X8 \n");

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    printf("    ");
    for(j=0; j<8; j++){
        printf(" %2d", j);
    }

    printf("\n");

    printf("     ");
    for(int i=0; i<8; i++){
        printf("---");
    }
    printf("\n");

    for(int i=0; i<8; i++){
        printf(" %2d | ", i);
        for(int j=0; j<8; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}