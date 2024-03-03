/*Faça um programa para verificar se um ponto está contido dentro de um retângulo ou não.
Receber inicialmente uma quantidade inteira N que indicará o número de casos de teste. Para
cada caso de teste, receber inteiros x0, y0, x1, y1, x, y onde (x0, y0) corresponde ao vértice
inferior esquerdo do retângulo, (x1, y1) ao vértice superior direito e (x, y) são as coordenadas
do ponto a ser verificado. Receber os valores e imprimir a resposta (“Contido” ou “Naocontido”)
na rotina main() e usar uma struct para armazenar as duas coordenadas do ponto e
uma função para verificar a pertinência.*/

#include <stdio.h>

struct Coordenada 
{
	int x0, y0, x1, y1;
};

void VerificaPonto(struct Coordenada, int, int);

int main()
{
	struct Coordenada coord;
	int casos;
	int x, y;
	
	scanf("%i", &casos);
	
	for(int i=0; i<casos; i++)
	{
		scanf("%i %i %i %i %i %i", &coord.x0, &coord.y0, &coord.x1, &coord.y1, &x, &y);
		VerificaPonto(coord, x, y);
	}
}

void VerificaPonto(struct Coordenada coordenada, int x, int y)
{
	if ((coordenada.x0 <= x && x <= coordenada.x1) && (coordenada.y0 <= y && y <= coordenada.y1))
	{
		printf("Contido\n");
	}
	else
	{
		printf("Nao-contido\n");
	}
}