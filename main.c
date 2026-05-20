#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>   // <-- IMPORTANTE (Windows UTF-8)
#include "game.h"
#include "colors.h"

// main p iniciar jogo
int main(void)
{
    // FORÇAR UTF-8 NO TERMINAL (EVITA LIXO COMO Ôûê)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int debug_seed = 0;

    printf("Modo debug? (1 = sim / 0 = nao): ");
    scanf("%d", &debug_seed);
    getchar();

    if (debug_seed == 1)
    {
        srand(1);
    }
    else
    {
        srand(time(NULL));
    }

    int option;

    printf("\n");

    // ===== ASCII ART (SAFE UTF-8) =====
    printf(YELLOW);
    printf("██╗   ██╗██╗ ██████╗\n");
    printf("██║   ██║██║██╔════╝\n");
    printf("██║   ██║██║██║     \n");
    printf("╚██╗ ██╔╝██║██║     \n");
    printf(" ╚████╔╝ ██║╚██████╗\n");
    printf("  ╚═══╝  ╚═╝ ╚═════╝\n");

    printf(RED);
    printf("███████╗██╗    ██╗███████╗███████╗██████╗ ███████╗██████╗ \n");
    printf("██╔════╝██║    ██║██╔════╝██╔════╝██╔══██╗██╔════╝██╔══██╗\n");
    printf("███████╗██║ █╗ ██║█████╗  █████╗  ██████╔╝█████╗  ██████╔╝\n");
    printf("╚════██║██║███╗██║██╔══╝  ██╔══╝  ██╔═══╝ ██╔══╝  ██╔══██╗\n");
    printf("███████║╚███╔███╔╝███████╗███████╗██║     ███████╗██║  ██║\n");
    printf("╚══════╝ ╚══╝╚══╝ ╚══════╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝\n");

    printf(RESET);

    printf("\n");
    printf(CYAN "=========== MINESWEEPER BY VIC ===========\n" RESET);
    printf("\n");

    printf("1 - Jogar\n");
    printf("2 - Sair\n");

    printf("Opcao: ");

    if (scanf("%d", &option) != 1)
    {
        printf("Input invalido. A sair...\n");
        return 0;
    }

    getchar();

    if (option == 2)
    {
        printf("A sair do jogo...\n");
        return 0;
    }

    char player[50];

    printf("Nome do jogador: ");
    fgets(player, sizeof(player), stdin);

    player[strcspn(player, "\n")] = '\0';

    int score = 0;
    int result;

    result = play_level(10, 3, 1, &score);
    if (result != 1)
    {
        printf("\nJogo terminado no nivel 1.\n");
        return 0;
    }

    result = play_level(5, 2, 2, &score);
    if (result != 1)
    {
        printf("\nJogo terminado no nivel 2.\n");
        return 0;
    }

    result = play_level(3, 1, 3, &score);
    if (result != 1)
    {
        printf("\nJogo terminado no nivel 3.\n");
        return 0;
    }

    printf("\n* * * * * * * * * * * * *\n");
    printf("PARABENS %s!\n", player);
    printf("COMPLETASTE TODOS OS NIVEIS!\n");
    printf("E o teu score final foi de %d\n", score);
    printf("* * * * * * * * * * * * *\n");

    return 0;
}