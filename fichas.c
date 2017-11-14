//Exercício cadastro de consultas em linguagem C
//Demonstração do uso de structs e arquivos
//Autor: Diego Tumelero

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//número de registros, começa pelo número 1
#define NUM 2

//estruturas de dados para armazenar os pacientes
struct tipo_endereco{
    char estado[3];
    char cidade[40];
    char bairro[40];
    char cep[10];
    char endereco[50];
    char numero[6];
};

struct tipo_data{
    int dia;
    int mes;
    int ano;
};

struct tipo_cadastro{
    int    codigo;
    char   nome[50];
    int    modalidade_consulta;
    char   nome_convenio[30];
    int    taxa_consulta;
    struct tipo_endereco endereco;
    struct tipo_data     data;
};

//declarações globais
struct tipo_cadastro cadastro[NUM];
int    opcao=0;
int    i;



void limpa_tela(){
    //printf("cls");	//windows
    system("clear");	//linux
}



void pause(){
    //system("pause");				//windows
    system("read -p \"\" saindo");	//linux
}



//impressão de dados de uma ficha "i" na tela
void imprime_dados(){
    printf("\n+------------+");
    printf("\n| PACIENTE %d |", i); //mostra o número do paciente
    printf("\n+------------+");

    printf("\nNome:................%s", cadastro[i].nome);
    printf("\nData de nascimento:..%02d/%02d/%04d", 
            cadastro[i].data.dia, cadastro[i].data.mes, cadastro[i].data.ano);

    printf("\n_____________________");
    printf("\nDados de endereço:");
    printf("\nEstado:..............%s", cadastro[i].endereco.estado);
    printf("\nCidade:..............%s", cadastro[i].endereco.cidade);
    printf("\nBairro:..............%s", cadastro[i].endereco.bairro);
    printf("\nCEP:.................%s", cadastro[i].endereco.cep);
    printf("\nEndereço:............%s", cadastro[i].endereco.endereco);
    printf("\nNúmero:..............%s", cadastro[i].endereco.numero);

    printf("\n_____________________");
    if (cadastro[i].modalidade_consulta == 1)
        printf("\nModalidade:..........Convênio");
    else
        printf("\nModalidade:..........");
    if (cadastro[i].modalidade_consulta == 2)
        printf("\nModalidade:..........Particular");
    else
        printf("\nModalidade:..........");

    printf("\nNome do convênio:....%s", cadastro[i].nome_convenio);
    printf("\nTaxa da consulta:....%d\n", cadastro[i].taxa_consulta);
}



//imprime todas as fichas na tela
void listar(){
    for(i=1; i<=NUM; i++){
        imprime_dados(); //função usada para simplificar o processo de impressão
    }
}



//leitura do arquivo
void ler_arquivo(){
    FILE *ler;	//ponteiro de leitura

	//abertura do arquivo
    if((ler = fopen("fichas.txt", "r")) == NULL)
    {
        perror("Erro: Não foi possível abrir o arquivo.\n");
        exit(1);
    }

    //este loop pode ser usado o futuro para melhorar o programa //while (!feof(ler))

	//laço de leitura do arquivo
    for(i=1; i<=NUM; i++){
        fscanf(ler, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\t%d\n", 
            &cadastro[i].codigo, 
            cadastro[i].nome, 

            cadastro[i].endereco.estado, 
            cadastro[i].endereco.cidade,
            cadastro[i].endereco.bairro, 
            cadastro[i].endereco.cep, 
            cadastro[i].endereco.endereco, 
            cadastro[i].endereco.numero, 

            &cadastro[i].data.dia, 
            &cadastro[i].data.mes, 
            &cadastro[i].data.ano, 

            &cadastro[i].modalidade_consulta, 
            cadastro[i].nome_convenio, 
            &cadastro[i].taxa_consulta);
    }
	
	//fecha o arquivo
    fclose(ler);
}



//escreve no arquivo as fichas
void gravar_arquivo(){
	//ponteiro
    FILE *gravar;

	//abertura do arquivo
    gravar = fopen("fichas.txt", "w");

	//laço de gravação das fichas
    for(i=1; i<=NUM; i++){
        fprintf(gravar, "%d\t", cadastro[i].codigo);
        fprintf(gravar, "%s\t", cadastro[i].nome);

        fprintf(gravar, "%s\t", cadastro[i].endereco.estado);
        fprintf(gravar, "%s\t", cadastro[i].endereco.cidade);
        fprintf(gravar, "%s\t", cadastro[i].endereco.bairro);
        fprintf(gravar, "%s\t", cadastro[i].endereco.cep);
        fprintf(gravar, "%s\t", cadastro[i].endereco.endereco);
        fprintf(gravar, "%s\t", cadastro[i].endereco.numero);

        fprintf(gravar, "%d\t", cadastro[i].data.dia);
        fprintf(gravar, "%d\t", cadastro[i].data.mes);
        fprintf(gravar, "%d\t", cadastro[i].data.ano);

        fprintf(gravar, "%d\t", cadastro[i].modalidade_consulta);
        fprintf(gravar, "%s\t", cadastro[i].nome_convenio);
        fprintf(gravar, "%d\n", cadastro[i].taxa_consulta);
    }
	
	//fecha o arquivo
    fclose(gravar);
}



//cadastro de nvos pacientes
void cadastrar(){
    for(i=1; i<=NUM; i++){
        printf("\n----------\nPACIENTE %d\n----------\n", i); //mostra o número do paciente
        
        //em uma versão futura será gerado um código único para cada paciente
        //cadastro[i].codigo = i; //não usar este código
        

		//leitura e armazenamento das informações nas structs
        printf("Nome:\n");
        scanf("%s", cadastro[i].nome);

        printf("\n----------\nDados de endereço:\n");
        printf("Estado:\n");
        scanf("%s", cadastro[i].endereco.estado);
        printf("Cidade:\n");
        scanf("%s", cadastro[i].endereco.cidade);
        printf("Bairro:\n");
        scanf("%s", cadastro[i].endereco.bairro);
        printf("CEP:\n");
        scanf("%s", cadastro[i].endereco.cep);
        printf("Endereço:\n");
        scanf("%s", cadastro[i].endereco.endereco);
        printf("Número:\n");
        scanf("%s", cadastro[i].endereco.numero);

        printf("\n----------\nData de nascimento:\n");
        printf("Dia:\n");
        scanf("%d", &cadastro[i].data.dia);
        printf("Mês:\n");
        scanf("%d", &cadastro[i].data.mes);
        printf("Ano:\n");
        scanf("%d", &cadastro[i].data.ano);

        printf("\n----------\nModalidade da consulta:\n");
        printf("[1] Convênio\n");
        printf("[2] Particular\n");
        scanf("%d", &cadastro[i].modalidade_consulta);
        printf("Nome do convênio:\n");
        scanf("%s", cadastro[i].nome_convenio);
        printf("Taxa da consulta:\n");
        scanf("%d", &cadastro[i].taxa_consulta);
    }

	//cham a função que grava estes dados lidos no arquivo
    gravar_arquivo();
}



//função para "apagar"
void excluir(){
    printf("\n----------\nDigite o código do registro a ser apagado do arquivo: ");
    scanf("%d", &i);

    strcpy( cadastro[i].nome,              ".");

    strcpy( cadastro[i].endereco.estado,   ".");
    strcpy( cadastro[i].endereco.cidade,   ".");
    strcpy( cadastro[i].endereco.bairro,   ".");
    strcpy( cadastro[i].endereco.cep,      ".");
    strcpy( cadastro[i].endereco.endereco, ".");
    strcpy( cadastro[i].endereco.numero,   ".");
        
    cadastro[i].data.dia                   = 0;
    cadastro[i].data.mes                   = 0;
    cadastro[i].data.ano                   = 0;

    cadastro[i].modalidade_consulta        = 0;
    strcpy( cadastro[i].nome_convenio,     ".");
    cadastro[i].taxa_consulta              = 0;
	
    gravar_arquivo(); //grava as alterações no arquivo 
}



//consulta um paciente pelo nome
void consultar(){
    char pesquisa[50];
    
    printf("\n----------\nDigite o nome: ");
    scanf("%s", pesquisa);

    for (i=1; i<=NUM; i++){
        if (0 == strcmp(pesquisa, cadastro[i].nome)){
			imprime_dados();
        }
    }
}



//permite alterar os dados de uma ficha
void alterar(){
    printf("\n----------\nDigite o código do registro a ser alterado:\n");
    scanf("%d", &i);

    printf("\n----------\nPACIENTE %d\n----------\n", i); //mostra o número do paciente
    printf("\nNome:     %s", cadastro[i].nome);
    printf("\nData de nascimento: %02d/%02d/%04d", 
            cadastro[i].data.dia, cadastro[i].data.mes, cadastro[i].data.ano);

    printf("\n----------\nDados de endereço:\n");
    printf("Estado:\n");
    scanf("%s", cadastro[i].endereco.estado);
    printf("Cidade:\n");
    scanf("%s", cadastro[i].endereco.cidade);
    printf("Bairro:\n");
    scanf("%s", cadastro[i].endereco.bairro);
    printf("CEP:\n");
    scanf("%s", cadastro[i].endereco.cep);
    printf("Endereço:\n");
    scanf("%s", cadastro[i].endereco.endereco);
    printf("Número:\n");
    scanf("%s", cadastro[i].endereco.numero);

    printf("\n----------\nModalidade da consulta:\n");
    printf("[1] Convênio\n");
    printf("[2] Particular\n");
    scanf("%d", &cadastro[i].modalidade_consulta);
    printf("Nome do convênio:\n");
    scanf("%s", cadastro[i].nome_convenio);
    printf("Taxa da consulta:\n");
    scanf("%d", &cadastro[i].taxa_consulta);

	//grava as alterações no arquivo
    gravar_arquivo();
}



//menu principal
void menu(){
    limpa_tela();

    printf("Sistema de armazenamento de registros.\n");
    printf("Quantidade máxima de registros: %d\n", NUM);
    printf("-------------------------------\n");
    printf("Informe uma opção:\n");
    printf("-------------------------------\n");
    printf("1 - Ler registros de um arquivo\n");
    printf("2 - Cadastrar\n");
    printf("3 - Excluir\n");
    printf("4 - Consultar\n");
    printf("5 - Alterar\n");
    printf("6 - Listar todos os registros\n");
    printf("7 - Sair\n");
    printf("-------------------------------\n");

    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            ler_arquivo();
            menu();	//menu() é uma função recursiva
        break;

        case 2:
            limpa_tela();
            cadastrar();
            menu();
        break;

        case 3:
            limpa_tela();
            excluir();
            menu();
        break;

        case 4:
            limpa_tela();
            consultar();
            pause();
            menu();
        break;

        case 5:
            limpa_tela();
            alterar();
            menu();
        break;

        case 6:
            limpa_tela();
            listar();
            pause();
            menu();
        break;

        case 7:
            exit(0);
        break;

        default:
            printf("Opção inválida!\n");
            pause();
            menu();
    }
}



void main(){
    limpa_tela();

    printf("Instituto Federal do Rio Grande do Sul\n");
    printf("IFRS - Campus Canoas\n\n");

    printf("TADS - Programação Estruturada - 2017/2\n");
    printf("Professor: Diego Tumelero\n");
    printf("Autor: Diego Tumelero\n\n");

    printf("Sistema de armazenamento de registros de consultas.\n");
    printf("Quantidade máxima de registros: %d.\n", NUM);
    
    pause();

	//o menu não fica na função principal para que ele possa ser chamado recursivamente
    menu();
}
