#include <stdio.h>

// --------------------------------------------------------
// Função recursiva para movimentar a Torre
// A Torre move-se apenas em linha reta (ex: 5 casas à direita)
// --------------------------------------------------------
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return; // caso base
    printf("Direita\n");
    moverTorre(casasRestantes - 1); // chamada recursiva
}

// --------------------------------------------------------
// Função recursiva para movimentar o Bispo
// O Bispo move-se na diagonal (ex: 5 casas "Cima Direita")
// Aqui usamos recursividade + loops aninhados para simular
// o deslocamento vertical e horizontal ao mesmo tempo
// --------------------------------------------------------
void moverBispo(int casasRestantes) {
    if (casasRestantes == 0) return; // caso base

    // Loop externo: movimento vertical
    for (int v = 1; v <= 1; v++) {
        // Loop interno: movimento horizontal
        for (int h = 1; h <= 1; h++) {
            printf("Cima Direita\n");
        }
    }

    moverBispo(casasRestantes - 1); // chamada recursiva
}

// --------------------------------------------------------
// Função recursiva para movimentar a Rainha
// A Rainha move-se em todas as direções — simularemos 8 casas à esquerda
// --------------------------------------------------------
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return; // caso base
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1); // chamada recursiva
}

// --------------------------------------------------------
// Movimento do Cavalo
// Agora: 2 casas para cima e 1 para a direita
// Usando loops aninhados com múltiplas variáveis e controle de fluxo
// --------------------------------------------------------
void moverCavalo() {
    int i, j;
    int casasCima = 2;
    int casasDireita = 1;

    printf("Movimento do Cavalo:\n");

    // Loop externo: movimento vertical (duas casas para cima)
    for (i = 1; i <= casasCima; i++) {
        if (i == 2) {
            printf("Cima (preparando movimento em L)\n");
        } else {
            printf("Cima\n");
        }

        // Loop interno: controla o movimento horizontal
        for (j = 1; j <= casasDireita; j++) {
            if (i < casasCima) {
                // ainda não chegou no fim do L, ignora o movimento horizontal
                continue;
            }

            // se chegou à última casa vertical, move à direita
            if (j == 1) {
                printf("Direita\n");
                break; // encerra o loop interno após a casa à direita
            }
        }
    }
}

// --------------------------------------------------------
// Função principal
// --------------------------------------------------------
int main() {
    // -----------------------------
    // Torre (Recursividade)
    // -----------------------------
    printf("Movimento da Torre:\n");
    moverTorre(5); // 5 casas à direita

    // -----------------------------
    // Bispo (Recursividade + Loops Aninhados)
    // -----------------------------
    printf("\nMovimento do Bispo:\n");
    moverBispo(5); // 5 casas em diagonal "Cima Direita"

    // -----------------------------
    // Rainha (Recursividade)
    // -----------------------------
    printf("\nMovimento da Rainha:\n");
    moverRainha(8); // 8 casas à esquerda

    // -----------------------------
    // Cavalo (Loops Aninhados + Controle de Fluxo)
    // -----------------------------
    printf("\n");
    moverCavalo(); // movimento em L (2 cima, 1 direita)

    return 0;
}
