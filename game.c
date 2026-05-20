#include <stdio.h>
#include <string.h>
#include "game.h"
#include "board.h"
#include "colors.h"

// print_board p mostrar tabuleiro
static void print_board(char visible[MAX][MAX],
                        int size,
                        int level,
                        int mines,
                        int lives,
                        int score,
                        int safe_left)
{
    printf("\n");
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");

    printf("          VICSWEEPER - MINESWEEPER\n");

    printf("* * * * * * * * * * * * * * * * * * * * * *\n");

    printf("Nivel: %d\n", level);
    printf("Minas: %d\n", mines);

    printf("Vidas: ");
    for (int i = 0; i < lives; i++)
    {
        printf("S2 ");
    }
    printf("\n");

    printf("Score: %d\n", score);

    printf("Progresso: %d/%d\n",
           (size * size) - mines - safe_left,
           (size * size) - mines);

    printf("\n   ");

    for (int i = 0; i < size; i++)
    {
        printf("%2d ", i);
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%2d ", i);

        for (int j = 0; j < size; j++)
        {
            if (visible[i][j] == '#')
                printf(" # ");

            else if (visible[i][j] == '*')
                printf(" * ");

            else if (visible[i][j] == '0')
                printf(" 0 ");

            else
                printf(" %c ", visible[i][j]);
        }

        printf("\n");
    }
}

/*
✔ FUNÇÃO PRINCIPAL DO JOGO
*/
int play_level(int size,
               int mines,
               int level,
               int *score)
{
    char board[MAX][MAX];
    char visible[MAX][MAX];

    int lives = (level == 1) ? 2 : 1;
    int revealed = 0;
    int safe_cells = (size * size) - mines;
    int first_move = 1;

    init_board(board, visible, size);

    while (1)
    {
        int row, col;
        int safe_left = safe_cells - revealed;

        print_board(visible, size, level, mines, lives, *score, safe_left);

        char input[20];

        printf("Linha (ou r para sair): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == 'r' || input[0] == 'R')
            return -1;

        if (sscanf(input, "%d", &row) != 1)
            continue;

        printf("Coluna (ou r para sair): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == 'r' || input[0] == 'R')
            return -1;

        if (sscanf(input, "%d", &col) != 1)
            continue;

        if (row < 0 || row >= size || col < 0 || col >= size)
            continue;

        if (visible[row][col] != '#')
            continue;

        if (first_move)
        {
            place_mines(board, size, mines, row, col);
            fill_numbers(board, size);
            first_move = 0;
        }

        if (board[row][col] == '*')
        {
            lives--;
            visible[row][col] = '*';

            if (lives <= 0)
            {
                reveal_all(board, visible, size);
                print_board(visible, size, level, mines, lives, *score, 0);
                printf("GAME OVER\n");
                return 0;
            }

            continue;
        }

        reveal_cells(board, visible, size, row, col, &revealed);

        (*score)++;

        if (revealed == safe_cells)
        {
            reveal_all(board, visible, size);
            print_board(visible, size, level, mines, lives, *score, 0);
            printf("LEVEL COMPLETE\n");
            return 1;
        }
    }
}