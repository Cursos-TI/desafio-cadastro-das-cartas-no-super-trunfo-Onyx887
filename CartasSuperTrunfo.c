#include <stdio.h>

int main() {
    // -----------------------------
    // Movimento da Torre (FOR LOOP)
    // -----------------------------
    int i;
    int casasTorre = 5; // número de casas a mover
    printf("Movimento da Torre:\n");
    for (i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // -----------------------------
    // Movimento do Bispo (WHILE LOOP)
    // -----------------------------
    int j = 1;
    int casasBispo = 5; // número de casas a mover
    printf("\nMovimento do Bispo:\n");
    while (j <= casasBispo) {
        printf("Cima Direita\n");
        j++;
    }

    // -----------------------------
    // Movimento da Rainha (DO-WHILE LOOP)
    // -----------------------------
    int k = 1;
    int casasRainha = 8; // número de casas a mover
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= casasRainha);

    return 0;
}
