#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para calcular densidade e PIB per capita
void calcularIndicadores(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para exibir atributos no menu
void exibirMenuAtributos(int excluir) {
    printf("\nEscolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos turísticos\n");
    if (excluir != 5) printf("5 - Densidade demográfica\n");
    if (excluir != 6) printf("6 - PIB per capita\n");
    printf("Opção: ");
}

// Função que retorna o valor numérico de um atributo
float obterValor(Carta c, int atributo) {
    switch(atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        case 6: return c.pib_per_capita;
        default: return 0.0;
    }
}

// Função que retorna o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade demográfica";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Cadastro de duas cartas (pré-definidas)
    Carta c1 = {"São Paulo", "A01", "São Paulo", 12300000, 1521.0, 699.28, 50};
    Carta c2 = {"Rio de Janeiro", "A02", "Rio de Janeiro", 6748000, 1200.0, 364.89, 35};

    // Calculando indicadores
    calcularIndicadores(&c1);
    calcularIndicadores(&c2);

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo 
    exibirMenuAtributos(atributo1);
    scanf("%d", &atributo2);

    // Valores para cada carta
    float valor1_attr1 = obterValor(c1, atributo1);
    float valor2_attr1 = obterValor(c2, atributo1);
    float valor1_attr2 = obterValor(c1, atributo2);
    float valor2_attr2 = obterValor(c2, atributo2);

    // Comparação de cada atributo
    printf("\n--- Comparação de Cartas ---\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n\n", c2.cidade, c2.estado);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", c1.cidade, valor1_attr1);
    printf("%s: %.2f\n", c2.cidade, valor2_attr1);

    int resultado1 = (atributo1 == 5) 
        ? (valor1_attr1 < valor2_attr1) 
        : (valor1_attr1 > valor2_attr1);
    printf("Vencedor: %s\n\n", 
           (valor1_attr1 == valor2_attr1) ? "Empate" : (resultado1 ? c1.cidade : c2.cidade));

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", c1.cidade, valor1_attr2);
    printf("%s: %.2f\n", c2.cidade, valor2_attr2);

    int resultado2 = (atributo2 == 5) 
        ? (valor1_attr2 < valor2_attr2) 
        : (valor1_attr2 > valor2_attr2);
    printf("Vencedor: %s\n\n", 
           (valor1_attr2 == valor2_attr2) ? "Empate" : (resultado2 ? c1.cidade : c2.cidade));

    // Soma dos atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("--- Resultado Final ---\n");
    printf("%s - Soma: %.2f\n", c1.cidade, soma1);
    printf("%s - Soma: %.2f\n", c2.cidade, soma2);

    if (soma1 > soma2) {
        printf("Resultado: %s venceu a rodada!\n", c1.cidade);
    } else if (soma2 > soma1) {
        printf("Resultado: %s venceu a rodada!\n", c2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
