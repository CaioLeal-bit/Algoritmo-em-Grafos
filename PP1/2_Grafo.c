//Ler uma matriz de tamanho x e de adjacência de um grafo não direcionado, fazendo as validações necessárias para a entrada e mostre uma lista dos vértices com seu respectivo grau.
//MONTAGEM DO TRIÂNGULO DE CIMA DA MATRIZ
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho, i, j; //tamanho da matriz
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho);

    int matriz[tamanho][tamanho];
    int grau[tamanho];

    //Montagem da Matriz
    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if (i == j) {
                matriz[i][j] = 0; // Diagonal principal deve ser 0
            } else if(i < j) {
                printf("Digite o valor para a posicao [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                matriz[j][i] = matriz[i][j]; // Preencher simetricamente
            } 
        }
    }

    //Mostrar a matriz
    printf("\nMatriz de adjacência:\n    ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", i+1);
    }

    printf("\n  ");

    for (i = 0; i < tamanho; i++) {
        printf("---");
    }

    for (i = 0; i < tamanho; i++) {
        printf("\n%d | ",i+1);
        for (j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
    }

    //Verificação de Simetria
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(matriz[i][j] != matriz[j][i]){
                printf("\n\nA matriz não é simétrica.\n");
                return 1;
                
            }
        }
    }

    printf("\n");

    //Cálculo do Grau dos Vértices:
    for(int i = 0; i< tamanho; i++){
        grau[i] = 0;
        for(int j = 0; j < tamanho; j++){
            grau[i] += matriz[i][j];
        }
    }

    printf("\n");

    //Lista de Graus e Vértices
    printf("Lista de Vértices e seus Graus:\n");
    for(int i = 0; i < tamanho; i++){
        printf("Vértice %d: Grau %d\n", i, grau[i]);
    }

    printf("\n");

    return 0;
}

