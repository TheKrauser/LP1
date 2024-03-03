#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 4) Faça um programa que recebe uma palavra de até 25 caracteres e determina a 
// quantidade de ocorrências de cada letra, desprezando as diferenças entre 
// maiúsculas e minúsculas. Use um vetor de 26 posições para armazenar a
// quantidade de ocorrências de cada letra. No elemento 0 guarde a quantidade de 
// ocorrências da letra ‘A’, o elemento 1 guarde a quantidade de ocorrências da 
// letra ‘B’, e assim por diante. Imprima no final a quantidade de ocorrências de 
// cada letra, mas apenas das letras que existirem na palavra informada. Caso a 
// palavra tenha caracteres não alfabéticos, ignore-os: conte apenas as letras.

int main(void)
{
	char palavra[26], palavraConvertida[26];
	int quantidadeLetras[26] = {0};
	char letraInicial = 'a';
	
	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	
	strcpy(palavraConvertida, palavra);
	
	for (int i=0; i<strlen(palavraConvertida); i++)
	{
		palavraConvertida[i] = tolower(palavraConvertida[i]);
	}
	
	for(int i=0; i<26; i++)
	{
		for (int j=0; j<strlen(palavraConvertida); j++)
		{
			if (palavraConvertida[j] == letraInicial)
			{
				quantidadeLetras[i]++;
			}
		}
		
		letraInicial++;
	}
	
	for(int i=0; i<26; i++)
	{
		if (quantidadeLetras[i] != 0)
		{
			printf("Letra %i: %i\n", i, quantidadeLetras[i]);
		}
	}
	
	return 0;
}