#include <stdio.h>
#include <stdlib.h>

int* buscaNoVetor(int* v, int n, int valor, int* maior, int* qtd) {
    int contagem = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            contagem++;
        }
    }

    *qtd = contagem;

    if (contagem == 0) {
        return NULL;
    }

    int* indices = (int*) malloc(contagem * sizeof(int));
    int indiceAtual = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[indiceAtual] = i;
            indiceAtual++;
        }
    }

    return indices;
}

int main() {
    int n;
    scanf("%d", &n);

    int* v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int valorBusca;
    scanf("%d", &valorBusca);

    int quantidadeOcorrencias = 0;
    int maiorValorIgnorado = 0; 
    
    int* indicesEncontrados = buscaNoVetor(v, n, valorBusca, &maiorValorIgnorado, &quantidadeOcorrencias);

    if (indicesEncontrados == NULL) {
        printf("Nenhuma ocorrencia\n");
    } else {
        printf("%d\n", quantidadeOcorrencias);
        for (int i = 0; i < quantidadeOcorrencias; i++) {
            printf("%d ", indicesEncontrados[i]);
        }
        printf("\n");
    }

    free(v);
    free(indicesEncontrados);

    return 0;
}
