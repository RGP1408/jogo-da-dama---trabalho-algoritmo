#include <stdio.h>
#include <stdlib.h>
#define N 8
/* preenche o tabuleiro com peças e printa */
void printmatriz (char **M) {
    int i,j;

     printf("   0  1  2  3  4  5  6  7 \n");

     for (i = 0; i < N; i++) {
      printf("%d ", i);
        for (j = 0; j < N; j++) {
          if (i < 3 && (i + j) %2 != 0) {
            M[i][j] ='B';
          }
          if (i > 4 && (i+j) %2 !=0)
            M[i][j] ='P';
           printf("[%c]",M[i][j]);
          }
        printf("\n");
     }
}
char **initialize () {
  /* alocação das linhas e colunas */
  char **M;
  int i,j;
  M = (char **)calloc(N, sizeof(char *));
    for(i = 0; i < N; i++)
        M[i] = (char *)calloc(N, sizeof(char));

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            M[i][j]=' ';//espaco em branco
    return M;
}
int step (char **M, int linha,int coluna,int linhadest,int coldest, char jogador) {

  if ((linha+coluna)%2!=0) {
    if((jogador=='B' && linhadest < linha)||(jogador=='P' && linha>linhadest))
  } 
      return 1;
}
void game () {
  char **tabuleiro;
  int linha, coluna,lind,cold;
  char jogador = 'P';
  int jogoativo = -1;
  
  tabuleiro = initialize();
  /* laço jogo da dama */
  while (jogoativo==-1) {  
    printmatriz(tabuleiro);
    printf("\nBem vindo ao jogo!!\nO jogador %c começa! vamos lá P digite as coordenadas e faça seu movimento!!\nBom jogo!!\n",jogador);
    scanf("%d %d", &linha, &coluna);
    printf("Destino: ");
    scanf("%d %d", &lind, &cold);
    // se não posso prosseguir
    if ( !step(tabuleiro,linha, coluna, lind, cold, jogador)) {
      printf("Jogada Invalida!\n");
      continue;
    }

    jogoativo = status(tabuleiro);
     
    //alternancia de jogador
    if (jogador == 'P')
        jogador = 'B';
      else jogador = 'P';
    }
    printf("\n%s\n", msg[jogoativo]);
}  

void main () {

  game();
}  
