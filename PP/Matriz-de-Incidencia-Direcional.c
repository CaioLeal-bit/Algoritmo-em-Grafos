//MATRIZ DE INCIDÊNCIA DIRECIONAL
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vertices, arestas;
    printf("Digite o número de vértices: ");
    scanf("%d", &vertices);
    printf("Digite o número de arestas: ");
    scanf("%d", &arestas);

    int matriz[vertices][arestas];

    // Inicializar com 0
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < arestas; j++){
            matriz[i][j] = 0;
        }
    }

    // Ler as arestas
    for(int j = 0; j < arestas; j++){
        int origem, destino;
        printf("Digite a Origem e o Destino da Aresta %d: ", j+1);
        scanf("%d %d", &origem, &destino);

        // Ajuste para índices baseados em 0
        origem--;
        destino--;

        matriz[origem][j] = 1;   // origem da aresta
        matriz[destino][j] = -1; // destino da aresta
    }

    // Mostrar a matriz
    printf("\nMatriz de Incidência:\n    ");
    for (int j = 0; j < arestas; j++) {
        printf("A%d ", j+1);
    }

    printf("\n  ");
    for (int j = 0; j < arestas; j++) {
        printf("---");
    }

    for (int i = 0; i < vertices; i++) {
        printf("\nV%d | ", i+1);
        for (int j = 0; j < arestas; j++) {
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n\n");

    // Grau de Entrada
    for (int i = 0; i < vertices; i++) {
        int grauEntrada = 0;
        for (int j = 0; j < arestas; j++) {
            if (matriz[i][j] == -1) {
                grauEntrada++;
            }
        }
        printf("Grau de entrada do vértice %d: %d\n", i+1, grauEntrada);
    }

    printf("\n");

    // Grau de Saída
    for (int i = 0; i < vertices; i++) {
        int grauSaida = 0;
        for (int j = 0; j < arestas; j++) {
            if (matriz[i][j] == 1) {
                grauSaida++;
            }
        }
        printf("Grau de saída do vértice %d: %d\n", i+1, grauSaida);
    }

    //Transformação de matriz de Incidência para Matriz de Adjacência
    int matrizAdj[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrizAdj[i][j] = 0;
        }
    }

    for (int j = 0; j < arestas; j++) {
        int origem = -1, destino = -1;
        for (int i = 0; i < vertices; i++) {
            if (matriz[i][j] == 1) {
                origem = i;
            }
            if (matriz[i][j] == -1) {
                destino = i;
            }
        }
        if (origem != -1 && destino != -1) {
            matrizAdj[origem][destino] = 1;
        }
    }

    // Mostrar a matriz de adjacência
    printf("\nMatriz de Adjacência:\n    ");
    for (int j = 0; j < vertices; j++) {
        printf("V%d ", j+1);
    }

    printf("\n  ");
    for (int j = 0; j < vertices; j++) {
        printf("---");
    }

    for (int i = 0; i < vertices; i++) {
        printf("\nV%d | ", i+1);
        for (int j = 0; j < vertices; j++) {
            printf("%2d ", matrizAdj[i][j]);
        }
    }

    printf("\n\n");

    //Tranformar matriz de Adjacência para lista
    printf("\nLista de Adjacência:\n");
    for (int i = 0; i < vertices; i++) {
        printf("V%d ", i+1);
        for (int j = 0; j < vertices; j++) {
            if (matrizAdj[i][j] == 1) {
                printf("-> V%d", j+1);
            }
        }
        printf("\n");
    }

    return 0;
}
