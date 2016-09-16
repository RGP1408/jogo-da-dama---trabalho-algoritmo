#include <stdio.h>
#include <stdlib.h>
#define N 8
/* preenche o tabuleiro com peças e printa */
void printmatriz (char **M) {
    int i,j;

    for (i = 0; i < N; i++) {
      for(j = 0; j < N; j++) {
       if (i < 3 && (i + j) %2 != 0) {
            M[i][j] ='B';
          }
       if (i > 4 && (i+j) %2 !=0) {
            M[i][j] ='P';
          }
        }
      }
     printf("\n   0  1  2  3  4  5  6  7 \n");

     for (i = 0; i < N; i++) {
      printf("%d ", i);
        for (j = 0; j < N; j++) {
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
/*condições para a não realização de jogadas e condições para poder comer */
int step (char **M, int linha,int coluna,int linhadest,int coldest, char jogador) {
  int i,j;
   // condições para não andar 
   if ((linha+coluna)%2 == 0)
   { 
     if ((jogador == 'P' && linha < linhadest) || (jogador == 'B' && linha > linhadest))
       { 
        //condições para comer
        if(coldest-1 != coluna || coldest+1 != coluna)
        { 
                        if(coluna == coldest-1)
                        {
                        M[linhadest][coldest] = jogador;
                        M[linha][coluna] =' ';
                        }
                        if(coldest == coluna+1)
                        {
                        M[linhadest][coldest] = jogador;
                        M[linha][coluna] =' ';
                        }
        }

        if(M[linha+1][coluna+1]==jogador)
        {
                        if(coluna+2==coldest)
                        {
                                 M[linhadest][coldest] = jogador;
                                 M[linha][coluna] = ' ';
                                 M[linha+1][coluna+1]=' ';
                        }
        }
        
        if(M[linha+1][coluna-1]==jogador)
        {
                        if(coluna-2==coldest)
                        {
                                 M[linhadest][coldest] = jogador;
                                 M[linha][coluna] =' ';
                                 M[linha+1][coluna-1]=' ';
                        }
        }
  
        if(M[linha-1][coluna+1] == jogador)
        {
                        if(coluna+2==coluna)
                        {
                                 M[linhadest][coldest] = jogador;
                                 M[linha][coluna] = ' ';
                                 M[linha-1][coluna+1]=' ';
                        }
        }
        
        if(M[linha-1][coluna-1]== jogador)
        {
                        if(coluna-2==coldest)
                        {
                                M[linhadest][coldest] = jogador;
                                M[linha][coluna] =' ';
                                M[linha-1][coluna-1]=' ';
                                
                        }
        }
       }
        
        return 0; 
          }
     M[linha][coluna] = ' '; 
     M[linhadest][coldest] = jogador;   
        return 1;
  }
  int statusGamer(char **M,char jogador) {

  }
  int status (char **M) {
  int i,j;
      //verifica se tem espaço livre 
      for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(M[i][j]==' ')
              return -1;
} 
void game () {
  char **tabuleiro;
  int linha, coluna,lind,cold;
  char jogador = 'P';
  int jogoativo = -1;
  
  tabuleiro = initialize();

    printf("\nBem vindo ao jogo!!\n");
    while (jogoativo==-1) 
    {
      printmatriz(tabuleiro);
      if (jogador == 'P')
      printf("\nVamos jogador P,faça seus movimentos\n");
      if (jogador == 'B') 
      printf("\nVamos jogador B,faça seus movimentos\n");
      scanf("%d %d", &linha, &coluna);
      printf("Destino: ");
      scanf("%d %d", &lind, &cold);
      // caso a jogada seja errada
      if (!step(tabuleiro,linha, coluna, lind, cold, jogador)) {     
        printf("Jogada Invalida!jogue novamente\n");
      continue;
    }

    jogoativo = status(tabuleiro);

    //alternancia de jogador
    if (jogador == 'P')
        jogador = 'B';
      else jogador = 'P';
    }
   }   
void main () {

  game();
}  
