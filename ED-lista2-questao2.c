/*
** Função : Lista encadeada
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    float elementos[MAX_SIZE];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

int pilhaCheia(Pilha *pilha) {
    return (pilha->topo == MAX_SIZE - 1);
}

void push(Pilha *pilha, float elemento) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = elemento;
    printf("Elemento %.2f inserido na pilha\n", elemento);
}

float pop(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia\n");
        return 0;
    }
    float elemento = pilha->elementos[pilha->topo];
    pilha->topo--;
    return elemento;
}

void exibirPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Conteudo da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%.2f\n", pilha->elementos[i]);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    int opcao;
    float elemento;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elemento (push)\n");
        printf("2 - Remover elemento (pop)\n");
        printf("3 - Exibir pilha\n");
        printf("4 - Verificar se a pilha esta vazia\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido na pilha: ");
                scanf("%f", &elemento);
                push(&pilha, elemento);
                exibirPilha(&pilha);
                break;
            case 2:
                if (!pilhaVazia(&pilha)) {
                    elemento = pop(&pilha);
                    printf("Elemento %.2f removido da pilha\n", elemento);
                }
                exibirPilha(&pilha);
                break;
            case 3:
                exibirPilha(&pilha);
                break;
            case 4:
                if (pilhaVazia(&pilha)) {
                    printf("A pilha esta vazia\n");
                } else {
                    printf("A pilha nao esta vazia\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
