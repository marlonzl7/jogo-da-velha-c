#include <stdio.h>

void mostrarJogo(char matriz[3][3]);
int fazerJogada(char matriz[3][3], int jogada, char jogador);
int verificarJogo(char matriz[3][3], char jogador);
int verificarLinhas(char matriz[3][3], char jogador);
int verificarColunas(char matriz[3][3], char jogador);
int verificarDiagonalPrincipal(char matriz[3][3], char jogador);
int verificarDiagonalSecundaria(char matriz[3][3], char jogador);
void limparBuffer();

int main() {
    int jogada, terminou = 0, qtdJogadas = 0;
    char jogador;
    char jogo[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    do {
        for (int i = 0; i < 2; i++) {
            printf("\nVez do jogador %d\n", i + 1);
            mostrarJogo(jogo);
            jogador = (i == 0) ? 'X' : 'O';

            int jogadaValida = 0;
            
            do {
                printf("Faça sua jogada (1 a 9): ");
                if (scanf("%d", &jogada) != 1) {
                    printf("Entrada inválida! Use apenas números.\n");
                    limparBuffer();
                    continue;
                }

                if (jogada < 1 || jogada > 9) {
                    printf("Jogada inválida! Escolha de 1 a 9.\n");
                } else if (!fazerJogada(jogo, jogada, jogador)) {
                    printf("Posição já ocupada. Escolha outra.\n");
                } else {
                    jogadaValida = 1;
                }

            } while (!jogadaValida);

            qtdJogadas++;

            if (verificarJogo(jogo, jogador)) {
                mostrarJogo(jogo);
                printf("----- Jogo encerrado! -----\n");
                printf("Resultado: Jogador %d venceu!\n", i + 1);
                printf("---------------------------\n");
                terminou = 1;
                break;
            }

            if (qtdJogadas == 9) {
                mostrarJogo(jogo);
                printf("----- Jogo encerrado! -----\n");
                printf("Resultado: Empate!\n");
                printf("---------------------------\n");
                terminou = 1;
                break;
            }
        }
    } while (!terminou);

    return 0;
}

void mostrarJogo(char matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("+---+---+---+\n");
        for (int j = 0; j < 3; j++) {
            printf("| %c ", matriz[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+\n");
}

int fazerJogada(char matriz[3][3], int jogada, char jogador) {
    int linha = (jogada - 1) / 3;
    int coluna = (jogada - 1) % 3;

    if (matriz[linha][coluna] == '-') {
        matriz[linha][coluna] = jogador;
        return 1;
    }
    return 0;
}

int verificarJogo(char matriz[3][3], char jogador) {
    return verificarLinhas(matriz, jogador)
        || verificarColunas(matriz, jogador)
        || verificarDiagonalPrincipal(matriz, jogador)
        || verificarDiagonalSecundaria(matriz, jogador);
}

int verificarLinhas(char matriz[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == jogador && matriz[i][1] == jogador && matriz[i][2] == jogador) {
            return 1;
        }
    }
    return 0;
}

int verificarColunas(char matriz[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (matriz[0][i] == jogador && matriz[1][i] == jogador && matriz[2][i] == jogador) {
            return 1;
        }
    }
    return 0;
}

int verificarDiagonalPrincipal(char matriz[3][3], char jogador) {
    return matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador;
}

int verificarDiagonalSecundaria(char matriz[3][3], char jogador) {
    return matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador;
}

void limparBuffer() {
    while (getchar() != '\n');
}
