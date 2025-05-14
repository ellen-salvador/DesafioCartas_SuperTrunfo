#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[5];
    char nome[50];
    int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} CartaCidade;

// Preenche automaticamente os dados das 5 principais capitais
void preencherDadosReais(CartaCidade *carta) {
    if (strcmp(carta->nome, "São Paulo") == 0) {
        carta->populacao = 12325000;
        carta->area = 1521.11f;
        carta->pib = 699.28f;
        carta->pontos_turisticos = 50;
    } else if (strcmp(carta->nome, "Rio de Janeiro") == 0) {
        carta->populacao = 6748000;
        carta->area = 1200.25f;
        carta->pib = 300.50f;
        carta->pontos_turisticos = 30;
    } else if (strcmp(carta->nome, "Brasília") == 0) {
        carta->populacao = 3055149;
        carta->area = 5802.00f;
        carta->pib = 254.00f;
        carta->pontos_turisticos = 25;
    } else if (strcmp(carta->nome, "Salvador") == 0) {
        carta->populacao = 2886698;
        carta->area = 693.80f;
        carta->pib = 63.62f;
        carta->pontos_turisticos = 22;
    } else if (strcmp(carta->nome, "Belo Horizonte") == 0) {
        carta->populacao = 2523000;
        carta->area = 331.40f;
        carta->pib = 104.30f;
        carta->pontos_turisticos = 20;
    } else {
        printf("População: ");
        scanf("%d", &carta->populacao);
        printf("Área (em km2): ");
        scanf("%f", &carta->area);
        printf("PIB (em bilhões de reais): ");
        scanf("%f", &carta->pib);
        printf("Número de pontos turísticos: ");
        scanf("%d", &carta->pontos_turisticos);
    }
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;
}

void registrarCarta(CartaCidade *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);
    printf("Código da carta (ex: A01): ");
    scanf(" %4s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    preencherDadosReais(carta);
}

void exibirCarta(const CartaCidade *carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nome);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km2\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta->pib_per_capita);
}

int main() {
    CartaCidade carta1, carta2;

    registrarCarta(&carta1, 1);
    registrarCarta(&carta2, 2);

    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);

    return 0;
}