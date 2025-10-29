#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro 10x10

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (representando água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Exibe o tabuleiro formatado com letras (A–J) e números (1–10)
    printf("\n     === TABULEIRO BATALHA NAVAL ===\n\n");

    // Cabeçalho das colunas (A–J)
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Linha de separação
    printf("   -----------------------------------------\n");

    // Linhas numeradas (1–10)
    for (i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);  // número da linha

        for (j = 0; j < TAM; j++) {
            printf(" ~ ");  // representa água
        }
        printf("\n");
    }

    printf("\nLegenda: ~ = água\n");

    return 0;
}
