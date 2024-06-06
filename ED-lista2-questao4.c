/*
** Função : classificação por seleção
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void gerarVetorAleatorio(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // gerar números aleatórios entre 0 e 99
    }
}

void selectionSort(int vetor[], int tamanho) {
    int indiceMenor;
    for (int i = 0; i < tamanho - 1; i++) {
        indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[TAMANHO];

    gerarVetorAleatorio(vetor, TAMANHO);

    printf("Vetor original:\n");
    exibirVetor(vetor, TAMANHO);

    selectionSort(vetor, TAMANHO);

    printf("Vetor ordenado:\n");
    exibirVetor(vetor, TAMANHO);

    return 0;
}
