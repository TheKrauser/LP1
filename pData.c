/*O dia da semana para uma data qualquer pode ser calculado pela seguinte fórmula:
Dia da semana = RESTO(TRUNCA(2.6 * M – 0.1) + D + A + QUOCIENTE(A, 4) +
QUOCIENTE(S, 4) – 2 * S, 7)
onde:
M representa o número do mês. Janeiro e fevereiro são os meses 11 e 12
do ano precedente, março é o mês 1 e dezembro é o mês 10.
D representa o dia do mês.
A representa o número formado pelos dois últimos algarismos do ano.
S representa o número formado pelos dois primeiros algarismos do ano.

Os dias da semana são numerados de zero a seis; domingo corresponde a 0, segunda a 1, e
assim por diante. Faça então um programa que:
- Leia um conjunto de datas (dia, mês, ano), conforme os exemplos apresentados a
seguir. Assuma que todas as datas informadas serão datas válidas. Encerrar o
processamento quando for informado a data dia 0 mês 0 ano 0, que não deverá ser
processada.
- Para cada data lida, determine o dia da semana correspondente, segundo o método
especificado anteriormente. Caso a aplicação da fórmula produza um valor negativo,
some 7 a esse valor e prossiga normalmente com o processamento.
- Escreva, para cada data lida, o dia, o mês, o ano e o nome do dia da semana calculado
pelo seu programa, no formato indicado nos exemplos.
- Usar uma struct para representar a data, uma função para retornar o número do dia da
semana e outra função que, com base no número dia da semana, imprime o nome do
dia.

Dicas:
- O resto da divisão do número inteiro X pelo número inteiro Y é um inteiro dado, em
linguagem C, por X % Y.
- O quociente da divisão do número inteiro X pelo número inteiro Y é um inteiro dado,
em linguagem C, por X / Y. Se um dos operandos (X ou Y ou ambos) for de tipo real
(float ou double), então o resultado será um número real.
- Para truncar um número real, descartando sua parte fracionária e convertendo o
resultado para inteiro, basta colocar a expressão (int) antes do número ou variável
real. Por exemplo, (int)3.1415 produz o valor 3; (int)vInfo produz o valor 10,
caso a variável real vInfo possua o valor 10.424397.*/

#include <stdio.h>

int DiaSemana(int, int, int);
void ImprimeDiaSemana(int);

struct Data
{
	int dia, mes, ano;
};

int main()
{
	struct Data data;

	scanf("%i%i%i", &data.dia, &data.mes, &data.ano);
	
	while(data.dia != 0 && data.mes != 0 && data.ano != 0)
	{
		printf("%02d/%02d/%i: ", data.dia, data.mes, data.ano);
		ImprimeDiaSemana(DiaSemana(data.dia, data.mes, data.ano));
		scanf("%i%i%i", &data.dia, &data.mes, &data.ano);
	}
	
	return 0;
}

int DiaSemana(int dia, int mes, int ano)
{
	int semana;
	
	if (mes < 3)
	{
		mes += 10;
		ano -= 1;
	}
	else
	{
		mes -= 2;
	}

	int anoPrimeiros = ano / 100;
	int anoUltimos = ano % 100;
	
	semana = ((int)(2.6 * mes - 0.1) + dia + anoUltimos + (anoUltimos / 4) + (anoPrimeiros / 4) - 2 * anoPrimeiros) % 7;
	
	if (semana < 0)
	{
		return semana + 7;
	}
	else
	{
		return semana;
	}
}

void ImprimeDiaSemana(int semana)
{
	if (semana == 0)
	{
		printf("Domingo\n");
	}
	else if (semana == 1)
	{
		printf("Segunda-Feira\n");
	}
	else if (semana == 2)
	{
		printf("Terça-Feira\n");
	}
	else if (semana == 3)
	{
		printf("Quarta-Feira\n");
	}
	else if (semana == 4)
	{
		printf("Quinta-Feira\n");
	}
	else if (semana == 5)
	{
		printf("Sexta-Feira\n");
	}
	else
	{
		printf("Sabado\n");
	}
}