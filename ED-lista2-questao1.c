/*
** Função : Lista encadeada
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de um livro
typedef struct livro {
    char autor[100];
    char titulo[100];
    char editora[100];
    int ano;
    struct livro *prox;
} Livro;

// Função para criar um novo livro
Livro *criarLivro(char autor[], char titulo[], char editora[], int ano) {
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    if (novoLivro != NULL) {
        strcpy(novoLivro->autor, autor);
        strcpy(novoLivro->titulo, titulo);
        strcpy(novoLivro->editora, editora);
        novoLivro->ano = ano;
        novoLivro->prox = NULL;
    }
    return novoLivro;
}

// Função para inserir um livro de forma ordenada na lista
void inserirLivroOrdenado(Livro **lista, Livro *novoLivro) {
    Livro *atual = *lista;
    Livro *anterior = NULL;

    while (atual != NULL && strcmp(atual->titulo, novoLivro->titulo) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novoLivro->prox = *lista;
        *lista = novoLivro;
    } else {
        anterior->prox = novoLivro;
        novoLivro->prox = atual;
    }
}

// Função para remover um livro da lista
void removerLivro(Livro **lista, char titulo[]) {
    Livro *atual = *lista;
    Livro *anterior = NULL;

    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            *lista = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    }
}

// Função para buscar um livro pelo título
Livro *buscarLivroPorTitulo(Livro *lista, char titulo[]) {
    Livro *atual = lista;

    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        atual = atual->prox;
    }

    return atual;
}

// Função para buscar livros pelo autor
void buscarLivrosPorAutor(Livro *lista, char autor[]) {
    Livro *atual = lista;
    int encontrou = 0;

    while (atual != NULL) {
        if (strcmp(atual->autor, autor) == 0) {
            printf("Autor: %s, Titulo: %s, Editora: %s, Ano: %d\n", atual->autor, atual->titulo, atual->editora, atual->ano);
            encontrou = 1;
        }
        atual = atual->prox;
    }

    if (!encontrou) {
        printf("Nenhum livro encontrado para o autor %s.\n", autor);
    }
}

// Função para liberar a memória alocada para a lista de livros
void liberarLista(Livro *lista) {
    Livro *atual = lista;
    Livro *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n===== MENU =====\n");
    printf("1 - Inserir livro\n");
    printf("2 - Remover livro\n");
    printf("3 - Buscar livro por titulo\n");
    printf("4 - Buscar livros por autor\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Livro *biblioteca = NULL;
    int opcao;
    char autor[100], titulo[100], editora[100];
    int ano;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]", autor);
                printf("Digite o titulo do livro: ");
                scanf(" %[^\n]", titulo);
                printf("Digite a editora do livro: ");
                scanf(" %[^\n]", editora);
                printf("Digite o ano de edicao do livro: ");
                scanf("%d", &ano);

                inserirLivroOrdenado(&biblioteca, criarLivro(autor, titulo, editora, ano));
                break;
            case 2:
                printf("Digite o titulo do livro a ser removido: ");
                scanf(" %[^\n]", titulo);
                removerLivro(&biblioteca, titulo);
                break;
            case 3:
                printf("Digite o titulo do livro a ser buscado: ");
                scanf(" %[^\n]", titulo);
                Livro *livroEncontrado = buscarLivroPorTitulo(biblioteca, titulo);
                if (livroEncontrado != NULL) {
                    printf("Autor: %s, Titulo: %s, Editora: %s, Ano: %d\n", livroEncontrado->autor, livroEncontrado->titulo, livroEncontrado->editora, livroEncontrado->ano);
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;
            case 4:
                printf("Digite o autor dos livros a serem buscados: ");
                scanf(" %[^\n]", autor);
                buscarLivrosPorAutor(biblioteca, autor);
                break;
            case 5:
                liberarLista(biblioteca);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
