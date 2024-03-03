/*Criar uma struct para representar o tipo ponto, por meio da seguinte instrução:
struct ponto { float x; float y; } ;
Em seguida, o programa deverá receber vários pares de pontos e, para cada par, determinar a
distância entre eles, conforme a fórmula
Distância = √ (x2 - x1)² + (y2 - y1)²
Encerrar o processamento quando for recebido um conjunto de entradas com quatro números
zero.*/

#include <stdio.h>
#include <math.h>

struct Ponto
{
	float x, y;
};

float CalculaDistancia(struct Ponto, struct Ponto);

int main()
{
	struct Ponto ponto1, ponto2;
	float dist;

	scanf("%f %f %f %f", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
	while (ponto1.x != 0 && ponto2.x != 0 && ponto1.y != 0 && ponto2.y != 0)
	{
		dist = CalculaDistancia(ponto1, ponto2);
		printf("%f\n", dist);
		scanf("%f %f %f %f", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
	}

	return 0;
}

float CalculaDistancia(struct Ponto p1, struct Ponto p2)
{
	float dist;

	dist = sqrt((pow(p2.x - p1.x, 2)) + (pow(p2.y - p1.y, 2)));

	return dist;
}