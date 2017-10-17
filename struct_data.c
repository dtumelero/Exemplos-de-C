/*
Exemplo de structs em linguagem c
*/

#include <stdio.h>

//struct
struct data{
    char mes[10];
	int  dia; 
    int  ano;
};

void main(){
    //declaração da struct de nome data_nascimento
	struct data data_nascimento;		

    printf("Digite o dia de nascimento: ");
    scanf("%d", &data_nascimento.dia);

    printf("Digite o mês de nascimento: ");
    scanf("%s", data_nascimento.mes);	//quando é string não vai & no scanf

    printf("Digite o ano de nascimento: ");
    scanf("%d", &data_nascimento.ano);

	//é possível dividir em multiplas linhas um comando
	//mas é bom deixar bem "apresentado" para facilitar a leitura
	printf("\nA data de nascimento é %d de %s de %d.\n", 
			data_nascimento.dia, 
			data_nascimento.mes, 
			data_nascimento.ano);
}
