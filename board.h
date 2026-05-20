#ifndef BOARD_H
#define BOARD_H

#define MAX 10   // ✔ garante que todos os ficheiros "veem" MAX

//init_board p inicializar o tabuleiro escondido e o visivel
void init_board(char board[MAX][MAX],
                char visible[MAX][MAX],
                int size);

//place_mines p colocar minas aleatorias
void place_mines(char board[MAX][MAX],
                 int size,
                 int mines,
                 int first_row,
                 int first_col);

//fill_numbers p preencher tabuleiro com numeros
void fill_numbers(char board[MAX][MAX],
                  int size);

//reveal_cells p revelar casas (apenas 1 célula)
void reveal_cells(char board[MAX][MAX],
                  char visible[MAX][MAX],
                  int size,
                  int row,
                  int col,
                  int *revealed);

//reveal_all p mostrar solução final
void reveal_all(char board[MAX][MAX],
                char visible[MAX][MAX],
                int size);

#endif