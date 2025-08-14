/*--------------------------------------------------------------
∗ UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho   : Atividade 2
∗ Disciplina : Programacao
∗ Professor  : Luiz Eduardo da Silva
∗ Aluno      : Bruno Martins Cordeiro
* Matricúla  : 2020.1.08.006
∗ Data       : 30/07/2021
∗-------------------------------------------------------------*/

#include <stdio.h>

int piso[20][20];
int direcao;
int caneta;
int linha, coluna;
char comando;
int operando;

int main (void)
{
   int i, j;
   for(i = 0; i < 20; i++)
     for (j = 0; j < 20; j++)
       piso[i][j] = '.';
    direcao = 1;
    caneta = 0;
    linha = 0;
    coluna = 0;
    do {
     scanf("%c", &comando);
        if(comando == 'p'){
            for(i = 0; i < 20; i++)
            {
                for(j = 0; j < 20; j++)
                {
                    printf(" %c ", piso[i][j]);
                }
            printf("\n");
            }
        }
        if (comando == 'd')
        { 
            caneta = 1;
        }
        if (comando == 'u')
        { 
            caneta = 0;
        }
        if (comando == 'r')
        { 
            direcao++;
        }
        if (direcao == 4)
        {
            direcao = 0;
        }
        if (comando == 'l')
        {
            direcao--;
                if (direcao < 0)
                {
                    direcao = 3;
                }
        }
        if (comando == 'w')
        { 
            scanf("%d", &operando);
                operando--; 
        
            if(direcao == 0)
            {
                for (i = 0; i != operando; i++, linha--)
                    if (caneta == 1)
        
                    {
                        piso[linha][coluna] = '*';
                    }
            }
        if (direcao == 1)
        { 
            for (i = 0; i != operando; i++, coluna++)
                if (caneta == 1)
                {
                    piso[linha][coluna] = '*';
                }
        }
        if (direcao == 2)
        { 
            for (i = 0; i != operando; i++, linha++)
                if (caneta == 1)
                {
                    piso[linha][coluna] = '*'; 
                }
        }   
        if (direcao == 3)
        {
            for (i = 0; i != operando; i++, coluna--)
                if (caneta == 1)
                {
                    piso[linha][coluna] = '*';
                }
        }
     }
    } while (comando != 'e');  
     return 0;  
}