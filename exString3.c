#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 3) Faça um programa que:
// a) Declara duas variáveis com capacidade para armazenar strings de até 20 caracteres cada uma.
// b) Recebe uma string informada pelo usuário e a armazena na primeira variável.
// c) Recebe outra string informada pelo usuário e a armazena na segunda variável.
// d) Compara as duas strings com strcmp() e, caso sejam idênticas, exibe a 
// mensagem “Strings são idênticas: case sensitive”, em caso contrário, 
// verifica se são iguais caso ignoremos as diferenças entre maiúsculas e 
// minúsculas. Caso sejam, exibir a mensagem “Strings são idênticas: case 
// insensitive” e a mensagem “Strings são diferentes” em caso contrário.

int main(void)
{
	char palavra1[21], palavra2[21];
	char palavra1Convertida[21], palavra2Convertida[21];
	
	printf("Digite a primeira String: ");
	scanf("%s", palavra1);
	
	printf("Digite a segunda String: ");
	scanf("%s", palavra2);
	
	strcpy(palavra1Convertida, palavra1);
	strcpy(palavra2Convertida, palavra2);
	
	for(int i=0; i<strlen(palavra1Convertida); i++)
	{
		palavra1Convertida[i] = tolower(palavra1Convertida[i]);
	}
	
	for(int i=0; i<strlen(palavra2Convertida); i++)
	{
		palavra2Convertida[i] = tolower(palavra2Convertida[i]);
	}
	
	if (strcmp(palavra1, palavra2) == 0)
	{
		printf("Strings são idênticas: case sensitive");
	}
	else if (strcmp(palavra1Convertida, palavra2Convertida) == 0)
	{
		printf("Strings são idênticas: case insensitive");
	}
	else
	{
		printf("Strings são diferentes");
	}
	
	return 0;
}