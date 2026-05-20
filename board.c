#include <stdlib.h>
#include "board.h"
#include "utils.h"

// init_board p inicializar o tabuleiro escondido e o visivel
void init_board(char board[MAX][MAX],
                char visible[MAX][MAX],
                int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = '0';
            visible[i][j] = '#';
        }
    }
}

// place_mines p colocar minas aleatorias
void place_mines(char board[MAX][MAX],
                 int size,
                 int mines,
                 int first_row,
                 int first_col)
{
    int placed = 0;

    while (placed < mines)
    {
        int row = rand() % size;
        int col = rand() % size;

        if (row == first_row && col == first_col)
        {
            continue;
        }

        if (board[row][col] == '*')
        {
            continue;
        }

        board[row][col] = '*';
        placed++;
    }
}

// fill_numbers p preencher tabuleiro com numeros
void fill_numbers(char board[MAX][MAX],
                  int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == '*')
            {
                continue;
            }

            int mines = count_adjacent_mines(board, size, i, j);
            board[i][j] = mines + '0';
        }
    }
}

/*
✔ NOVO: flood fill (cascata Minesweeper)
- abre automaticamente áreas vazias
*/
static void flood_reveal(char board[MAX][MAX],
                         char visible[MAX][MAX],
                         int size,
                         int row,
                         int col,
                         int *revealed)
{
    if (row < 0 || row >= size || col < 0 || col >= size)
        return;

    if (visible[row][col] != '#')
        return;

    if (board[row][col] == '*')
        return;

    visible[row][col] = board[row][col];
    (*revealed)++;

    // só expande se for vazio ('0')
    if (board[row][col] == '0')
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i != 0 || j != 0)
                {
                    flood_reveal(board, visible, size,
                                 row + i, col + j,
                                 revealed);
                }
            }
        }
    }
}

// reveal_cells p revelar célula (AGORA COM CASCATA)
void reveal_cells(char board[MAX][MAX],
                  char visible[MAX][MAX],
                  int size,
                  int row,
                  int col,
                  int *revealed)
{
    if (row < 0 || row >= size || col < 0 || col >= size)
        return;

    if (visible[row][col] != '#')
        return;

    if (board[row][col] == '*')
        return;

    // ✔ NOVO: cascata real
    flood_reveal(board, visible, size, row, col, revealed);
}

// reveal_all p mostrar solucao final
void reveal_all(char board[MAX][MAX],
                char visible[MAX][MAX],
                int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            visible[i][j] = board[i][j];
        }
    }
}