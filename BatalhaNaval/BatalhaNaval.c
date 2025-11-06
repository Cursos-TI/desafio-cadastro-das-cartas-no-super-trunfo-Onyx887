#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10
#define TAM_HAB 5  // tamanho da matriz de habilidade

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;

    printf("\n     === TABULEIRO BATALHA NAVAL ===\n\n");

    // Cabeçalho de colunas (A–J)
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");
    printf("   -----------------------------------------\n");

    // Linhas numeradas (1–10)
    for (i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~ "); // Água
            else if (tabuleiro[i][j] == 3)
                printf(" N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" * "); // Área de habilidade
        }
        printf("\n");
    }

    printf("\nLegenda: ~ = água | N = navio | * = habilidade\n");
}

// Função para posicionar navios fixos
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio 1 - horizontal
    for (int j = 2; j < 5; j++)
        tabuleiro[2][j] = 3;

    // Navio 2 - vertical
    for (int i = 5; i < 8; i++)
        tabuleiro[i][6] = 3;

    // Navio 3 - diagonal principal
    for (int i = 0; i < 3; i++)
        tabuleiro[7 + i][i] = 3;

    // Navio 4 - diagonal secundária
    for (int i = 0; i < 3; i++)
        tabuleiro[i][9 - i] = 3;
}

// Gera matriz de habilidade CONE
void gerarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            // Forma de cone: começa estreito e abre para baixo
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade CRUZ
void gerarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Gera matriz de habilidade OCTAEDRO (losango)
void gerarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    int i, j;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Sobrepõe habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int i, j;
    int offset = TAM_HAB / 2;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + (i - offset);
            int coluna = origemColuna + (j - offset);

            // Verifica se está dentro do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5; // marca habilidade
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona navios
    posicionarNavios(tabuleiro);

    // Matrizes de habilidade
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades em diferentes locais
    aplicarHabilidade(tabuleiro, cone, 1, 1);      // cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // octaedro no canto inferior direito

    // Exibe resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
