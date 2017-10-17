#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ORDEM 1000
#define ALEAT 256

#pragma OMP_NUM_THREADS=8

int linha;
int coluna;
int i;
long int somaprod;

long int mat1[ORDEM][ORDEM];
long int mat2[ORDEM][ORDEM];
long int mat3[ORDEM][ORDEM];

int M1L=ORDEM, M1C=ORDEM, M2L=ORDEM, M2C=ORDEM;



//imprime mat3
void print_mat3(){
	//Imprime mat3
    for(linha=0; linha<M1L; linha++)
    {
        for(coluna=0; coluna<M2C; coluna++)
        {
            printf("%ld\t", mat3[linha][coluna]);
        }
        printf("\n");
    }
}



//multiplicação
void mul_mat(){
    #pragma omp parallel for
    for(linha=0; linha<M1L; linha++){    
        #pragma omp critical
		for(coluna=0; coluna<M2C; coluna++){
            somaprod = 0;
            for(i=0; i<M1L; i++){
                somaprod += mat1[linha][i] * mat2[i][coluna];
            }
            mat3[linha][coluna] = somaprod;
        }
    }
}



//gera valores aleatórios para as mat1 e mat2
void rand_mat(){
    for(linha=0; linha<M1L; linha++){
        for(coluna=0; coluna<M2C; coluna++){
            mat1[linha][coluna] = rand() %ALEAT;
            mat2[linha][coluna] = rand() %ALEAT;
        }
    }
}



void main(){
	//gera valores aleatórios para as mat1 e mat2
	rand_mat();

	//multiplica as matrizes
	mul_mat();

	//imprime mat3
	//print_mat3();
}
