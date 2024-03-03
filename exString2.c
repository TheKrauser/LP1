#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 2) Faça um programa que recebe uma string de até 18 caracteres e depois exibe:
// a) A quantidade de letras existentes na palavra.
// b) A quantidade de letras maiúsculas encontradas na palavra.
// c) A quantidade de letras minúsculas que a palavra possui.
// d) A quantidade de dígitos numéricos encontrados na palavra.
// e) A quantidade de caracteres especiais da palavra

int main(void)
{
	char palavra[19];
	int contLetras = 0, contMaiusculas = 0, contMinusculas = 0, contDigitos = 0, contEspeciais = 0;
	
	printf("Digite uma String: ");
	scanf("%s", palavra);
	
	for (int i=0; i<strlen(palavra); i++)
	{
		if (isalpha(palavra[i]) != 0)
		{
			contLetras++;
		}
		
		if (islower(palavra[i]) != 0)
		{
			contMinusculas++;
		}
		else if (isupper(palavra[i]) != 0)
		{
			contMaiusculas++;
		}
		else if (isdigit(palavra[i]) != 0)
		{
			contDigitos++;
		}
		else if (isgraph(palavra[i]) != 0)
		{
			contEspeciais++;
		}
	}
	
	printf("\n\nA) Quantidade de letras na palavra:  %i\n", contLetras);
	printf("B) Quantidade de letras maiusculas:  %i\n", contMaiusculas);
	printf("C) Quantidade de letras minusculas:  %i\n", contMinusculas);
	printf("D) Quantidade de digitos numericos:  %i\n", contDigitos);
	printf("E) Quantidade de caracteres especiais:  %i\n", contEspeciais);
	
	return 0;
}