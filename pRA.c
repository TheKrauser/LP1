/*Faça um programa que recebe um RA em uma variável long long int. Em seguida, por
meio de uma subrotina, o RA recebido deve ser decomposto, colocando cada um de seus
termos (Escola, Curso, Ano de Ingresso, etc) em uma variável criada a partir de uma struct
definida especificamente para essa finalidade. A subrotina deve receber o dado long long
int e retornar a struct com os termos do RA. Imprimir, na rotina principal, os dados na
forma Curso, Ano de Ingresso, Turno e Número sequencial.*/

#include <stdio.h>

struct RA
{
	int escola, curso, ano, semestre, turno, numero;
};

struct RA DecomporRA(long long int);

int main()
{
	struct RA sRA;
	long long int ra;
	
	scanf("%lld", &ra);
	sRA = DecomporRA(ra);
	printf("Curso: %03d\nAno de Ingresso: %i\nTurno: %i\nNumero Sequencial: %03d", sRA.curso, sRA.ano, sRA.turno, sRA.numero); 
	
	return 0;
}

struct RA DecomporRA(long long int ra)
{
	struct RA _ra;
	
	_ra.escola = ra/10000000000;
	_ra.curso = (ra%10000000000)/10000000;
	_ra.ano = (ra%10000000)/100000;
	_ra.semestre = (ra%100000)/10000;
	_ra.turno = (ra%10000)/1000;
	_ra.numero = ra%1000;
	
	return _ra;
}