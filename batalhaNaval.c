#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

 

#include <stdio.h>
// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#define TAM 10      // tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3     // tamanho fixo dos navios
#define NUM_NAVIOS 2 // quantidade de navios

int main() {
    int tabuleiro[TAM][TAM];

    // Cada navio ocupa 3 posições consecutivas (horizontalmente)
    int navios[NUM_NAVIOS][2] = {
        {1, 2}, {5, 4}// navio 1 começa na linha 1, coluna 2 ; navio 2 começa na linha 5, coluna 4
    };

    //  Inicializa o tabuleiro com '0' (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //  Posiciona os navios no tabuleiro
    for (int i = 0; i < NUM_NAVIOS; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];

        // Coloca o navio horizontalmente (3 posições)
        if(i == 0) {
            for (int j = 0; j < TAM_NAVIO; j++) {
                if (coluna + j < TAM) {
                    tabuleiro[linha][coluna + j] = 3;
                }
            }
        } 
        else {
            // Coloca o navio vertical (3 posições)
            for (int k = 0; k < TAM_NAVIO; k++) {
                if (linha + k < TAM) {
                tabuleiro[linha + k][coluna] = 3;
                }
            }
        }
    }

    //  Exibe o tabuleiro na tela
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    printf("   ");
    for  (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}