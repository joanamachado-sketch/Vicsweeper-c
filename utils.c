#include "utils.h"
#include "board.h"

//count_adjacent_mines p contar minas vizinhas
int count_adjacent_mines(char board[MAX][MAX],
                          int size,
                          int row,
                          int col)
{
    int mines = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            // limites do tabuleiro
            if (i >= 0 &&
                i < size &&
                j >= 0 &&
                j < size)
            {
                if (board[i][j] == '*')
                {
                    mines++;
                }
            }
        }
    }

    return mines;
}