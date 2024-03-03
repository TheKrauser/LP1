#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Faça um programa que recebe uma palavra de até 15 caracteres e depois a 
// imprime das seguintes maneiras:
// a) Do jeito que foi digitada.
// b) Toda em minúsculas.
// c) Toda em maiúsculas.
// d) Com a primeira letra em maiúsculas e o restante em minúsculas.
// e) Com os caracteres invertidos quanto a maiúsculas e minúsculas, por 
// exemplo, “SoRocaBa” ficaria “sOrOCAbA”.

int main(void)
{
	char palavra[16];
	char palavraMinuscula[16], palavraMaiuscula[16], primeiraMaiuscula[16], palavraInvertida[16];
	
	printf("Digite uma String: ");
	scanf("%s", palavra);
	
	//strcpy(destino, origem);
	strcpy(palavraMinuscula, palavra);
	strcpy(palavraMaiuscula, palavra);
	strcpy(primeiraMaiuscula, palavra);
	strcpy(palavraInvertida, palavra);
	
	//Convertendo para minusculas e maiusculas
	for (int i=0; i<strlen(palavra); i++)
	{
		palavraMinuscula[i] = tolower(palavraMinuscula[i]);
		palavraMaiuscula[i] = toupper(palavraMaiuscula[i]);
		
		if (i == 0)
		{
			primeiraMaiuscula[i] = toupper(primeiraMaiuscula[i]);
		}
		else
		{
			primeiraMaiuscula[i] = tolower(primeiraMaiuscula[i]);
		}
		
		if (palavraInvertida[i] >= 'A' && palavraInvertida[i] <= 'Z')
		{
			palavraInvertida[i] = tolower(palavraInvertida[i]);
		}
		else if (palavraInvertida[i] >= 'a' && palavraInvertida[i] <= 'z')
		{
			palavraInvertida[i] = toupper(palavraInvertida[i]);
		}
	}
	
	printf("\n\nA) A palavra digitada foi: %s\n", palavra);
	printf("B) Todos os caracteres minusculos: %s\n", palavraMinuscula);
	printf("C) Todos os caracteres maiusculos: %s\n", palavraMaiuscula);
	printf("D) Primeira letra maiuscula: %s\n", primeiraMaiuscula);
	printf("E) Letras invertidas: %s\n", palavraInvertida);
	
	return 0;
}
