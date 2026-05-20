Registo de desenvolvimento do projeto em C ao longo das sessões de trabalho.

- SESSÃO 1 - IDEIA E PLANEAMENTO DO PROJETO

Nesta primeira sessão o objetivo foi explorar diferentes ideias de projeto, uma vez que não tinha muita experiência prévia no desenvolvimento deste tipo de jogo em C.

Inicialmente foram analisadas várias opções possíveis, tendo em conta a complexidade e viabilidade dentro do tempo disponível. Após alguma exploração, decidi desenvolver o jogo Minesweeper, mas numa versão simplificada e adaptada para terminal.

Defini que o jogo teria:
- tabuleiro dinâmico por níveis
- aumento de dificuldade progressivo
- sistema de minas aleatórias
- sistema de vidas e score

Nesta fase também comecei a planear a estrutura do programa, nomeadamente:
- que ficheiros seriam necessários (main, game, board, utils)
- que funções seriam necessárias para separar lógica do jogo
- como seria feita a divisão entre lógica do jogo e lógica do tabuleiro

O objetivo principal desta sessão foi perceber o que queria fazer.

- SESSÃO 2 - IMPLEMENTAÇÃO INICIAL E ESTRUTURA DO CÓDIGO

Nesta sessão comecei o desenvolvimento do código propriamente dito a partir da estrutura planeada anteriormente.

Desde o início decidi dividir o projeto em vários ficheiros (.c e .h), de forma a organizar melhor o código e evitar erros à medida que o projeto fosse aumentando.

Primeiro criei os ficheiros principais:
- main.c para a execução do programa e controlo dos níveis
- game.c encarregue da lógica principal do jogo
- board.c foco na gestão do tabuleiro e minas

Nesta fase comecei a implementar a base do jogo, incluindo:
- criação do tabuleiro com matrizes — criação de duas matrizes (board e visible) para haver uma parte interna e o que o jogador vê
- inicialização do estado visível e oculto — inicio do jogo, com o tab oculto preenchido com valores base e o visível escondid com #
- estrutura inicial do ciclo de jogo
- leitura de input do jogador (linha e coluna) — leitura do que o jogador escolher para revelar

Iniciei a separação de responsabilidades das funções, por exemplo:
- funções para colocar minas no tabuleiro
- funções para revelar células
- funções para calcular valores do tabuleiro (número de minas adjacentes)

O foco desta sessão foi criar uma base funcional do jogo.

- SESSÃO 3 - LÓGICA DO JOGO E MELHORIAS FUNCIONAIS

Nesta sessão foi dado continuidade ao desenvolvimento do jogo, focando na implementação da lógica principal e melhoria do funcionamento geral.

Implementei várias partes importantes do jogo, incluindo:
- sistema de colocação de minas aleatórias
- proteção da primeira jogada (garantir que não acaba logo)
- sistema de revelação de células individuais
- sistema de vidas (perde vida ao acertar numa mina, p evitar perder logo o jogo)
- sistema de score (incrementa a cada jogada segura)
- condição de vitória (quando todas as casas seguras são reveladas)
- condição de derrota (quando as vidas chegam a zero)

Também foram feitas melhorias na interação com o utilizador:
- validação de input (evitar entradas vazias ou inválidas)
- melhor feedback ao jogador em cada jogada
- melhoria na apresentação do tabuleiro

Nesta fase o jogo já se tornou funcional e jogável, embora ainda estejam previstas pequenas melhorias e ajustes finais após testes adicionais.

Foi também criada a componente auxiliar `utils.c`, responsável por funções de suporte ao jogo, nomeadamente o cálculo de minas adjacentes, permitindo separar a lógica principal da lógica de apoio ao tabuleiro. Esta separação ajudou a organizar melhor o código e a manter cada ficheiro com uma responsabilidade mais clara.

O objetivo da próxima fase será testar o jogo mais vezes e verificar se existem melhorias adicionais a implementar antes da entrega final.

- SESSÃO 4 - MELHORIAS NA INTERAÇÃO E EXPERIÊNCIA DE JOGO

Nesta sessão foram feitas melhorias na interação com o utilizador e na experiência geral do jogo, com o objetivo de tornar o jogo mais estável e mais intuitivo de jogar.

- validação de input para evitar entradas vazias ou inválidas
- melhoria do feedback ao jogador após cada jogada
- melhoria na apresentação do tab com grelha alinhada, índices e cores ANSI para distinguir estados das células

Nesta fase o foco foi na usabilidade e clareza do jogo durante a execução.

O objetivo final será continuar a testar o jogo e realizar pequenos ajustes caso sejam identificados problemas antes da entrega.
