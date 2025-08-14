/*--------------------------------------------------------------
∗ UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho   : Atividade 4
∗ Disciplina : Programacao
∗ Professor  : Luiz Eduardo da Silva
∗ Aluno      : Bruno Martins Cordeiro
* Matricúla  : 2020.1.08.006
∗ Data       : 26/08/2021
∗-------------------------------------------------------------*/

#include <stdio.h>

void leSudoku(int n, int sudoku[16][16])
{
    char s[2];
    int i, j, dim = n * n;
    for(i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
        {
            scanf("%s", s);
            if(s[0] >= '1' && s[0] <= '9')
                sudoku[i][j] = s[0] - '0';
            if(s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }
}

void imprimeLinha(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        printf("+");
        for(j = 0; j < n; j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16])
{
    int i, j, dim = n * n;
    imprimeLinha(n);
    for(i = 0; i < dim; i++)
    {
        printf("|");
        for(j = 0; j < dim; j++)
        {
            int num = sudoku[i][j];
            if(num <= 9)
                printf("%2d ", num);
            else
                printf("%2c ", num - 10 + 'A');
            if((j + 1) % n == 0)
                printf("|");
        }
        printf("\n");
        if((i + 1) % n == 0)
            imprimeLinha(n);
    }
}

/*----------------------------------------------------------
 * Funcao que testa uma solucao do Sudoku
 * Parametros:
 *      n = dimensao das regioes
 *      sudoku -> jogo preenchido
 *      lin -> linha do erro (se houver)
 *      col -> coluna do erro(se houver)
 *  Retorna:
 *      1 se a matriz é uma solucao do sudoku
 *      0 caso contrario, modificando os parametros
 *          lin e col para indicar a linha e coluna onde
 *          foi detectado o problema
 * -------------------------------------------------------*/

int sudokuOk(int n, int sudoku[16][16], int *lin, int *col)
{
    int i, j, k, num = 0, dim = n * n, a = 0, b = 0, l = 1;
    // verificação por região
    while (a < dim){
        while (b < dim){
            while (l <= dim){ //l é o numero dentro do sudoku entre 1 e dim
                for (i = a; i < n + a; i++){ //i recebe valor inicial do quadrante que ele vai analisar
                    for (j = b; j < n + b; j++){
                        if (sudoku[i][j] == l)
                            num++;
                        if (num > 1){
                            *lin = i + 1;
                            *col = j + 1;
                            return 0;
                        }
                    }
                }
                num = 0;
                l++; //contagem reinicia e então se analisa o proximo numero
            }
            l = 0; //reinicia os numeros a serem comparados no proximo quadrante
            b = n + b; // b é o quadrante das colunas (avança para a direita)
        }
        b = 0; // volta para a coluna da esquerda
        a = n + a; // a é o quadrante das linhas(desce), e vai repetindo até o final das colunas novamente
    }
    // verificação por linha
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            for (k = j + 1; k < dim; k++){
                if (sudoku[i][j] == sudoku[i][k]){
                    *lin = i + 1;
                    *col = k + 1;
                    return 0;
                }
            }
        }
    }
    // verificação por coluna
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i++){
            for (k = i + 1; k < dim; k++){
                if (sudoku[i][j] == sudoku[k][j]){
                    *lin = k + 1;
                    *col = j + 1;
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d", &n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if(ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posicao (%d, %d)\n", nlin, ncol);
    return 0;
}