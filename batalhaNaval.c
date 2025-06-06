#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]) {
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
            else
                printf("? ");
        }
        printf("\n");
    }
}

// Cria uma matriz de habilidade com forma de cone
void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone apontando para baixo
            if (j >= (TAM_HABILIDADE - 1) / 2 - i && j <= (TAM_HABILIDADE - 1) / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade com forma de cruz
void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade com forma de octaedro (losango)
void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(centro - i) + abs(centro - j) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Sobrepõe a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - offset + i;
            int colunaTabuleiro = origemColuna - offset + j;

            // Verifica se está dentro dos limites
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO) {

                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navios manualmente (exemplo)
    tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO; tabuleiro[1][4] = NAVIO; // horizontal
    tabuleiro[4][6] = NAVIO; tabuleiro[5][6] = NAVIO; tabuleiro[6][6] = NAVIO; // vertical
    tabuleiro[0][0] = NAVIO; tabuleiro[1][1] = NAVIO; tabuleiro[2][2] = NAVIO; // diagonal principal
    tabuleiro[5][9] = NAVIO; tabuleiro[6][8] = NAVIO; tabuleiro[7][7] = NAVIO; // diagonal secundária

    // Matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro (pontos de origem definidos manualmente)
    aplicarHabilidade(tabuleiro, cone, 2, 2);        // centro da habilidade cone
    aplicarHabilidade(tabuleiro, cruz, 5, 6);        // centro da cruz
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);    // centro do octaedro

    // Imprime o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
