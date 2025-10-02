#include <stdio.h>

int main() {
    // Declaração dos dados da Carta 1 
    char estado1[3];
    char codigo1[4];
    char nomeCidade1[30];
    int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // Declaração dos dados da Carta 2 
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[30];
    int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    // Entrada de dados da Carta 1 
    printf("Digite o Estado da Carta 1: ");
    scanf("%s", estado1);

    printf("Digite o Codigo da Carta 1: ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade da Carta 1: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a Populacao da Carta 1: ");
    scanf("%d", &populacao1);

    printf("Digite a Area da Carta 1 (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1 
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // Entrada de dados da Carta 2
    printf("\nDigite o Estado da Carta 2: ");
    scanf("%s", estado2);

    printf("Digite o Codigo da Carta 2: ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade da Carta 2: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a Populacao da Carta 2: ");
    scanf("%d", &populacao2);

    printf("Digite a Area da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2 
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // COMPARAÇÃO 
    // Aqui escolhemos qual atributo comparar.
    printf("\nComparacao de cartas (Atributo: Populacao):\n\n");
    printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
