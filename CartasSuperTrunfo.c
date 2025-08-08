#include <stdio.h>

int main() {
    // Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidadePopulacional1, pibPerCapita1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidadePopulacional2, pibPerCapita2;

    // Leitura dos dados da Carta 1
    printf("Digite o estado da Carta 1: \n");
    scanf(" %c", &estado1);

    printf("Digite o código da Carta 1: \n");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade da Carta 1: \n");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a população da Carta 1: \n");
    scanf("%d", &populacao1);

    printf("Digite a área da Carta 1 (em km²): \n");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhões de reais): \n");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da Carta 1: \n");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da Carta 2
    printf("\nDigite o estado da Carta 2: \n");
    scanf(" %c", &estado2);

    printf("Digite o código da Carta 2: \n");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade da Carta 2: \n");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a população da Carta 2: \n");
    scanf("%d", &populacao2);

    printf("Digite a área da Carta 2 (em km²): \n");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhões de reais): \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da Carta 2: \n");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1; // PIB convertido para reais

    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2; // PIB convertido para reais

    // Exibição dos resultados
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}
