#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Definição de uma estrutura para armazenar os dados de uma cidade
typedef struct {
    char codigo[5]; // Código da carta (ex: A01, B02)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Função para cadastrar as cidades
void cadastrarCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    for (char estado = 'A'; estado < 'A' + NUM_ESTADOS; estado++) {
        for (int cidadeNum = 0; cidadeNum < NUM_CIDADES; cidadeNum++) {
            int index = cidadeNum + (estado - 'A') * NUM_CIDADES;
            printf("Cadastro da cidade %c%02d:\n", estado, cidadeNum + 1);

            // Atribuindo o código da carta
            snprintf(cidades[estado - 'A'][cidadeNum].codigo, sizeof(cidades[estado - 'A'][cidadeNum].codigo), "%c%02d", estado, cidadeNum + 1);

            // Inserindo os dados da cidade
            printf("Informe a população: ");
            scanf("%d", &cidades[estado - 'A'][cidadeNum].populacao);
            printf("Informe a área (em km²): ");
            scanf("%f", &cidades[estado - 'A'][cidadeNum].area);
            printf("Informe o PIB (em bilhões de reais): ");
            scanf("%f", &cidades[estado - 'A'][cidadeNum].pib);
            printf("Informe o número de pontos turísticos: ");
            scanf("%d", &cidades[estado - 'A'][cidadeNum].pontos_turisticos);

            printf("\n");
        }
    }
}

// Função para exibir os dados de todas as cidades cadastradas
void exibirCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    printf("Dados das Cidades Cadastradas:\n\n");
    
    for (char estado = 'A'; estado < 'A' + NUM_ESTADOS; estado++) {
        for (int cidadeNum = 0; cidadeNum < NUM_CIDADES; cidadeNum++) {
            printf("Cidade %c%02d:\n", estado, cidadeNum + 1);
            printf("Código: %s\n", cidades[estado - 'A'][cidadeNum].codigo);
            printf("População: %d\n", cidades[estado - 'A'][cidadeNum].populacao);
            printf("Área: %.2f km²\n", cidades[estado - 'A'][cidadeNum].area);
            printf("PIB: R$ %.2f bilhões\n", cidades[estado - 'A'][cidadeNum].pib);
            printf("Pontos Turísticos: %d\n", cidades[estado - 'A'][cidadeNum].pontos_turisticos);
            printf("\n");
        }
    }
}

int main() {
    // Matriz para armazenar as cidades
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    
    // Cadastrar as cidades
    cadastrarCidades(cidades);

    // Exibir as cidades cadastradas
    exibirCidades(cidades);

    return 0;
}