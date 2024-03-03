#include <stdio.h>

void Bolha(int *);

int main()
{
    int *pLista, lista[10];

    pLista = lista;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &lista[i]);
    }

    Bolha(pLista);
}

void Bolha(int *p)
{
    int elementosOrdenados = 0;
    int aux = 0;

    int repet = 9;
    while (elementosOrdenados < 10)
    {
        for (int i = 0; i < repet; i++)
        {
            if (*(p+i) > *(p+i+1))
            {
                aux = *(p+i+1);
                *(p+i+1) = *(p+i);
                *(p+i) = aux;
            }
        }

        repet--;
        elementosOrdenados++;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
}