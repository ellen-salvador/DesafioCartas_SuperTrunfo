/*
 * Projeto: Super Trunfo de Cidades
 * Autor: Ellen Christiane Salvador
 * Data: 14/05/2025
 * Descrição: Cadastro e exibição de cartas do Super Trunfo para cidades brasileiras.
 */

#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[5];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para registrar uma carta
void registrarCarta(CartaCidade *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    // Dados automáticos
    sprintf(carta->codigo, "%c0%d", carta->estado, numero); // Ex: A01, B02
    carta->populacao = 100000 * numero; // Exemplo automático
    carta->area = 500.0f + 100.0f * numero; // Exemplo automático
    carta->pib = 50.0f * numero; // Exemplo automático
    carta->pontos_turisticos = 5 * numero; // Exemplo automático
}

// Função para exibir uma carta
void exibirCarta(const CartaCidade *carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nome);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km2\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontos_turisticos);
}

int main() {
    CartaCidade carta1, carta2;

    // Cadastro das duas cartas
    registrarCarta(&carta1, 1);
    registrarCarta(&carta2, 2);

    // Exibição das duas cartas
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);

    return 0;
}