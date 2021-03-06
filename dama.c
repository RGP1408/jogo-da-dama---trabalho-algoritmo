/*Trabalho de Algoritmo
Alunos: Renan Gonçalves Pereira
        Vinicius Trindade

OBSERVAÇÃO IMPORTANTE:
QUANDO VIRAR DAMA,SUA PEÇA NÃO IRÁ MUDAR NA PRÓXIMA RODADA, SELECIONE A PEÇA QUE ESTÁ NA CASA E FAÇA UM MOVIMENTO, A JOGADA IRÁ SE REPETIR E AGORA SELECIONE A DAMA!
EX: PEÇA B CHEGOU EM 7 0, NA PROXIMA RODADA ELA AINDA ESTARÁ COMO B, ENTÃO SELECIONE B E FAÇA UM MOVIMENTO,A JOGADA IRÁ SE REPETIR E A PEÇA VIRARÁ X, AGORA SELECIONE X E SE MOVIMENTE!

JOGO DA DAMA
Regras;
CONDIÇÔES
-- Jogadas somente válidas para casas onde a soma da linha e coluna sejam impares.
-- As jogadas são alternadas, ex : primeiro jogador B ou Y, depois jogador P ou Y.
-- Você não pode digitar uma coordenada que não esteja no tabuleiro.


PARA ANDAR
peça normal;
você só pode andar uma casa, apenas para frente.
ex: peça Brancas(B) somente para baixo do tabuleiro e peças Pretas(P) somente para cima do tabuleiro.

dama;
Dama do jogador B = ( X )
Dama do jogador P = ( Y )
*Para virar Dama, caso seja o jogador B, virará dama quando chegar na linha de origem de P , caso seja o jogador P, virará dama quando chegar na linha de origem de B.
*A peça só irá se transformar em X ou Y quando você movimenta-lá!
*você pode se mover livremente pelas diagonais, desde que não tenha uma peça do seu time no caminho, e não pode pular duas peças inimigas.


PARA COMER
peça normal e dama;
você come a peça adversária desde que a casa de destino esteja vazia.
só pode comer uma vez por rodada, para frente e para trás.

PARA JOGAR
Você deve digitar a peça que irá jogar, o sistema mostrará a vez de quem jogar, caso digite uma peça errada será mostrado uma mensagem de erro e pedirá para digitar novamente.
depois de selicionar a peça digite a coordenada dela,e seu destino.

PARA VITÒRIA
o jogador que comer todas as peças será declarado vencedor! */

#include <stdio.h>
#include <stdlib.h>
#define N 8
/* preenche o tabuleiro com peças e printa */
void printMatriz(char **M){
    int i,j;
    printf("\n   0  1  2  3  4  5  6  7\n");

    for (i = 0; i < N; i++)
    {
      printf("%d ",i);
        for(j = 0; j < N; j++)
        {
            printf("[%c]",M[i][j]);
        }
        printf(" %d",i);
        printf("\n");
    }
    printf("   0  1  2  3  4  5  6  7\n");
}
char **initialize () {
  /* alocação das linhas e colunas */
  char **M;
  int i,j;
  M = (char **)calloc(N, sizeof(char *));
    for(i = 0; i < N; i++)
        M[i] = (char *)calloc(N, sizeof(char));

    for(i = 0; i < N; i++)
      {
        for(j = 0; j < N; j++)
        {
          if (i == 0 || i == 2)
          {
            if(j%2 == 0)
            {
              M[i][j]=' ';
            }
            else
            {
              M[i][j]='B';
            }
          }
          else if (i == 1)
          {
            if (j%2 == 0)
            {
              M[i][j]='B';
            }
             else
            {
              M[i][j]=' ';
            }
          }
          if (i == 5 || i == 7)
          {
            if(j%2 == 0)
            {
              M[i][j]='P';
            }
            else
            {
              M[i][j]=' ';
            }
          }
          else if (i == 6)
          {
            if (j%2 == 0)
            {
              M[i][j]=' ';
            }
             else
            {
              M[i][j]='P';
            }
          }
          if (i == 4 || i == 3)
          {
            M[i][j]=' ';
          }
       }

    }
    return M;
}
/*condições para a realização de jogadas e condições para poder comer */
int step (char **M, int linha,int coluna,int linhadest,int coldest, char jogador, char damaB, char damaP) {
        int i,j;


        //para mover não deve retornar 0
        if (linha < 0 || linhadest < 0 ||
            coluna < 0 || coldest < 0 ||
            linha >= N || linhadest >= N ||
            coluna >= N || coldest >= N)
          {
            return 0;
          }
        if ((linha+coluna)%2 == 0 || (linhadest+coldest)%2 == 0)
          {
         return 0;
          }

    if (jogador == 'B')
        {
        // Para B poder virar Dama
        for(i = 0; i < N; i++)
          {
            for (j = 0;j < N; j++)
            {
             if (M[7][0] == 'B')
             {
             M[7][0] = damaB;
             return 0;
             }
             if (M[7][2] == 'B')
             {
             M[7][2] = damaB;
             return 0;
             }
             if (M[7][4] == 'B')
             {
             M[7][4] = damaB;
             return 0;
             }
             if (M[7][6] == 'B')
             {
             M[7][6] = damaB;
             return 0;
             }
          }
        }

          //movimentos não permitidos para B
          if (linhadest == linha ||
              M[linha][coluna] == 'P' ||
              M[linha][coluna] == 'Y' ||
              M[linhadest][coldest] !=' ')
          {
            return 0;
          } //lembrando que não pode andar na mesma linha!!
          if (linhadest == linha+1)
          {
            if (coldest > coluna+1)
            {
              return 0;
            }
            if (coldest < coluna-1)
            {
              return 0;
            }
          }
        if(linhadest == linha+2)//condições de B para poder comer para frente
          {
          if  ((M[linha+2][coluna+2] ==' ' && M[linha+1][coluna+1] =='P') ||
               (M[linha+2][coluna+2] ==' ' && M[linha+1][coluna+1] =='Y'))
            {
              M[linha][coluna] =' ';
              M[linha+1][coluna+1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
            }
           if ((M[linha+2][coluna-2] ==' ' && M[linha+1][coluna-1] =='P') ||
               (M[linha+2][coluna-2] ==' ' && M[linha+1][coluna-1] =='Y'))
             {
              M[linha][coluna] =' ';
              M[linha+1][coluna-1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
             }
          }
          if (linhadest == linha-2)//para comer para trás
          {
            if ((M[linha-1][coluna+1] =='P' && M[linha-2][coluna+2] ==' ') ||
                (M[linha-1][coluna+1] =='Y' && M[linha-2][coluna+2] ==' '))
            {
              M[linha][coluna] =' ';
              M[linha-1][coluna+1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
            }
            if ((M[linha-1][coluna-1] =='P' && M[linha-2][coluna-2] == ' ') ||
                (M[linha-1][coluna+1] =='Y' && M[linha-2][coluna-2] ==' '))
            {
              M[linha][coluna] = ' ';
              M[linha-1][coluna-1] =' ';
              M[linhadest][coldest] ='B';
              return 1;
            }
          }

          if (linhadest > linha+1 && !linha+2)
          {
            return 0;
          }
          if (linhadest < linha && !linha-2)
          {
            return 0;
          }
      }
        if (jogador == 'P')
        {//Para P virar Dama
          for(i = 0; i < N; i++)
          {
            for (j = 0;j < N; j++)
            {
             if (M[0][1] == 'P')
             {
             M[0][1] = damaP;
             return 0;
             }
             if (M[0][3] == 'P')
             {
             M[0][3] = damaP;
             return 0;
             }
             if (M[0][5] == 'P')
             {
             M[0][5] = damaP;
             return 0;
             }
             if (M[0][7] == 'P')
             {
             M[0][7] = damaP;
             return 0;
             }
          }
        }

          //movimentos não permitidos por P
          if( linhadest==linha ||
              M[linha][coluna] == 'B' ||
              M[linha][coluna] == 'X' ||
              M[linhadest][coldest] !=' ')
          {
            return 0;
          }
          if (linhadest == linha-1)
          {
            if (coldest > coluna+1)
            {
              return 0;
            }
            if (coldest < coluna-1)
            {
              return 0;
            }
          }
          if(linhadest == linha-2)//condições de P para poder comer
          {
            if ((M[linha-2][coluna+2] ==' ' && M[linha-1][coluna+1] =='B') ||
                (M[linha-2][coluna+2] ==' ' && M[linha-1][coluna+1] =='X'))
            {
              M[linha][coluna] =' ';
              M[linha-1][coluna+1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
            }
            if ((M[linha-2][coluna-2] ==' ' && M[linha-1][coluna-1] =='B') ||
                (M[linha-2][coluna-2] ==' ' && M[linha-1][coluna-1] =='X'))
             {
              M[linha][coluna] =' ';
              M[linha-1][coluna-1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
             }
          }
          if (linhadest == linha+2)//para comer para trás,pela direita e esquerda
          {
            if ((M[linha+1][coluna+1] =='B' && M[linha+2][coluna+2] ==' ') ||
                (M[linha+1][coluna+1] =='X' && M[linha+2][coluna+2] ==' '))
            {
              M[linha][coluna] =' ';
              M[linha+1][coluna+1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
            }
            if ((M[linha+1][coluna-1] =='B' && M[linha+2][coluna-2] == ' ') ||
                (M[linha+1][coluna-1] =='X' && M[linha+2][coluna-2] == ' '))
            {
              M[linha][coluna] = ' ';
              M[linha+1][coluna-1] =' ';
              M[linhadest][coldest] ='P';
              return 1;
            }
          }
          if (linhadest < linha-1 && !linha-2)
          {
            return 0;
          }
          if (linhadest > linha && !linha+2)
          {
            return 0;
          }
         }

         /* Para formar a Dama, jogador deve chegar na linha de origem do adversário.
          A Dama se move para qualquer lado e quantas casas quiser desde que não haja
          uma peça do mesmo time no caminho e nem duas peças inimigas consecutivas,
          ela só come uma vez. */

        if (jogador == 'X')
        {
          //movimentos não permitidos para Dama X
             if  (linhadest == linha ||
                   coldest == coluna ||
                  M[linha][coluna] !='X' ||
                 (M[linhadest][coldest] != ' '))
                {
                  return 0;
                }

            if (linhadest > linha)//subindo as linhas ou de B para baixo!
            {
              if (coldest > coluna)//pela direita
              {
                if(coluna-linha != coldest-linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                int contagemp = 0;
                int contagemy = 0;
                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                      if (M[i][j] == 'P')
                       {
                        contagemp++;
                       }
                      if (M[i][j] == 'Y')
                       {
                        contagemy++;
                       }
                    }
                  }
                   for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                        if(M[linhadest][coldest] == ' ')
                        {
                        if((contagemp > 1 || contagemy > 1) || (contagemp == 1 && contagemy == 1))
                        {
                          printf("\nVocê não pode sobrepor mais de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'B' || M[i][j] == 'X')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                }
            }

              if (coldest < coluna)//pela esquerda
                 {
                    if(coluna+linha != coldest+linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                  int contagemp = 0;
                  int contagemy = 0;

                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                      if (M[i][j] == 'P')
                      {
                        contagemp++;
                      }
                      if(M[i][j] == 'Y')
                      {
                        contagemy++;
                      }
                    }
                  }
                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                     if(M[linhadest][coldest] == ' ')
                      {
                        if((contagemp > 1 || contagemy > 1) || (contagemp == 1 && contagemy == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'B' || M[i][j] == 'X')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }
                }
            }
            if (linhadest < linha)//descendo as linhas ou de P para cima!
            {
              if (coldest > coluna)//pela direita
              {
                  if(coluna+linha != coldest+linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                int contagemp = 0;
                int contagemy = 0;
                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                      if (M[i][j] == 'P')
                       {
                        contagemp++;
                       }
                      if (M[linha-1][coluna+1] == 'Y')
                       {
                        contagemy++;
                       }
                    }
                  }
                  if((contagemp > 1 || contagemy > 1) || (contagemp == 1 && contagemy == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                        }
                   for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                        if(M[linhadest][coldest] == ' ')
                        {
                         if (M[i][j] == 'B' || M[i][j] == 'X')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }

                      M[i][j] = ' ';
                      }
                    }
                }
             }

          if (coldest < coluna)//pela esquerda
            {
                     if(linha-coluna != linhadest-coldest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                  }
                  int contagemp = 0;
                  int contagemy = 0;

                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                      if (M[i][j] == 'P')
                      {
                        contagemp++;
                      }
                      if(M[i][j] == 'Y')
                      {
                        contagemy++;
                      }
                    }
                  }
                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                     if(M[linhadest][coldest] == ' ')
                      {
                        if((contagemp > 1 || contagemy > 1) || (contagemp == 1 && contagemy == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'B' || M[i][j] == 'X')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }
                 }
            }
        }

        if (jogador == 'Y')
        {

          //movimentos não permitidos para Dama Y
             if (linhadest == linha ||
                  M[linha][coluna] !='Y' ||
                 (M[linhadest][coldest] != ' '))
                {
                  return 0;
                }

            if (linhadest > linha)//subindo as linhas ou de B para baixo!
            {
              if (coldest > coluna)//pela direita
              {
                  if(coluna-linha != coldest-linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                int contagemb = 0;
                int contagemx = 0;
                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                      if (M[i][j] == 'B')
                       {
                        contagemb++;
                       }
                      if (M[i][j] == 'X')
                       {
                        contagemx++;
                       }
                    }
                  }
                   for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                        if((contagemb > 1 || contagemx > 1) || (contagemb == 1 && contagemx == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'P' || M[i][j] == 'Y')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }

              if (coldest < coluna)//pela esquerda
                 {
                     if(coluna+linha != coldest+linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                  int contagemb = 0;
                  int contagemx = 0;

                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                      if (M[i][j] == 'B')
                      {
                        contagemb++;
                      }
                      if(M[i][j] == 'X')
                      {
                        contagemx++;
                      }
                    }
                  }
                  for (i = linha+1; i < linhadest; i++)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                     if(M[linhadest][coldest] == ' ')
                      {
                        if((contagemb > 1 || contagemx > 1) || (contagemb == 1 && contagemx == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'P' || M[i][j] == 'Y')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }
                }
            }
            if (linhadest < linha)//descendo as linhas ou de P para cima!
            {
              if (coldest > coluna)//pela direita
              {
                  if(coluna+linha != coldest+linhadest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                int contagemb = 0;
                int contagemx = 0;
                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                      if (M[i][j] == 'B')
                       {
                        contagemb++;
                       }
                      if (M[i][j] == 'X')
                       {
                        contagemx++;
                       }
                    }
                  }
                   for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna+1; j < coldest; j++)
                    {
                        if((contagemb > 1 || contagemx > 1) || (contagemb == 1 && contagemx == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                        }
                         if (M[i][j] == 'P' || M[i][j] == 'Y')
                         {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }

              if (coldest < coluna)//pela esquerda
                 {
                     if(linha-coluna != linhadest-coldest){
                    printf("\nVocê só pode se movimentar pela diagonal\n");
                    return 0;
                }
                  int contagemb = 0;
                  int contagemx = 0;

                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                      if (M[i][j] == 'B')
                      {
                        contagemb++;
                      }
                      if(M[i][j] == 'X')
                      {
                        contagemx++;
                      }
                    }
                  }
                  for (i = linha-1; i > linhadest; i--)
                  {
                    for (j = coluna-1; j > coldest; j--)
                    {
                     if(M[linhadest][coldest] == ' ')
                      {
                        if((contagemb > 1 || contagemx > 1) || (contagemb == 1 && contagemx == 1))
                        {
                          printf("\nVocê não pode sobrepor mais  de uma peça");
                          return 0;
                          break;
                         }
                        if (M[i][j] == 'P' || M[i][j] == 'Y')
                        {
                          printf("\nVocê não pode sobrepor peças do seu time");
                          return 0;
                         }
                      M[i][j] = ' ';
                      }
                    }
                  }
                 }
            }
        }
     M[linha][coluna] = ' ';
     M[linhadest][coldest] = jogador;
        return 1;
       }
int statusGamer(char **M, char jogador, char dama) {
  int i,j;
  int pecas = 0,pecadama = 0,total;

  for (i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      if (M[i][j] == jogador)
      {
        pecas++;
      }
      if (M[i][j] == dama)
      {
        pecadama++;
      }
    }
  }
  total = pecas + pecadama;

  if (total == 0)
  {
    return 1;
  }
  if (total < 12)
  {
    return 0;
  }
}
int status(char **M) {
  /*condições para vitória
 (1) - vitoria de B
 (2) - vitoria de P
 (-1) - segue jogo! */
  int i,j;
  if (statusGamer(M,'P','Y') == 1)
  {
   return 1;
  }
  if (statusGamer(M,'B','X') == 1)
  {
  return 2;
  }
  //verifica se pode continuar
  for (i = 0; i < N; i++)
  {
   for (i = j; j < N; j++)
   {
    if (M[i][j] !=' ')
      return -1;
   }
  }
}
void game () {
  char **tabuleiro;
  int linha, coluna,lind,cold;
  char jogador = 'B';
  char damaB = 'X';
  char damaP = 'Y';
  char peca;
  int jogoativo = -1;

  tabuleiro = initialize();

    printf("\nBem vindo ao jogo da Dama!!\n");
    printf("Jogador B começa o jogo!\n");
    while (jogoativo==-1)
    {
      printMatriz(tabuleiro);
      if (jogador == 'B' || jogador == 'X')
      {
        printf("\nCaro jogador B!!\nConfirme sua peça ou escolha a Dama caso a tenha.\nPeça: ");
        scanf("\n%c", &peca);
        if (peca != 'B' && peca != damaB)
        {
          do
          {
          printf("\nPEÇA ERRADA!!\nNão é a vez desse jogador ou peça não existe! digite novamente.\nPeça: ");
          scanf("\n%c", &peca);
          } while (peca != 'B' && peca != damaB);
         }
        if (peca == 'B')
        {
        printf("\nVamos jogador B!! faça seus movimentos.\n");
        }
        if (peca == damaB)
        {
          printf("\nWoW!uma Dama! Vamos X, mande ver!!\n");
        }
        jogador = peca;
      }


      if (jogador == 'P' || jogador == 'Y')
        {
        printf("\nCaro jogador P!!\nConfirme sua peça ou escolha a Dama caso a tenha\nPeça: ");
        scanf("\n%c", &peca);
        if (peca != 'P' && peca != damaP)
        {
          do {
        printf("\nPEÇA ERRADA!!\nNão é a vez desse jogador ou peça não existe! digite novamente.\nPeça: ");
        scanf("\n%c", &peca);
          } while(peca !='P' && peca != damaP);
        }

        if (peca == 'P')
        {
          printf("\nVamos jogador P!! faça seus movimentos.\n");
        }
        if (peca == damaP)
        {
          printf("\nWoW!uma Dama! Vamos Y, mande ver!!\n");
        }
        jogador = peca;
      }

      printf("Origem: ");
      scanf("%d %d", &linha, &coluna);
      printf("Destino: ");
      scanf("%d %d", &lind, &cold);

      // caso a jogada seja errada
      if (!step(tabuleiro,linha, coluna, lind, cold, jogador, damaB, damaP)) {
        printf("\nJogada Invalida!jogue novamente\n");
      continue;
    }

    jogoativo = status(tabuleiro);
    //alternancia de jogador
    if (jogador == 'B' || jogador == 'X')
        jogador = 'P';
    else  jogador = 'B';

    }
    if (jogoativo == 1)
    printf("\nFIM DE JOGO!\nParabéns pela vitória jogador B\n");

    if (jogoativo == 2)
    printf("\nFIM DE JOGO!\nParabéns pela vitória jogador P\n");

   }
int main (void) {

  game();
}
