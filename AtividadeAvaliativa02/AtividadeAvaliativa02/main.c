#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void capitalizarInicial(char *str) {
	// Função que recebe uma string e retorna a mesma string 
	// com a primeira letra de cada palavra em maiúscula e as demais em minúscula.

	int j = 0; //Variável para controlar a posição do caractere na string modificada

	// Loop para percorrer cada caractere da string
	for (int i = 0; str[i] != '\0';i++) {

		// Verifica se o caractere atual não é um espaço em branco
		// Ou se J é maior que 0 e o caractere anterior da string modificada não é um espaço em branco
		if (!isspace(str[i]) || (j>0 && !isspace(str[j-1]))) {
			// Se não for um espaço, converte o caractere para minúsculo e adiciona à string modificada
			str[j] = tolower(str[i]);

			// Se for um caractere alfabético
			// E se for o primeiro caractere da string modificada ou se o caractere anterior for um espaço em branco
			if (isalpha(str[j]) && (j == 0 || str[j - 1] == ' ')) {
				str[j] = toupper(str[j]);
			}
			j++;
		}
	}

	// Encerra a string com o caractere nulo
	str[j] = '\0';
}

void preencherPrecos(float* precos, int tamanho) {
	// Função que recebe um vetor de precos e seu tamanho, e preenche o vetor com valores digitados pelo usuário.

	int resultado = 0; // Variável para armazenar o resultado da função scanf_s

	// Loop para percorrer cada posição do vetor de precos e incluir um valor adequado digitado pelo usuário.	
	for (int i = 0; i < tamanho;) {
		printf("Digite o preco do produto numero %d: ", i+1);
		resultado = scanf_s("%f", &precos[i]);

		// Verifica se o valor digitado é um numero válido e maior que zero
		if (resultado == 1) {

			// Se for, verifica se o valor é menor ou igual a zero
			if (precos[i] <= 0) {
				printf("Preco inválido. Digite um valor maior que zero.\n");

				// Limpa o buffer de entrada, descartando os caracteres inválidos
				// até encontrar uma quebra de linha ou o fim da entrada (EOF).
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			}
			// Se não for, incrementa o índice para passar para a próxima posição do vetor
			else {
				i++;
			}
		}

		// Se não for um numero válido, exibe uma mensagem de erro
		else {
			printf("Preco inválido. Digite um valor numérico.\n");

			// Limpa o buffer de entrada, descartando os caracteres inválidos
			// até encontrar uma quebra de linha ou o fim da entrada (EOF).
			int c;
			while ((c = getchar()) != '\n' && c != EOF);

		}

	}
}

float calcularDesconto(float* precos, int tamanho, float* media) {
	// Função que recebe um vetor de precos, seu tamanho e um ponteiro para a média dos precos
	// e retorna o valor total dos descontos aplicados

	*media = 0; // Inicializa a média com zero

	float total_desconto = 0; // Variável para armazenar o valor total dos descontos aplicados

	// Loop para percorrer cada posição do vetor de precos e aplicar o desconto correspondente
	for (int i = 0; i < tamanho; i++) {

		// Verifica o valor do preco e aplica o desconto correspondente
		if (precos[i] > 3000) {
			total_desconto += precos[i] * 0.2; // Adiciona o valor do desconto à variável total
			precos[i] *= 0.8; // Aplica desconto de 20%
		}
		else if (precos[i] > 1500) {
			total_desconto += precos[i] * 0.15; // Adiciona o valor do desconto à variável total
			precos[i] *= 0.85; // Aplica desconto de 15%
		}
		else if (precos[i] > 500) {
			total_desconto += precos[i] * 0.1; // Adiciona o valor do desconto à variável total
			precos[i] *= 0.9; // Aplica desconto de 10%
		}
		else if (precos[i] > 0) {
			total_desconto += precos[i] * 0.05; // Adiciona o valor do desconto à variável total
			precos[i] *= 0.95; // Aplica desconto de 5%
		}
	}

	// Loop para calcular a média dos precos após os descontos
	for (int i = 0; i < tamanho; i++) {
		*media += precos[i];
	}

	// Divide a soma dos precos pelo tamanho do vetor para obter a média
	*media /= tamanho;

	// Retorna o valor total dos descontos aplicados
	return total_desconto;
}

int main(void) {

	char str[100]; // Variável para armazenar a string digitada pelo usuário
	// Solicita ao usuário que digite uma string
	printf("Digite uma string: ");
	fgets(str, 100, stdin);
	// Chama a função capitalizarInicial para modificar a string
	capitalizarInicial(str);
	// Exibe a string modificada
	printf("String modificada: %s\n\n", str);


	int quantidade = 0; // Variável para armazenar a quantidade de precos digitados pelo usuário

	// Loop para solicitar a quantidade de precos a serem digitados pelo usuário
	while (1) {
		int resultado = 0; // Variável para armazenar o resultado da função scanf_s

		// Solicita ao usuário que digite a quantidade de precos a serem digitados
		printf("Digite a quantidade de precos a serem digitados: ");
		resultado = scanf_s("%d", &quantidade);

		// Verifica se o valor digitado é um numero válido
		if (resultado == 1) {

			// Se for, verifica se o valor é menor ou igual a zero
			if (quantidade <= 0) {
				printf("Quantidade inválida. Digite um valor maior que zero.\n");
			}
			// Se não for, sai do loop
			else {
				printf("Quantidade de precos a serem digitados: %d\n", quantidade);
				break;
			}

		}

		else if (resultado == EOF) {
			// Se o usuário pressionar Ctrl+D (EOF), encerra o programa
			printf("Entrada encerrada pelo usuário.\n");
			return 0;
		}

		// Se não for um numero válido, exibe uma mensagem de erro
		else {
			printf("Preco inválido. Digite um valor numerico.\n");
		}

		// Limpa o buffer de entrada, descartando os caracteres inválidos
		// até encontrar uma quebra de linha ou o fim da entrada (EOF).
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}
	// Aloca dinamicamente um vetor de precos com o tamanho especificado pelo usuário
	float* precos = (float*)malloc(quantidade * sizeof(float));

	// Verifica se a alocação de memória foi mal-sucedida
	if (precos == NULL) {
		printf("Erro ao alocar memoria para o vetor de precos.\n");
		return 1;
	}

	// Chama a função preencherPrecos para preencher o vetor de precos com os valores digitados pelo usuário
	preencherPrecos(precos, quantidade);
	
	float media = 0; //Inicializa a variável com 0 para armazenar a média dos precos com desconto
	// Chama a função calcularDesconto 
	// para aplicar os descontos aos precos e calcular a média dos precos com desconto
	float total_desconto = calcularDesconto(precos, quantidade, &media);

	// Exibe a média dos precos com os descontos aplicados e o total de descontos aplicados
	printf("\nMedia dos precos com os descontos aplicados: %.2f\n", media);
	printf("Total de descontos aplicados: %.2f\n\n", total_desconto);

	// Loop para exibir os precos com desconto
	for (int i = 0; i < quantidade; i++) {
		printf("Preco do produto com desconto numero %d: %.2f\n", i + 1, precos[i]);
	}

	// Libera a memória alocada para o vetor de precos
	free(precos);

	return 0;
}