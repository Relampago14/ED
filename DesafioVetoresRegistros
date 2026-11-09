#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int matricula;
	char nome[50];
	char numero_cel[50];
	float peso;
	float altura;
} Aluno;

// Função para inicializar o vetor de alunos
void inicializarVetor(Aluno alunos[], int quantidade) {
	for (int i = 0; i < quantidade; i++) {
		// Inicializa os campos do aluno com valores padrão
		alunos[i].matricula = 0;
		alunos[i].nome[0] = '\0'; // Inicializa a string como vazia (Basta colocar o primeiro caractere como '\0')
		alunos[i].numero_cel[0] = '\0'; // Inicializa a string como vazia (Basta colocar o primeiro caractere como '\0')
		alunos[i].peso = 0.0;
		alunos[i].altura = 0.0;
	}
}

// Função para incluir um aluno no vetor
void incluirAluno(Aluno alunos[], int *controle, int quantidade) {

	// Verifica se já atingiu o limite de alunos cadastrados
	if (*controle >= quantidade) {
		printf("Não é possível incluir mais alunos.\n");
		return;
	}

	// Solicita os dados do aluno ao usuário
	printf("Digite a matrícula do aluno: ");
	scanf_s("%d", &alunos[*controle].matricula);

	printf("Digite o nome do aluno: ");
	// Limita a leitura do nome para evitar estouro de buffer
	scanf_s("%49s", alunos[*controle].nome, sizeof(alunos[*controle].nome));

	printf("Digite o número de celular do aluno: ");
	// Limita a leitura do número de celular para evitar estouro de buffer
	scanf_s("%49s", alunos[*controle].numero_cel, sizeof(alunos[*controle].numero_cel));

	printf("Digite o peso do aluno: ");
	scanf_s("%f", &alunos[*controle].peso);

	printf("Digite a altura do aluno: ");
	scanf_s("%f", &alunos[*controle].altura);

	// Incrementa a quantidade de alunos cadastrados
	(*controle)++;
}

// Função para excluir um aluno do vetor
void excluirAluno(Aluno alunos[], int *controle, int matricula){
	// Para cada aluno cadastrado, verifica se a matrícula corresponde à do aluno a ser excluído
	for (int i = 0; i < *controle; i++) {
		// Verifica se a matrícula do aluno atual é igual à matrícula fornecida
		if (alunos[i].matricula == matricula) {
			// Se for, remove o aluno deslocando os elementos subsequentes para a esquerda
			for (int j = i; j < *controle; j++) {
				alunos[j] = alunos[j + 1];
			}
			// Decrementa a quantidade de alunos cadastrados
			(*controle)--;
		}

	}
}

// Função para imprimir a relação de alunos cadastrados
void imprimirRelacaoAlunos(Aluno alunos[], int controle) {
	// Para cada aluno cadastrado, imprime a matrícula e o nome
	for (int i = 0; i < controle; i++) {
		printf("Matrícula: %d, Nome: %s\n", alunos[i].matricula, alunos[i].nome);
	}
}

// Função para buscar um aluno pelo nome
void buscarPorNome(Aluno alunos[], int controle, const char* nome) {

	// Para cada aluno cadastrado, verifica se o nome corresponde ao nome fornecido
	for (int i = 0; i < controle; i++) {
		// Compara o nome do aluno atual com o nome fornecido sem diferenciar maiúsculas de minúsculas
		if (_stricmp(alunos[i].nome, nome) == 0) {
			// Se for igual, imprime os dados do aluno encontrado
			printf("\nAluno encontrado:\n");
			printf("Matrícula: %d\n", alunos[i].matricula);
			printf("Nome: %s\n", alunos[i].nome);
			printf("Número de Celular: %s\n", alunos[i].numero_cel);
			printf("Peso: %.2f\n", alunos[i].peso);
			printf("Altura: %.2f\n", alunos[i].altura);
		}

		// Se não, exibe uma mensagem informando que o aluno não foi encontrado
		else {
			printf("Aluno não encontrado.\n");
		}
	}
}

// Função para imprimir os dados dos alunos cadastrados
void imprimirAlunos(Aluno alunos[], int controle) {
	// Para cada aluno cadastrado, imprime seus dados
	for (int i = 0; i < controle; i++) {
		printf("\nAluno %d:\n", i + 1);
		printf("Matrícula: %d\n", alunos[i].matricula);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Número de Celular: %s\n", alunos[i].numero_cel);
		printf("Peso: %.2f\n", alunos[i].peso);
		printf("Altura: %.2f\n", alunos[i].altura);
	}
}

int main() {
	int controle_inclusao = 0; // Variável para controlar a quantidade de alunos cadastrados
	Aluno alunos[500];

	inicializarVetor(alunos, sizeof(alunos) / sizeof(alunos[0]));
	incluirAluno(alunos, &controle_inclusao, sizeof(alunos) / sizeof(alunos[0]));
	imprimirRelacaoAlunos(alunos, controle_inclusao);
	imprimirAlunos(alunos, controle_inclusao);
	buscarPorNome(alunos, controle_inclusao, "joao");

	return 0;
}
