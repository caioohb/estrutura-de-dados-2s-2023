#include <stdio.h>

void multiplicar(int array1[], int array2[], int result[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        result[i] = array1[i] * array2[i];
    }
}

int main() {
    int quantidade;
    printf("Digite a quantidade de numeros para o tamanho do array: ");
    scanf("%d", &quantidade);

    int array1[quantidade];
    int array2[quantidade];
    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &array2[i]);
    }

    int result[quantidade];
    multiplicar(array1, array2, result, quantidade);

    printf("Multiplicaçao dos arrays:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
