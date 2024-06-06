/*
** Função : simular lista de compras
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar um item da lista de compras
typedef struct Item {
    char nome[50];
    int quantidade;
    struct Item* proximo;
} Item;

// Função para criar um novo item da lista de compras
Item* criarItem(char nome[], int quantidade) {
    Item* novoItem = (Item*)malloc(sizeof(Item));
    if (novoItem != NULL) {
        strcpy(novoItem->nome, nome);
        novoItem->quantidade = quantidade;
        novoItem->proximo = NULL;
    }
    return novoItem;
}

// Função para inserir um item na lista de compras
void inserirItem(Item** lista, char nome[], int quantidade) {
    Item* novoItem = criarItem(nome, quantidade);
    if (novoItem == NULL) {
        printf("Erro: nao foi possivel criar o item.\n");
        return;
    }
    novoItem->proximo = *lista;
    *lista = novoItem;
    printf("Item '%s' inserido na lista de compras.\n", nome);
}

// Função para remover um item da lista de compras
void removerItem(Item** lista, char nome[]) {
    Item* atual = *lista;
    Item* anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("Item '%s' nao encontrado na lista de compras.\n", nome);
        return;
    }
    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    printf("Item '%s' removido da lista de compras.\n", nome);
}

// Função para consultar um item na lista de compras
void consultarItem(Item* lista, char nome[]) {
    Item* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Item '%s' encontrado na lista de compras. Quantidade: %d\n", nome, atual->quantidade);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item '%s' nao encontrado na lista de compras.\n", nome);
}

// Função para mostrar todos os itens da lista de compras
void mostrarLista(Item* lista) {
    if (lista == NULL) {
        printf("Lista de compras vazia.\n");
        return;
    }
    printf("Lista de compras:\n");
    Item* atual = lista;
    while (atual != NULL) {
        printf(" - %s (Quantidade: %d)\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

// Função para liberar a memória alocada para a lista de compras
void liberarLista(Item** lista) {
    Item* atual = *lista;
    Item* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
    printf("Memoria liberada.\n");
}

int main() {
    Item* lista = NULL;
    int opcao, quantidade;
    char nome[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Consultar item\n");
        printf("4 - Mostrar lista de compras\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                scanf(" %[^\n]", nome);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                inserirItem(&lista, nome, quantidade);
                break;
            case 2:
                printf("Digite o nome do item a ser removido: ");
                scanf(" %[^\n]", nome);
                removerItem(&lista, nome);
                break;
            case 3:
                printf("Digite o nome do item a ser consultado: ");
                scanf(" %[^\n]", nome);
                consultarItem(lista, nome);
                break;
            case 4:
                mostrarLista(lista);
                break;
            case 5:
                liberarLista(&lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
