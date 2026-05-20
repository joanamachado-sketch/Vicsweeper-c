#include <stdlib.h>
#include "board.h"
#include "utils.h"

//init_board p inicializar o tabuleiro escondido e o visivel
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

//place_mines p colocar minas aleatorias
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

        if (row == first_row &&
            col == first_col)
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

//fill_numbers p preencher tabuleiro com numeros
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

            int mines = count_adjacent_mines(board,
                                              size,
                                              i,
                                              j);

            board[i][j] = mines + '0';
        }
    }
}

//reveal_cells p revelar APENAS UMA CASA (SEM EXPANSÃO)
void reveal_cells(char board[MAX][MAX],
                  char visible[MAX][MAX],
                  int size,
                  int row,
                  int col,
                  int *revealed)
{
    // limites
    if (row < 0 ||
        row >= size ||
        col < 0 ||
        col >= size)
    {
        return;
    }

    // já revelada
    if (visible[row][col] != '#')
    {
        return;
    }

    // mina (não revela aqui)
    if (board[row][col] == '*')
    {
        return;
    }

    // ✔ revela apenas UMA célula (modo correto tipo Minesweeper simples)
    visible[row][col] = board[row][col];
    (*revealed)++;
}

//reveal_all p mostrar solucao final
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