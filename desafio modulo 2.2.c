// O objetivo era criar um jogo de Pedra, Papel e Tesoura contra a máquina e exibir o resultado.

#include <stdio.h>
#include <stdlib.h>
int main() { 
  int opcao_jogador, opcao_maq; 
  
  printf("Digite uma opção:\n"); 
  printf("1 - Pedra\n"); 
  printf("2 - Papel\n"); 
  printf("3 - Tesoura\n"); 
  scanf("%d", &opcao_jogador); 
  
  opcao_maq = rand() % 3 + 1; 
  printf("A máquina escolheu %d\n", opcao_maq); 
  
  if (opcao_jogador == 1 && opcao_maq == 2){
    printf("Você perdeu!"); 
  }
  else if (opcao_jogador == 1 && opcao_maq == 3){ 
    printf("Você ganhou!");
  } 
  else if (opcao_jogador == 2 && opcao_maq == 1){
    printf("Você ganhou!"); 
  } 
  else if (opcao_jogador == 2 && opcao_maq == 3){
    printf("Você perdeu!");
  } 
  else if (opcao_jogador == 3 && opcao_maq == 1){
    printf("Você perdeu!"); 
  } 
  else if (opcao_jogador == 3 && opcao_maq == 2){ 
    printf("Você ganhou!");
  } 
  else { 
    printf("Empate!"); 
  } 
  return 0; 
}
