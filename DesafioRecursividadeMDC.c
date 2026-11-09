#include <stdlib.h>
#include <stdio.h>

// Função que calcula o MDC de dois números usando recursividade
int calcularMDC(int a, int b) {
	// Se b for igual a zero, o MDC é a
	if (b == 0) {
		return a;
	}
	// Se não, chama a função recursivamente, trocando os valores de 'a' por 'b' e 'b' pelo resto da divisão 
	else {
		return calcularMDC(b, a % b);
	}
}

int main() {
	int a, b;
	printf("Digite um número inteiro: ");
	scanf_s("%d", &a);
	printf("Digite outro número inteiro: ");
	scanf_s("%d", &b);
	int mdc = calcularMDC(a, b);
	printf("O MDC de %d e %d é: %d\n", a, b, mdc);
	return 0;
}
