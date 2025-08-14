
/*--------------------------------------------------------------
∗ UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho   : Atividade 3
∗ Disciplina : Programacao
∗ Professor  : Luiz Eduardo da Silva
∗ Aluno      : Bruno Martins Cordeiro
* Matricúla  : 2020.1.08.006
∗ Data       : 02/08/2021
∗-------------------------------------------------------------*/

#include <stdio.h>

/*--------------------------------------------------------------
* Calcula o comprimento do string
* Recebe o string (s)
* Retorna o comprimento de s
∗-------------------------------------------------------------*/
int strlength(char *s)
{
    int i;
    for(i = 0; s[i]; i++)
        ;
    return i;
}

/*--------------------------------------------------------------
* Le um string
* Parametros:
*   s = string a ser lido
*   len = tamanho maximo da leitura (contar o \0 e \n).
∗-------------------------------------------------------------*/
 void strread (char *s, int len)
 {
    fgets(s, len, stdin);
    s[strlength(s) - 1] = '\0';
 }

 /*--------------------------------------------------------------
 * Mostra os elementos do vetor string em modo texto
 * Parametros:
 *      s = string
 *      name = nome do string
 ∗-------------------------------------------------------------*/
 void strshow(char *s, char *name)
 {
    int i;
    for(i = 0; s[i]; i++)
        printf("%3d ", i);
    printf("%3d\n", i);
    for(i = 0; s[i]; i++)
        printf ("+---");
    printf("+---+\n");
    for(i = 0; s[i]; i++)
        printf("| %c ", s[i]);
    printf("| \\0| %s\n", name);
    for(i = 0; s[i]; i++)
        printf("+---");
    printf("+---+\n");
 }

/*--------------------------------------------------------------
* Insere um substring num string na posicao especificada
* Parametros:
*   pos = posicao onde inserir (0 e a primeira posicao)
*   sub = substring que seria inserido em s
*   s   = string onde inserir sub
∗-------------------------------------------------------------*/
void strinsert(int pos, char *sub, char *s)
{
    int i, j, k;
    char aux[70];
    if(strlength(s) < pos)
    {
        for(i = strlength(s), j = 0; sub[j] != '\0'; i++, j++)
            s[i] = sub[j];
        s[i] = '\0';
    }
    if(strlength(s) >= pos)
    {
        for (i = pos, j = 0; s[i] != '\0'; i++, j++)
            aux[j] = s[i];
        aux[j] = '\0';
        for (j = 0, i = pos; sub[j] != '\0'; j++, i++)
            s[i] = sub[j];
        for (k = 0; aux[k] != '\0'; k++, i++)
            s[i] = aux[k];
        s[i] = '\0';
    }
}

/*--------------------------------------------------------------
* transforma um literal em inteiro
* o literal pode ter sinal(+ ou -) seguido de digitos
∗-------------------------------------------------------------*/
int str2int(char *s)
{
    
}

int main(void)
{
    char string[100];
    char substring[100];
    char posstr[4];
    int posicao;
    do
    {
        scanf("%d", &posicao);
        strread(posstr, 4);
        //posicao = str2int(posstr);
        printf("\nPosicao = %d\n", posicao);
        if (posicao >= 0)
        {
            strread(substring, 30);
            strshow(substring, "substr.");
            strread(string, 70);
            strshow(string, "string");
            strinsert(posicao, substring, string);
            strshow(string, "result.");
        }
    }while (posicao >= 0);  
}