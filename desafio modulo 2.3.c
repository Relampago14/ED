//Você foi contratado para desenvolver um sistema a ser usado em uma enquete. A empresa que o contratou precisa tabelar os resultados da seguinte enquete, feita a uma grande quantidade de organizações:
//Qual o melhor sistema operacional para uso em servidores?
//As possíveis respostas são:
//1- Windows Server.
//2 - Unix.
//3 - Linux.
//4 - Netware.
//5 - Mac OS.
//6 - Outro.
//O programa deverá ler os valores até ser informado o valor 0, que encerra a entrada dos dados. Não deverão ser aceitos valores além dos válidos para o programa (0 a 6).
//Após os dados terem sido completamente informados, o programa deverá calcular a percentual de cada um dos concorrentes.
//Ao final, devem ser mostrados todos os sistemas operacionais com a quantidade de votos e o percentual de cada um.

#include <stdio.h>

int main() {
    int op=9, soma_op1 = 0, soma_op2 = 0, soma_op3 = 0, soma_op4 = 0, soma_op5 = 0, soma_op6 = 0;
    float soma_total = 0;
    
    printf("Qual o melhor sistema operacional para uso em servidores?\n");
    printf("1- Windows Server.\n2 - Unix.\n3 - Linux.\n4 - Netware.\n5 - Mac OS.\n6 - Outro.\n");
    
    while (op!=0){
        scanf("%d", &op);
        switch(op){
            case 0:
                break;
            case 1:
                soma_op1++;
                soma_total++;
                break;
            case 2:
                soma_op2++;
                soma_total++;
                break;
            case 3:
                soma_op3++;
                soma_total++;
                break;
            case 4:
                soma_op4++;
                soma_total++;
                break;
            case 5:
                soma_op5++;
                soma_total++;
                break;
            case 6:
                soma_op6++;
                soma_total++;
                break;
            default:
                printf("Opção Inválida\n");
        }
    }
    
    printf("Windows Server recebeu %d votos - %.2f%%\n", soma_op1, soma_op1/soma_total*100);
    printf("Unix recebeu %d votos - %.2f%%\n", soma_op2, soma_op2/soma_total*100);
    printf("Linux recebeu %d votos - %.2f%%\n", soma_op3, soma_op3/soma_total*100);
    printf("Netware recebeu %d votos - %.2f%%\n", soma_op4, soma_op4/soma_total*100);
    printf("Mac OS recebeu %d votos - %.2f%%\n", soma_op5, soma_op5/soma_total*100);
    printf("Outro recebeu %d votos - %.2f%%\n", soma_op6, soma_op6/soma_total*100);

    return 0;
}
