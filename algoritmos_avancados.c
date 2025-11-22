#include <stdio.h>

// -------------------------------
//  Estrutura da Árvore (Salas)
// -------------------------------

typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// Função para criar sala
Sala* criarSala(char nome[]) {
    Sala* nova = malloc(sizeof(Sala));
    int i = 0;
    while (nome[i] != '\0') {  // copiar string manualmente
        nova->nome[i] = nome[i];
        i++;
    }
    nova->nome[i] = '\0';
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// Conectar salas (esquerda e direita)
void conectarSalas(Sala *sala, Sala *esq, Sala *dir) {
    sala->esq = esq;
    sala->dir = dir;
}

// Explorar salas
void explorarSalas(Sala *atual) {
    char opcao;

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Escolha para onde ir:\n");
        printf("  (e) Ir para a esquerda\n");
        printf("  (d) Ir para a direita\n");
        printf("  (s) Sair da mansão\n");
        printf("➤ ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\nVocê decidiu sair da mansão...\n");
            return;
        }
        else if (opcao == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("Não há sala à esquerda!\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("Não há sala à direita!\n");
            }
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária

    // Criando as salas fixas
    Sala *hall    = criarSala("Hall de Entrada");
    Sala *biblio  = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *salao   = criarSala("Salão de Baile");
    Sala *sotao   = criarSala("Sótão");
    Sala *jardim  = criarSala("Jardim Interno");

    // Conectando (formando a árvore)
    conectarSalas(hall, biblio, cozinha);
    conectarSalas(biblio, salao, sotao);
    conectarSalas(cozinha, NULL, jardim);

    // Começar jogo
    explorarSalas(hall);

    return 0;
}
