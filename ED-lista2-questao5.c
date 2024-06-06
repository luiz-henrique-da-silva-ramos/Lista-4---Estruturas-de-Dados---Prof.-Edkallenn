/*
** Função :  gerenciar uma pilha de processos
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSOS 100
#define TAM_DESCRICAO 100

typedef struct {
    int id;
    char descricao[TAM_DESCRICAO];
} Processo;

typedef struct {
    Processo processos[MAX_PROCESSOS];
    int topo;
} PilhaProcessos;

void inicializarPilha(PilhaProcessos *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(PilhaProcessos *pilha) {
    return (pilha->topo == -1);
}

int pilhaCheia(PilhaProcessos *pilha) {
    return (pilha->topo == MAX_PROCESSOS - 1);
}

void push(PilhaProcessos *pilha, Processo processo) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    pilha->topo++;
    pilha->processos[pilha->topo] = processo;
    printf("Processo #%d - %s inserido na pilha\n", processo.id, processo.descricao);
}

Processo pop(PilhaProcessos *pilha) {
    Processo processoRemovido;
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia\n");
        processoRemovido.id = -1;
        strcpy(processoRemovido.descricao, "");
        return processoRemovido;
    }
    processoRemovido = pilha->processos[pilha->topo];
    pilha->topo--;
    printf("Processo #%d - %s removido da pilha\n", processoRemovido.id, processoRemovido.descricao);
    return processoRemovido;
}

void exibirPilha(PilhaProcessos *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Conteudo da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("Processo #%d - %s\n", pilha->processos[i].id, pilha->processos[i].descricao);
    }
}

int main() {
    PilhaProcessos pilha;
    inicializarPilha(&pilha);
    int opcao;
    Processo processo;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Incluir processo\n");
        printf("2 - Retirar processo\n");
        printf("3 - Encerrar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador do processo: ");
                scanf("%d", &processo.id);
                printf("Digite a descricao do processo: ");
                scanf(" %[^\n]", processo.descricao);
                push(&pilha, processo);
                exibirPilha(&pilha);
                break;
            case 2:
                processo = pop(&pilha);
                exibirPilha(&pilha);
                break;
            case 3:
                while (!pilhaVazia(&pilha)) {
                    processo = pop(&pilha);
                }
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
