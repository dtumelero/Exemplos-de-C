/*
Exemplo de ponteiros em linguagem C
*/

#include <stdio.h>

int main()
{
	int bergamota;	//variável
	int *tangerina;	//* indica que é um ponteiro
	int *mexirica;	//* indica que é um ponteiro

	tangerina = &bergamota;	//estou APONTANDO que tangerina é a mesma coisa que bergamota
	mexirica  = &bergamota;	//o & é de endereço, apontando que mexirica é um ponteiro (""atalho"") para bergamota

	bergamota = 10;	//quando se atribui um valor (um número) para bergamota...

	// ...tangerina e mexirica automáticamente passam a ter o mesmo valor
	printf("bergamota:  %d \n", bergamota);
	printf("*tagnerina: %d \n", *tangerina);
	printf("*mexirica:  %d \n", *mexirica);
}