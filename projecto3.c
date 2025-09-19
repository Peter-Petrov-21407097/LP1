#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include <ctype.h> 

const int numerolinhas = 8;

int primeiracoordenada(char opcao1) {
	int numero;
	numero = (int)(opcao1)-64;
	if(numero<1 || numero >9){
		printf("Error: Invalid coordinate.\n");
		exit(1);
	}else{
	return numero;
	}
}


int segundacoordenada(int opcao2){
	int numero;
	if(opcao2 == '1' || opcao2 == '2' || opcao2 == '3' || opcao2 == '4' || opcao2 == '5' || opcao2 == '6' ||opcao2 == '7' || opcao2 == '8'){
		numero = (int)(opcao2) - 48; /* Converter para numero de 1 a 8 na tabela ascii*/
		numero = (numero -1) * 4;
		return numero;

	}else{
		printf("Error: Invalid coordinate.\n");
		exit(1);
	}
}

int terceiracoordenada(int opcao3){
	
	int numero;
	if(opcao3 == '1' || opcao3 == '2' || opcao3 == '3'){
		numero = (int)(opcao3)-48;  /* Converter para numero de 1 a 8 na tabela ascii*/
		numero -= 1;
		return numero;
	}else{
		printf("Error: Invalid coordinate.\n");
	exit(1);
	}
}

int main(int argc, char* argv[])
{
	int i = 0;
	char linha[8][35];
	FILE *ficheiro;
	char opcao1 =' ';
    char opcao2 = 0;
    char opcao3 = 0;


    ficheiro = fopen("texto.txt","r");
    if (ficheiro == NULL){
		printf("Error: could not open file.");
        exit(1);
    }else{
		scanf("%[^\n]c", &opcao1);
		scanf("%[^\n]c", &opcao2);
		scanf("%[^\n]c", &opcao3);

	
	while(fgets(linha[i], 35, ficheiro)){
		linha[i][strlen(linha[i]) - 1] = '\0';
		i++;
		}

    for(i = 0; i < numerolinhas; ++i)
    {
		if(primeiracoordenada(opcao1) == i){
			if(linha[i][segundacoordenada(opcao2)+terceiracoordenada(opcao3)]>48 && linha[i][segundacoordenada(opcao2)+terceiracoordenada(opcao3)]<58){
			printf("%c", linha[i-1][segundacoordenada(opcao2)+terceiracoordenada(opcao3)]);
			}else{
				printf("Error: File is corrupted.");
				exit(1);
				}	
			}
		}
	}
    fclose(ficheiro);
    return 0;
}
