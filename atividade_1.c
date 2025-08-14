/*---------------------------------------------------------------
 ∗ UNIFAL − Universidade Federal de Alfenas.
 ∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
 ∗ Trabalho   : Atividade1
 ∗ Disciplina : Programacao
 ∗ Professor  : Luiz Eduardo da Silva
 ∗ Aluno      : Bruno Martins Cordeiro
 * Matricúla  : 2020.1.08.006
 ∗ Data       : 12/07/2021
 ∗------------------------------------------------------------*/

#include <stdio.h>

int main (void)
{
    int codigo, idade, maiorIdade = 0, menorIdade = 10000, IDmaior, IDmenor;
    int somaIdades = 0, numPessoas = 0, numPessoasM = 0, numPessoasF = 0, numPessoasO = 0;
    char sexo;
    float mediaIdade = 0;
    do {
        scanf("%d %c %d", &codigo, &sexo, &idade);
        if (codigo != 0 && sexo != 'x' && idade != 0) {
            somaIdades = somaIdades + idade;
            numPessoas = numPessoas + 1;
            mediaIdade = (float)somaIdades / numPessoas;
            if (menorIdade >= idade){
                menorIdade = idade;
                IDmenor = codigo;
            }
            if (maiorIdade <= idade){
                maiorIdade = idade;
                IDmaior = codigo;
            }
            if (sexo == 'm' || sexo == 'M') {
                numPessoasM = numPessoasM + 1;
            }
            else
                if (sexo == 'f' || sexo == 'F') {
                    numPessoasF = numPessoasF + 1;
                }
                else 
                    numPessoasO = numPessoasO + 1;
        }
    } while (codigo != 0 && sexo != 'x' && idade != 0);
    printf ("+-------------------+--------+\n");
    printf ("| Soma das idades   |%7d |\n", somaIdades);
    printf ("| Total de pesssoas |%7d |\n", numPessoas);
    printf ("| Media de idades   |%7.1f |\n", mediaIdade);
    printf ("| Homens            |%7d |\n", numPessoasM);
    printf ("| Mulheres          |%7d |\n", numPessoasF);
    printf ("| Outros            |%7d |\n", numPessoasO);
    printf ("| Maior idade       |%7d |\n", maiorIdade);
    printf ("| ID do mais velho  |%7d |\n", IDmaior);
    printf ("| Menor idade       |%7d |\n", menorIdade);
    printf ("| ID do mais novo   |%7d |\n", IDmenor);
    printf ("+-------------------+--------+\n");
    return 0;
}
