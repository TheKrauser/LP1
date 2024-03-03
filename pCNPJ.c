/*Faça um programa para validar números de CNPJ (antigo CGC) conforme as regras descritas
ao final deste enunciado. Para cada CNPJ informado o programa deverá emitir a mensagem
‘válido’ ou então ‘inválido – esperado: 99, encontrado: 99’, onde o primeiro 99 indica o valor
correto dos dígitos verificadores e o segundo 99 representa o par de dígitos verificadores
efetivamente encontrado no CNPJ informado. Considere que todo CNPJ a ser processado
será informado exatamente na forma ’99.999.999/9999-99’. Encerrar o processamento
quando o usuário informar o CNPJ ’00.000.000/0000-00’.

Visão geral:
O CNPJ é composto por 14 valores numéricos (descontados portanto os símbolos especiais
de formatação como os ‘.’, a ‘/’ e o ‘-‘), sendo que os 2 últimos caracteres correspondem aos
seus chamados dígitos verificadores, que são calculados com base nos valores e na posição
dos 12 dígitos iniciais.
1 2 3 4 5 6 7 8 9 10 11 12 dv1 dv2
9 9 . 9 9 9 . 9 9 9 / 9 9 9 9 - 9 9

Inicialmente se calcula o valor do primeiro dígito (dv1), que será utilizado posteriormente
para o cálculo do segundo dígito (dv2).
Forma do cálculo:

1. Multiplicar cada um dos 12 dígitos iniciais por um número próprio conforme sua posição
no CNPJ, adotando-se o seguinte critério: o primeiro dígito (aquele mais à esquerda) é
multiplicado por 5, o segundo por 4, o terceiro por 3, o quarto por 2, o quinto por 9, o
sexto por 8, até o décimo segundo, que é multiplicado por 2. Somar os resultados de cada
multiplicação:
(Num1 * 5) + (Num2 * 4) + ... + (Num4 * 2) + (Num5 * 9) + (Num6 * 8) + ... + (Num12 * 2)

2. Calcular o resto da divisão do valor obtido na soma por 11, e subtrair esse resto de 11. O
valor obtido é o primeiro dígito verificador. Caso o resto calculado tenha sido igual a 1
ou 0, considerar que o primeiro dígito verificador é igual a ao número zero.

3. Multiplicar cada um dos 12 dígitos iniciais por número próprio conforme conforme sua posição
no CNPJ, adotando-se o seguinte critério: o primeiro dígito (aquele mais à esquerda) é
multiplicado por 6, o segundo por 5, até o quinto, multiplicado por 2. Multiplicar o sexto
dígito por 9, o sétimo por 8, até o décimo segundo, que é multiplicado por 3. Somar os
resultados de cada multiplicação:
(Num1 * 6) + (Num2 * 5) + ... + (Num5 * 2) + (Num6 * 9) + (Num7 * 8) + ... + (Num12 * 3)

4. Adicionar ao valor obtido nessa soma o dobro do valor do primeiro dígito verificador.

5. Calcular o resto da divisão do valor obtido por 11, e subtrair esse resto de 11. O valor
obtido é o segundo dígito verificador. Caso o resto calculado tenha sido igual a 1 ou 0,
considerar que o segundo dígito verificador é igual ao número zero.

Exemplos de CNPJ válidos:
62.823.257/0002-81
50.794.809/0001-00
02.312.654/0001-86
55.256.218/0003-65
47.680.251/0001-28*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct CNPJ
{
	char cnpjNum[19];
};

void VerificaCNPJ(struct CNPJ);
int SomaCNPJ(char *, int);

int main()
{
	struct CNPJ cnpj;

	while (scanf("%s", cnpj.cnpjNum) != EOF)
	{
		if (strcmp(cnpj.cnpjNum, "00.000.000/0000-00") == 0)
			break;
		else
			VerificaCNPJ(cnpj);
	}

	return 0;
}

void VerificaCNPJ(struct CNPJ cnpj)
{
	int digito1 = 0;
	int digito2 = 0;
	int soma = 0;

	soma = SomaCNPJ(cnpj.cnpjNum, 5);

	digito1 = (soma % 11);

	if (digito1 <= 1)
		digito1 = 0;
	else
		digito1 = 11 - digito1;

	soma = SomaCNPJ(cnpj.cnpjNum, 6);

	soma += (digito1 * 2);

	digito2 = (soma % 11);

	if (digito2 <= 1)
		digito2 = 0;
	else
		digito2 = 11 - digito2;

	if (digito1 == cnpj.cnpjNum[16] - 48 && digito2 == cnpj.cnpjNum[17] - 48)
	{
		printf("válido\n");
	}
	else
	{
		printf("inválido - esperado: %i%i, encontrado: %c%c\n", digito1, digito2, cnpj.cnpjNum[16], cnpj.cnpjNum[17]);
	}
}

int SomaCNPJ(char *cnpj, int primeiraMultip)
{
	int soma = 0;
	int tam = strlen(cnpj);

	for (int i = 0; i < tam - 2; i++)
	{
		if (cnpj[i] == '.' || cnpj[i] == '/' || cnpj[i] == '-')
		{
			continue;
		}
		else
		{
			soma += (cnpj[i] - 48) * primeiraMultip;
			primeiraMultip--;

			if (primeiraMultip < 2)
				primeiraMultip = 9;
		}
	}

	return soma;
}