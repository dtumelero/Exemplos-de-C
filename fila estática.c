/*Scrip de manipulaão de FILA ou FIFO First In First Out
Feito por André Gondim */

/*
changelog:
21/11/2017
Diego Tumelero
-correção na nomeiclatura das mensagens do programa.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int dado[MAX];
int topo;
int op;

void exibir(void){
    if (topo == 0 )
    {
        printf("A fila esta vazia\n");
    }
    else
    {
        for(int temp=0;topo-1 >= temp ;temp++)
        {
            printf("Na posicao %d temos %d\n",temp,dado[temp]);
        }
    }
    getchar();
}

void inserir(void){
    if (topo==MAX){
        printf("A fila esta cheia, OverFlow\n");
    }
    else {
        printf("Digite o valor para entrar na fila: \n");
        scanf("%d",&dado[topo]);
        topo++;
    }
    exibir();
}

void remover(int x[]){
    if (topo==0){
        printf("A fila esta vazia\n");
    }
    else {
        printf("Elemento %d removido\n",dado[0]);
        for (int i=0;i<=topo-1;i++){
            dado[i] = x[i+1];
        }
    }
    topo--;;
    exibir();
}

int menu(){
    printf("-= Programa Fila em C =-\n\n");
    printf("   Para inserir digite      1\n");
    printf("   Para remover digite      2\n");
    printf("   Para exibir digite       3\n\n");
    printf("   Para sair                4\n");
    scanf("%d",&op);
    switch (op){
        case 1 : inserir();
            break;
        case 2 : remover(dado);
            break;
        case 3 : exibir();
            break;
    }
    return 0;
}


int main(){
    topo=0;
    while (op!=4){

        printf("\n");

        menu();
    }
    return 0;
}
