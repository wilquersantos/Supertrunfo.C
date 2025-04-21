#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char letra_estado1;
    char codigo1[4];
    char nome_cidade1[50];
    unsigned long int populacao1;
    float tamanho1;
    float pib1;
    int pontos_tur1;
    float densidade1;
    float pib_por_pessoa1;
    float superpoder1;

    // Variáveis para a segunda carta
    char letra_estado2;
    char codigo2[4];
    char nome_cidade2[50];
    unsigned long int populacao2;
    float tamanho2;
    float pib2;
    int pontos_tur2;
    float densidade2;
    float pib_por_pessoa2;
    float superpoder2;

    // Cadastro da primeira cidade
    printf("Cadastro da Cidade 1:\n");
    
    // Lê os dados um por um
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &letra_estado1);
    
    printf("Codigo (3 letras/numeros): ");
    scanf("%s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);  // Lê nome com espaço
    
    printf("Numero da população: ");
    scanf("%lu", &populacao1);
    
    printf("Tamanho (km²): ");
    scanf("%f", &tamanho1);
    
    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);
    
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos_tur1);
    
    // Calcula a densidade 
    densidade1 = populacao1 / tamanho1;
    
    // Calcula PIB por pessoa (converte bilhões para reais)
    pib_por_pessoa1 = (pib1 * 1000000000) / populacao1;

    // Cadastro da segunda cidade
    printf("\nCadastro da Cidade 2:\n");
    
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &letra_estado2);
    
    printf("Codigo (3 letras/numeros): ");
    scanf("%s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);   // Lê nome com espaço
    
    printf("Numero da população: ");
    scanf("%lu", &populacao2);
    
    printf("Tamanho (km²): ");
    scanf("%f", &tamanho2);
    
    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);
    
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos_tur2);
    
    // Cálculos para a segunda cidade
    densidade2 = populacao2 / tamanho2;
    pib_por_pessoa2 = (pib2 * 1000000000) / populacao2;

    //super poder carta 1
    superpoder1 = populacao1 + tamanho1 + pib1 + pontos_tur1 + pib_por_pessoa1 + (1/densidade1);

    //super poder carta 2
    superpoder2 = populacao2 + tamanho2 + pib2 + pontos_tur2 + pib_por_pessoa2 + (1/densidade2);

    // Mostra os resultados da primeira carta
    printf("\nCarta 1:\n");
    printf("Nome: %s\n", nome_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Area: %.2f km²\n", tamanho1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_tur1);
    printf("Densidade: %.2f hab/km²\n", densidade1);
    printf("PIB por pessoa: %.2f reais\n", pib_por_pessoa1);
    printf("Super Poder Carta 1: %.2f\n", superpoder1);

    // Mostra os resultados da segunda carta
    printf("\nCarta 2:\n");
    printf("Nome: %s\n", nome_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Area: %.2f km²\n", tamanho2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_tur2);
    printf("Densidade: %.2f hab/km²\n", densidade2);
    printf("PIB por pessoa: %.2f reais\n", pib_por_pessoa2);
    printf("Super Poder Carta 2: %.2f\n", superpoder2);

    // Menu interativo
    int opcao;
    do {
        printf("\nMenu de Atributos para Comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB por Pessoa\n");
        printf("0 - Sair\n");
        printf("Escolha o atributo para comparar: ");
        scanf("%d", &opcao);

        if(opcao == 0) {
            printf("Encerrando o jogo...\n");
            break;
        }

        printf("\nComparação de cartas:\n");
        printf("Carta 1 - %s: ", nome_cidade1);
        printf("Carta 2 - %s: ", nome_cidade2);

        switch(opcao) {
            case 1: // População
                printf("\nAtributo escolhido: População\n");
                printf("%s: %lu habitantes\n", nome_cidade1, populacao1);
                printf("%s: %lu habitantes\n", nome_cidade2, populacao2);
                
                if(populacao1 > populacao2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(populacao2 > populacao1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\nAtributo escolhido: Área\n");
                printf("%s: %.2f km²\n", nome_cidade1, tamanho1);
                printf("%s: %.2f km²\n", nome_cidade2, tamanho2);
                
                if(tamanho1 > tamanho2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(tamanho2 > tamanho1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\nAtributo escolhido: PIB\n");
                printf("%s: %.2f bilhões\n", nome_cidade1, pib1);
                printf("%s: %.2f bilhões\n", nome_cidade2, pib2);
                
                if(pib1 > pib2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(pib2 > pib1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\nAtributo escolhido: Pontos Turísticos\n");
                printf("%s: %d pontos\n", nome_cidade1, pontos_tur1);
                printf("%s: %d pontos\n", nome_cidade2, pontos_tur2);
                
                if(pontos_tur1 > pontos_tur2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(pontos_tur2 > pontos_tur1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("\nAtributo escolhido: Densidade Demográfica\n");
                printf("%s: %.2f hab/km²\n", nome_cidade1, densidade1);
                printf("%s: %.2f hab/km²\n", nome_cidade2, densidade2);
                
                // Regra invertida para densidade (menor vence)
                if(densidade1 < densidade2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(densidade2 < densidade1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 6: // PIB por Pessoa
                printf("\nAtributo escolhido: PIB por Pessoa\n");
                printf("%s: %.2f reais\n", nome_cidade1, pib_por_pessoa1);
                printf("%s: %.2f reais\n", nome_cidade2, pib_por_pessoa2);
                
                if(pib_por_pessoa1 > pib_por_pessoa2) {
                    printf("Resultado: %s venceu!\n", nome_cidade1);
                } else if(pib_por_pessoa2 > pib_por_pessoa1) {
                    printf("Resultado: %s venceu!\n", nome_cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}