#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // populacao / area
} Carta;

int main() {
    // Cadastro de exemplo
    Carta carta1 = {"Brasil", 210000000, 8515767, 2200000, 30, 0};
    Carta carta2 = {"Argentina", 45000000, 2780400, 500000, 15, 0};

    // Calcular densidade demográfica
    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    int escolha1, escolha2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    // Primeiro menu
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    scanf("%d", &escolha1);

    // Segundo menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == escolha1) continue; // Não repete a opção já escolhida
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    scanf("%d", &escolha2);

    // Garantir que não sejam iguais
    if (escolha1 == escolha2) {
        printf("Erro: não é permitido escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    // Função auxiliar inline para pegar valores
    #define GET_VALOR(carta, opcao) ((opcao==1)?carta.populacao: \
                                    (opcao==2)?carta.area: \
                                    (opcao==3)?carta.pib: \
                                    (opcao==4)?carta.pontosTuristicos: \
                                               carta.densidadeDemografica)

    // Valores para os dois atributos
    valor1_c1 = GET_VALOR(carta1, escolha1);
    valor1_c2 = GET_VALOR(carta2, escolha1);
    valor2_c1 = GET_VALOR(carta1, escolha2);
    valor2_c2 = GET_VALOR(carta2, escolha2);

    // Exibição inicial
    printf("\n--- Comparação de Cartas ---\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Comparação atributo 1
    printf("Atributo 1: ");
    switch (escolha1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    // Comparação atributo 2
    printf("Atributo 2: ");
    switch (escolha2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // Soma final
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n\n", carta1.nome, soma1, carta2.nome, soma2);

    // Regra de comparação: densidade vence o menor, resto vence o maior
    float pontos1 = 0, pontos2 = 0;

    if (escolha1 == 5) { // Densidade
        if (valor1_c1 < valor1_c2) pontos1++;
        else if (valor2_c1 < valor2_c2) pontos2++;
    } else {
        if (valor1_c1 > valor1_c2) pontos1++;
        else if (valor1_c2 > valor1_c1) pontos2++;
    }

    if (escolha2 == 5) { // Densidade
        if (valor2_c1 < valor2_c2) pontos1++;
        else if (valor2_c2 < valor2_c1) pontos2++;
    } else {
        if (valor2_c1 > valor2_c2) pontos1++;
        else if (valor2_c2 > valor2_c1) pontos2++;
    }

    // Resultado final
    printf("Resultado: ");
    if (soma1 > soma2) printf("%s venceu!\n", carta1.nome);
    else if (soma2 > soma1) printf("%s venceu!\n", carta2.nome);
    else printf("Empate!\n");

    return 0;
}
