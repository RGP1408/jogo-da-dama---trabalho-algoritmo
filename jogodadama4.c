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
  if(jogador == 'P') 
  {
    if ((linha+coluna)%2!=0) 
    { 
     if((linhadest < linha)||
   
      return 1;
  }
}
void game () {
  char **tabuleiro;
  int linha, coluna,lind,cold;
  char jogador = 'P';
  int jogoativo = -1;
  
  tabuleiro = initialize();
  /* laço jogo da dama */
     
    printmatriz(tabuleiro);
    printf("\nBem vindo ao jogo!!\n");
    while (jogoativo==-1) {
      if (jogador == 'P')
        printf("Vamos jogador P,faça seus movimentos\n");
      if (jogador == 'B') 
        printf("Vamos jogador B,faça seus movimentos\n");
    scanf("%d %d", &linha, &coluna);
    printf("Destino: ");
    scanf("%d %d", &lind, &cold);
    step(tabuleiro,linha, coluna, lind, cold, jogador);
    // se não posso prosseguir
    if ( !step(tabuleiro,linha, coluna, lind, cold, jogador)) {
      printf("Jogada Invalida!\n");
      continue;
    }
    //alternancia de jogador
    if (jogador == 'P')
        jogador = 'B';
      else jogador = 'P';
      printmatriz(tabuleiro);
    }
    
}  

void main () {

  game();
}  
