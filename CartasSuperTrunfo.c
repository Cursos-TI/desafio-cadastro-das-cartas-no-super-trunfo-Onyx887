#include <stdio.h>
int main(){

    printf("Carta1 \n");

    int Populacao = 15000000;
    char Estado['B']; 
    float Area = 3589000;
    float PIB = 87000000;
    int PontoTuristico = 50;

    printf("Digite a populacao: \n");
    scanf("%d", &Populacao);

    printf("Digite o estado: \n");
    scanf("%s", &Estado);

    printf("Digite a area em Km: \n");
    scanf("%f", &Area);

    printf("Digite o Pib per capita: \n");
    scanf("%f", &PIB);

    printf("Digite o ponto turistico: \n");
    scanf("%d", &PontoTuristico);

    printf("População: %d - Estado: %s\n", Populacao, Estado);
    printf("Area: %f - PIB: %f\n", Area, PIB);
    printf("Ponto Turístico %d\n", PontoTuristico);




    printf("Carta 2 \n");

    int POPULACAO = 5000;
    char ESTADO['R'];
    float AREA = 1536;
    float Pib = 891000;
    int PONTOTURISTICO = 70;

    printf("Digite a populacao: \n");
    scanf("%d", &POPULACAO);

    printf("Digite o estado: \n");
    scanf("%s", &ESTADO);

    printf("Digite a area: \n");
    scanf("%f", &AREA);

    printf("Digite o pib: \n");
    scanf("%f", &Pib);

    printf("Digite o Ponto Turistico: \n");
    scanf("%d", &PONTOTURISTICO);

    printf("População: %d - Estado: %s\n", POPULACAO, ESTADO);
    printf("Area: %f - PIB: %f\n", AREA, Pib);
    printf("Ponto Turístico %d\n", PONTOTURISTICO);

    return 0;
    
}
