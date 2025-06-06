#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios
#define NAVIO 3            // Valor que representa o navio no tabuleiro
#define AGUA 0             // Valor que representa água no tabuleiro

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios (definidas no código)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;

    // Validação dos limites do navio horizontal (posição horizontal)
    if (coluna_navio_horizontal + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se já há navios nas posições desejadas
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação dos limites do navio vertical (posição vertical)
    if (linha_navio_vertical + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se já há navios nas posições desejadas
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
