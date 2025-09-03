//Verifica se um grafo qualquer é um ciclo, uma roda ou um grafo completo e dizer se é euleriano ou não.

#include <stdio.h>

int verificarEuleriano(int n, int grafo[n][n]){
    //Verifica se é Euleriano em grafos completos(kn)
    if(n % 2 == 0){
        for(int i=0; i<n; i++){
            int grau = 0;
            for(int j=0; j<n; j++){
                grau += grafo[i][j];
            }
        if(grau % 2 != 0) return 0;
        }
    }
    return 1;
}


int verificarCiclo(int n, int grafo[n][n]){
    if(n<3) return 0;
    
    for(int i=0; i<n; i++){
        int grau = 0;
        for(int j=0; j<n;j++){
            grau+=grafo[i][j];
        }
        
        if(grau != 2) return 0;
    }
    
    return 1;
}

int verificarCompleto(int n, int grafo[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(i!=j && grafo[i][j] == 0) return 0;
            
            if(i == j && grafo[i][j] != 0) return 0;
        }
    }
    
    return 1;
}

int verificarRoda(int n, int grafo[n][n]){
    if(n<4) return 0;
    int centro = -1;
    
    for(int i=0; i<n; i++){
        int grau = 0;
        for(int j=0; j<n; j++){
            grau+=grafo[i][j];
        }
        if(grau==n-1){
            if(centro==-1) centro = i;
            else return 0;
        }
    }
    if(centro==-1) return 0;
    
    int m = n-1;
    int subgrafo[m][m];
    
    int k=0, l=0;
    for(int i=0; i<n;i++){
        if(i==centro) continue;
        l=0;
        for(int j=0;j<n; j++){
            if(j==centro) continue;
            subgrafo[k][l] = grafo[i][j];
            l++;
        }
        k++;
    }
    return verificarCiclo(m, subgrafo);
}

int main()
{
    int n;
    printf("Digite o numero de vertices: ");
    scanf("%d", &n);
    
    int grafo[n][n];
    printf("Digite a matriz adjacente (%dx%d):\n", n, n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &grafo[i][j]);
        }
    }
    
    if(verificarCompleto(n, grafo)) {
        printf("O grafo e completo!\n");
        if(verificarEuleriano(n, grafo)){
            printf("O grafo e Euleriano!\n");
        } else {
            printf("O grafo não é Euleriano!\n");
        }
    } else if(verificarCiclo(n, grafo)){
        printf("O grafo e um ciclo!\n");
        printf("O grafo é Euleriano!\n");
    } else if(verificarRoda(n, grafo)){
        printf("O grafo é uma roda!\n");
        printf("O grafo não é Euleriano!\n");
    } else {
        printf("O grafo não e nenhuma das opcoes\n");
    }

    
    return 0;
}