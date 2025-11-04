#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3  // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Coordenadas iniciais de cada navio
    // (Você pode alterar para testar posições diferentes)
    int linhaH = 1, colunaH = 2;  // Navio horizontal
    int linhaV = 4, colunaV = 7;  // Navio vertical
    int linhaD1 = 0, colunaD1 = 0; // Navio diagonal ↘
    int linhaD2 = 2, colunaD2 = 9; // Navio diagonal ↗

    // 3️⃣ Função de verificação simples de sobreposição
    // (aqui feita inline, sem função separada)
    int sobreposicao = 0;

    // 4️⃣ Posiciona navio horizontal
    if (colunaH + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 3) sobreposicao = 1;
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    // 5️⃣ Posiciona navio vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) sobreposicao = 1;
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // 6️⃣ Posiciona navio diagonal ↘ (linha e coluna aumentam)
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 3) sobreposicao = 1;
            tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        }
    }

    // 7️⃣ Posiciona navio diagonal ↗ (linha aumenta, coluna diminui)
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == 3) sobreposicao = 1;
            tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        }
    }

    // 8️⃣ Verifica se houve sobreposição
    if (sobreposicao) {
        printf("\nAviso: alguns navios se sobrepõem!\n");
    }

    // 9️⃣ Exibe o tabuleiro com letras (A–J) e números (1–10)
    printf("\n     === TABULEIRO BATALHA NAVAL ===\n\n");

    // Cabeçalho das colunas
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");
    printf("   -----------------------------------------\n");

    // Linhas numeradas
    for (i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 "); // Água
            else
                printf(" 3 "); // Parte do navio
        }
        printf("\n");
    }

    return 0;
}
