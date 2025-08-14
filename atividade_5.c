/*--------------------------------------------------------------
∗ UNIFAL − Universidade Federal de Alfenas.
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho   : Atividade 5
∗ Disciplina : Programacao
∗ Professor  : Luiz Eduardo da Silva
∗ Aluno      : Bruno Martins Cordeiro
* Matricúla  : 2020.1.08.006
∗ Data       : 08/09/2021
∗-------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char isbn_dv (char *isbn) {
    int s1[10], s2[10], i, j, isbn_int[10];
    char dv;
    for(i = 0; i < 9; i++){
        isbn_int[i] = isbn[i] - '0';
    }
    s1[0] = isbn_int[0];
    for(i = 1; i < 10; i++){
        s1[i] = s1[i - 1] + isbn_int[i];
    }
    s2[0] = s1[0];
    for(i = 1; i < 10; i++){
        s2[i] = s2[i - 1] + s1[i];
    }
    s2[9] = 12;
    for(j = 0; j < 11 && s2[9] % 11 != 0; j++){
        s1[9] = s1[8] + j;
        s2[9] = s2[8] + s1[9];
    }
    j = j - 1;
    if(j == 10){
        dv = 'X';
    }
    else if(j >= 0 && j <= 9){
        dv = j + '0';
    }
    return dv;
}

int main (void) {
    char isbn[12];
    do{
        fgets(isbn, 11, stdin);
        isbn[strlen(isbn) - 1] = '\0';
        if(strcmp(isbn, "000000000")){
            printf("%s-%c\n", isbn, isbn_dv(isbn));
        }
    } while(strcmp(isbn, "000000000"));
    return 0;
}