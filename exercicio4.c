#include <stdio.h>

int contarAparicoes(int array[], int quantidade, int procura) {
    int cont = 0;
    for (int i = 0; i < quantidade; i++) {
        if (array[i] == procura) {
            cont++;
        }
    }
    return cont;
}

int main() {
    int quantidade;
    printf("Digite a quantidade de numeros para o tamanho do array: ");
    scanf("%d", &quantidade);

    int array[quantidade];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &array[i]);
    }

    int procura;
    printf("Digite o numero de busca: ");
    scanf("%d", &procura);

    int aparece = contarAparicoes(array, quantidade, procura);
    printf("O numero %d aparece %d vezes no array.\n", procura, aparece);

    return 0;
}
