#include <stdio.h>
#include <stdbool.h>

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
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &letra_estado1);
    printf("Codigo (3 letras/numeros): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);
    printf("Numero da população: ");
    scanf("%lu", &populacao1);
    printf("Tamanho (km²): ");
    scanf("%f", &tamanho1);
    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos_tur1);
    
    densidade1 = populacao1 / tamanho1;
    pib_por_pessoa1 = (pib1 * 1000000000) / populacao1;
    superpoder1 = populacao1 + tamanho1 + pib1 + pontos_tur1 + pib_por_pessoa1 + (1/densidade1);

    // Cadastro da segunda cidade
    printf("\nCadastro da Cidade 2:\n");
    printf("Letra do Estado (A-H): ");
    scanf(" %c", &letra_estado2);
    printf("Codigo (3 letras/numeros): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);
    printf("Numero da população: ");
    scanf("%lu", &populacao2);
    printf("Tamanho (km²): ");
    scanf("%f", &tamanho2);
    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontos_tur2);
    
    densidade2 = populacao2 / tamanho2;
    pib_por_pessoa2 = (pib2 * 1000000000) / populacao2;
    superpoder2 = populacao2 + tamanho2 + pib2 + pontos_tur2 + pib_por_pessoa2 + (1/densidade2);

    // Exibição das cartas (com Super Poder)
    printf("\n=== Carta 1 ===\n");
    printf("Nome: %s\n", nome_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Area: %.2f km²\n", tamanho1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_tur1);
    printf("Densidade: %.2f hab/km²\n", densidade1);
    printf("PIB por pessoa: %.2f reais\n", pib_por_pessoa1);
    printf("Super Poder: %.2f\n", superpoder1);

    printf("\n=== Carta 2 ===\n");
    printf("Nome: %s\n", nome_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Area: %.2f km²\n", tamanho2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_tur2);
    printf("Densidade: %.2f hab/km²\n", densidade2);
    printf("PIB por pessoa: %.2f reais\n", pib_por_pessoa2);
    printf("Super Poder: %.2f\n", superpoder2);

    // Sistema de comparação com dois atributos (nova funcionalidade)
    int opcao1, opcao2;
    bool valido;
    
    do {
        printf("\n=== COMPARAÇÃO AVANÇADA ===\n");
        printf("Escolha DOIS atributos diferentes para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB por Pessoa\n");
        printf("0 - Sair\n");
        
        // Primeiro atributo com validação
        do {
            printf("\nEscolha o primeiro atributo (1-6, 0 para sair): ");
            if(scanf("%d", &opcao1) != 1) {
                printf("Entrada inválida! Digite um número.\n");
                while(getchar() != '\n'); // Limpa o buffer para validar se digitou letras
                continue;
            }
            
            if(opcao1 == 0) {
                printf("Encerrando o jogo...\n");
                return 0;
            }
            
            valido = (opcao1 >= 1 && opcao1 <= 6);
            
            if(!valido) {
                printf("Atributo inválido! Escolha um número entre 1 e 6.\n");
            }
        } while(!valido);
        
        // Segundo atributo com validação
        do {
            printf("Escolha o segundo atributo (diferente do primeiro, 1-6, 0 para sair): ");
            if(scanf("%d", &opcao2) != 1) {
                printf("Entrada inválida! Digite um número.\n");
                while(getchar() != '\n'); // Limpa o buffer para validar se digitou letras
                continue;
            }
            
            if(opcao2 == 0) {
                printf("Encerrando o jogo...\n");
                return 0;
            }
            
            valido = (opcao2 != opcao1) && (opcao2 >= 1 && opcao2 <= 6);
            
            if(!valido) {
                printf("Atributo inválido! Escolha um diferente do primeiro e entre 1 e 6.\n");
            }
        } while(!valido);

        // Variáveis temporárias para os valores dos atributos selecionados
        float valor1_attr1, valor1_attr2, valor2_attr1, valor2_attr2;
        char *nome_attr1, *nome_attr2;
        
        // Determina valores do primeiro atributo
        switch(opcao1) {
            case 1: valor1_attr1 = populacao1; valor2_attr1 = populacao2; nome_attr1 = "População"; break;
            case 2: valor1_attr1 = tamanho1; valor2_attr1 = tamanho2; nome_attr1 = "Área"; break;
            case 3: valor1_attr1 = pib1; valor2_attr1 = pib2; nome_attr1 = "PIB"; break;
            case 4: valor1_attr1 = pontos_tur1; valor2_attr1 = pontos_tur2; nome_attr1 = "Pontos Turísticos"; break;
            case 5: valor1_attr1 = densidade1; valor2_attr1 = densidade2; nome_attr1 = "Densidade Demográfica"; break;
            case 6: valor1_attr1 = pib_por_pessoa1; valor2_attr1 = pib_por_pessoa2; nome_attr1 = "PIB por Pessoa"; break;
        }
        
        // Determina valores do segundo atributo
        switch(opcao2) {
            case 1: valor1_attr2 = populacao1; valor2_attr2 = populacao2; nome_attr2 = "População"; break;
            case 2: valor1_attr2 = tamanho1; valor2_attr2 = tamanho2; nome_attr2 = "Área"; break;
            case 3: valor1_attr2 = pib1; valor2_attr2 = pib2; nome_attr2 = "PIB"; break;
            case 4: valor1_attr2 = pontos_tur1; valor2_attr2 = pontos_tur2; nome_attr2 = "Pontos Turísticos"; break;
            case 5: valor1_attr2 = densidade1; valor2_attr2 = densidade2; nome_attr2 = "Densidade Demográfica"; break;
            case 6: valor1_attr2 = pib_por_pessoa1; valor2_attr2 = pib_por_pessoa2; nome_attr2 = "PIB por Pessoa"; break;
        }
        
        // Exibe os atributos selecionados
        printf("\n=== ATRIBUTOS SELECIONADOS ===\n");
        printf("1º Atributo: %s\n", nome_attr1);
        printf("2º Atributo: %s\n", nome_attr2);
        
        // Comparação individual dos atributos
        printf("\n=== RESULTADOS INDIVIDUAIS ===\n");
        
        // Comparação do primeiro atributo
        printf("\nComparação de %s:\n", nome_attr1);
        printf("%s: %.2f\n", nome_cidade1, valor1_attr1);
        printf("%s: %.2f\n", nome_cidade2, valor2_attr1);
        
        int resultado_attr1;
        if(opcao1 == 5) { // Densidade (menor vence)
            resultado_attr1 = (valor1_attr1 < valor2_attr1) ? 1 : 
                             (valor2_attr1 < valor1_attr1) ? 2 : 0;
        } else { // Demais atributos (maior vence)
            resultado_attr1 = (valor1_attr1 > valor2_attr1) ? 1 : 
                             (valor2_attr1 > valor1_attr1) ? 2 : 0;
        }
        
        if(resultado_attr1 == 1) {
            printf("Vencedor: %s\n", nome_cidade1);
        } else if(resultado_attr1 == 2) {
            printf("Vencedor: %s\n", nome_cidade2);
        } else {
            printf("Empate!\n");
        }
        
        // Comparação do segundo atributo
        printf("\nComparação de %s:\n", nome_attr2);
        printf("%s: %.2f\n", nome_cidade1, valor1_attr2);
        printf("%s: %.2f\n", nome_cidade2, valor2_attr2);
        
        int resultado_attr2;
        if(opcao2 == 5) { // Densidade (menor vence)
            resultado_attr2 = (valor1_attr2 < valor2_attr2) ? 1 : 
                             (valor2_attr2 < valor1_attr2) ? 2 : 0;
        } else { // Demais atributos (maior vence)
            resultado_attr2 = (valor1_attr2 > valor2_attr2) ? 1 : 
                             (valor2_attr2 > valor1_attr2) ? 2 : 0;
        }
        
        if(resultado_attr2 == 1) {
            printf("Vencedor: %s\n", nome_cidade1);
        } else if(resultado_attr2 == 2) {
            printf("Vencedor: %s\n", nome_cidade2);
        } else {
            printf("Empate!\n");
        }
        
        // Soma dos atributos e resultado final
        printf("\n=== RESULTADO FINAL ===\n");
        
        // Ajusta os valores para a soma 
        float soma1 = (opcao1 == 5) ? (1/valor1_attr1) : valor1_attr1;
        soma1 += (opcao2 == 5) ? (1/valor1_attr2) : valor1_attr2;
        
        float soma2 = (opcao1 == 5) ? (1/valor2_attr1) : valor2_attr1;
        soma2 += (opcao2 == 5) ? (1/valor2_attr2) : valor2_attr2;
        
        printf("Soma dos atributos ajustados:\n");
        printf("%s: %.2f\n", nome_cidade1, soma1);
        printf("%s: %.2f\n", nome_cidade2, soma2);
        
        if(soma1 > soma2) {
            printf("\nRESULTADO FINAL: %s VENCEU!\n", nome_cidade1);
        } else if(soma2 > soma1) {
            printf("\nRESULTADO FINAL: %s VENCEU!\n", nome_cidade2);
        } else {
            printf("\nRESULTADO FINAL: EMPATE!\n");
        }
        
    } while(true);

    return 0;
}