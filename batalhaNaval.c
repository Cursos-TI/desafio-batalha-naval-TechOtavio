#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3        // Tamanho dos navios
#define NAVIO 3            // Valor que representa navio
#define AGUA 0             // Valor que representa água

// Função para verificar se há sobreposição em posições horizontais
int podePosicionarHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == NAVIO)
            return 0;
    }
    return 1;
}

// Função para verificar se há sobreposição em posições verticais
int podePosicionarVertical(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO)
            return 0;
    }
    return 1;
}

// Função para verificar se pode posicionar em diagonal crescente (\)
int podePosicionarDiagonalPrincipal(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] == NAVIO)
            return 0;
    }
    return 1;
}

// Função para verificar se pode posicionar em diagonal secundária (/)
int podePosicionarDiagonalSecundaria(int tabuleiro[10][10], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] == NAVIO)
            return 0;
    }
    return 1;
}

// Posicionamento do navio no tabuleiro
void posicionarHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

void posicionarVertical(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

void posicionarDiagonalPrincipal(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

void posicionarDiagonalSecundaria(int tabuleiro[10][10], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio horizontal
    int l1 = 1, c1 = 2;
    if (podePosicionarHorizontal(tabuleiro, l1, c1)) {
        posicionarHorizontal(tabuleiro, l1, c1);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    // Navio vertical
    int l2 = 4, c2 = 6;
    if (podePosicionarVertical(tabuleiro, l2, c2)) {
        posicionarVertical(tabuleiro, l2, c2);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    // Navio diagonal principal (\)
    int l3 = 0, c3 = 0;
    if (podePosicionarDiagonalPrincipal(tabuleiro, l3, c3)) {
        posicionarDiagonalPrincipal(tabuleiro, l3, c3);
    } else {
        printf("Erro ao posicionar navio diagonal principal.\n");
        return 1;
    }

    // Navio diagonal secundária (/)
    int l4 = 5, c4 = 9;
    if (podePosicionarDiagonalSecundaria(tabuleiro, l4, c4)) {
        posicionarDiagonalSecundaria(tabuleiro, l4, c4);
    } else {
        printf("Erro ao posicionar navio diagonal secundária.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
