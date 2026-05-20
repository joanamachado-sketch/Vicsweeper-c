#include <stdio.h>
#include <string.h>
#include "game.h"
#include "board.h"
#include "colors.h"

//print_board p mostrar tabuleiro
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
    printf("          MINESWEEPER BY VIC\n");
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

    //p informação mais clara sobre progresso do jogador
    printf("Progresso: %d/%d casas seguras descobertas\n",
           (size * size) - mines - safe_left,
           (size * size) - mines);

    printf("\n");

    printf("   ");

    // imprime indices das colunas (referencia do jogador)
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
            // cores para melhorar leitura do tabuleiro
            if (visible[i][j] == '#')
            {
                printf(CYAN " # " RESET); // casa escondida
            }
            else if (visible[i][j] == '*')
            {
                printf(RED " * " RESET); // mina
            }
            else if (visible[i][j] == '0')
            {
                printf(GREEN " 0 " RESET); // sem minas adjacentes
            }
            else
            {
                printf(YELLOW " %c " RESET, visible[i][j]); // numeros 1-8
            }
        }

        printf("\n");
    }

    printf("\n");
}

//jogar cada nivel do jogo
int play_level(int size,
               int mines,
               int level,
               int *score)
{
    char board[MAX][MAX];     // tabuleiro real (minas + numeros)
    char visible[MAX][MAX];   // tabuleiro visivel ao jogador

    int lives;

    // nivel 1 é mais facil (mais vidas)
    if (level == 1)
    {
        lives = 2;
    }
    else
    {
        lives = 1;
    }

    int revealed = 0; // conta casas seguras abertas

    int safe_cells = (size * size) - mines; // total de casas seguras

    int first_move = 1; // garante que primeira jogada nunca é mina

    init_board(board, visible, size); // inicializa tabuleiros

    while (1)
    {
        int row;
        int col;

        int safe_left = safe_cells - revealed;

        print_board(visible,
                    size,
                    level,
                    mines,
                    lives,
                    *score,
                    safe_left);

        char input[20];

        printf("Linha (ou q para sair): ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        // sair do jogo
        if (input[0] == 'q' || input[0] == 'Q')
        {
            return -1;
        }

        // input vazio nao é valido
        if (strlen(input) == 0)
        {
            printf("Input invalido!\n");
            continue;
        }

        // converte linha para numero
        if (sscanf(input, "%d", &row) != 1)
        {
            printf("Input invalido!\n");
            continue;
        }

        printf("Coluna (ou q para sair): ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (input[0] == 'q' || input[0] == 'Q')
        {
            return -1;
        }

        if (strlen(input) == 0)
        {
            printf("Input invalido!\n");
            continue;
        }

        // converte coluna para numero
        if (sscanf(input, "%d", &col) != 1)
        {
            printf("Input invalido!\n");
            continue;
        }

        // valida limites do tabuleiro
        if (row < 0 || row >= size || col < 0 || col >= size)
        {
            printf("\nCoordenada invalida! Usa valores entre 0 e %d.\n", size - 1);
            continue;
        }

        // verifica se a casa já foi jogada
        if (visible[row][col] != '#')
        {
            // ✔ MELHORIA: feedback divertido ao jogador
            printf("\nEssa casa ja foi... ahah va nao tenhas medo, escolhe um espaco livre!\n");
            continue;
        }

        // primeira jogada gera minas evitando a primeira posição
        if (first_move)
        {
            place_mines(board,
                        size,
                        mines,
                        row,
                        col);

            fill_numbers(board, size);

            first_move = 0;
        }

        // se acertar numa mina
        if (board[row][col] == '*')
        {
            lives--;

            printf("\nBOOM! Ups uma mina..\n");

            visible[row][col] = '*';

            // se perder todas as vidas termina o nivel
            if (lives <= 0)
            {
                reveal_all(board, visible, size);

                print_board(visible,
                            size,
                            level,
                            mines,
                            lives,
                            *score,
                            0);

                printf("LOSER! Sorry, tenta de novo...\n");

                return 0;
            }

            continue;
        }

        // revela a célula escolhida
        reveal_cells(board,
                     visible,
                     size,
                     row,
                     col,
                     &revealed);

        // aumenta score por jogada segura
        (*score) += 1;

        printf("\n Sem mina. Continua! \n");

        // condição de vitória
        if (revealed == safe_cells)
        {
            reveal_all(board, visible, size);

            print_board(visible,
                        size,
                        level,
                        mines,
                        lives,
                        *score,
                        0);

            printf("Nivel %d completo!\n", level);

            return 1;
        }
    }
}