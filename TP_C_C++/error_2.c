#include <stdio.h>

int VARIABLE_GLOBAL
char MATRIZ[5][9];


int main(void)
{
	int suma = sumar(5, 3); /* ERROR, sumar no ha sido declarada aún */
	printf("La suma es: %d ", suma);
	return 0;
}

int sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}
