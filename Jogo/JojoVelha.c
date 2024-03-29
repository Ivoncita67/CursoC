#include <stdio.h>

// Função para imprimir o tabuleiro do jogo
void imprimir_tabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Função para verificar se houve um vencedor
char verificar_vencedor(char tabuleiro[3][3]) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) return tabuleiro[0][i];
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) return tabuleiro[0][2];
    // Verificar se houve empate
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') return ' ';
        }
    }
    return 'D'; // Empate
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char jogador_atual = 'X';
    int linha, coluna;
    char vencedor = ' ';

    printf("Bem-vindo ao Jogo da Velha!\n");

    // Loop principal do jogo
    while (vencedor == ' ') {
        imprimir_tabuleiro(tabuleiro);
        printf("Jogador %c, digite a linha (1-3) e coluna (1-3) para sua jogada: ", jogador_atual);
        scanf("%d %d", &linha, &coluna);
        linha--; coluna--;

        // Verificar se a posição é válida e está vazia
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador_atual;
            vencedor = verificar_vencedor(tabuleiro);
            // Alternar o jogador
            jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }

    // Exibir o resultado do jogo
    imprimir_tabuleiro(tabuleiro);
    if (vencedor == 'X' || vencedor == 'O') {
        printf("Parabéns! O jogador %c venceu!\n", vencedor);
    } else {
        printf("O jogo empatou!\n");
    }

    return 0;
}
