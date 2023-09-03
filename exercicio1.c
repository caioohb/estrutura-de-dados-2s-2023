#include <stdio.h>

int somaArray(int array[], int quantidade) {
    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += array[i];
    }
    return soma;
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

    int soma = somaArray(array, quantidade);
    printf("A soma dos elementos do array e: %d\n", soma);

    return 0;
}
