/*
Exemplo de pilha estática em linguagem C
*/

#include <stdio.h>

#define MAXTAM 5

int pilha[MAXTAM];
int topo;
int valor;



int pilha_construtor()
{
	topo	= -1;	//declaração inicial
	valor	= 0;
}

int pilha_vazia()
{
	if (topo==-1)
		return 1;
	else
		return 0;
}

int pilha_cheia()
{
	if (topo == MAXTAM-1)
		return 1;
	else
		return 0;
}

//empilhar
int pilha_push(int valor)
{
	if ( pilha_cheia() == 0 )
	{
		topo++;
		pilha[topo] = valor;

		printf("push=%d\n", valor);
		return 0;
	} else {
		printf("ERRO - push=%d - pilha cheia\n", valor);
		return 1;
	}
}

//desempilhar
int pilha_pop()
{
	if ( pilha_vazia() == 0 )
	{
		//valor = pilha[topo];
		topo--;

		printf("pop\n");
		return 0;
	} else {
		printf("ERRO - pop - pilha vazia\n");
		return 1;
	}
}

int pilha_consulta()
{
	if ( pilha_vazia() == 0 )
	{
		printf("valor do topo da pilha: %d \n", pilha[topo]);
		return 0;
	} else
        printf("ERRO - pilha vazia\n");
		return 1;
}

int main()
{
	int valor;

	pilha_construtor();

	pilha_push(4);
	pilha_push(2);

    pilha_consulta();

	pilha_push(5);
	pilha_push(1);
	pilha_push(3);
	pilha_push(2);

	pilha_consulta();

	pilha_pop();
	pilha_pop();
	pilha_pop();
	pilha_pop();
	pilha_pop();
	pilha_pop();
	pilha_pop();
    pilha_consulta();

	return 1;
}
