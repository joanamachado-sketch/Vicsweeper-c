# MINESWEEPER BY VIC

Projeto em C desenvolvido para o laboratório, com implementação de um jogo tipo Minesweeper em terminal.


* COMO COMPILAR

gcc main.c game.c board.c utils.c -o minesweeper


* COMO EXECUTAR

.\minesweeper.exe

--- OBJETIVO DO JOGO

O objetivo do jogo é revelar todas as casas seguras do tabuleiro sem encontrar minas.

Cada jogada segura aumenta o score em 1 ponto.

Se o jogador acertar numa mina perde uma vida.

O jogo termina quando:
- todas as vidas são perdidas 
- ou todas as casas seguras são reveladas (vitória)

--- REGRAS DO JOGO

- O tabuleiro é gerado dinamicamente por nível
- As minas são colocadas aleatoriamente após a primeira jogada
- A primeira jogada nunca é uma mina
- O jogador não pode selecionar casas já reveladas
- Cada nível tem dificuldade diferente
- O score aumenta por cada casa segura revelada

--- ESTRUTURA DO PROJETO

main.c → inicia o jogo e controla níveis  
game.c → lógica principal do jogo e interação com o jogador  
board.c → criação do tabuleiro, minas e revelação  
utils.c → funções auxiliares (ex: contagem de minas adjacentes)  
headers (.h) → definições e partilha entre módulos  

--- FUNCIONALIDADES

- Geração aleatória de minas
- Sistema de níveis progressivos (3 níveis)
- Sistema de vidas
- Sistema de score
- Revelação de células individuais
- Validação de input do utilizador
- Proteção da primeira jogada
- Interface em terminal
- Cores ANSI no tabuleiro
