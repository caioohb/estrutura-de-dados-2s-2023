#include <stdio.h>

void maiorEMenor(int array[], int tamanho, int *menor, int *maior) {
    *menor = array[0];
    *maior = array[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
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

    int menor, maior;
    maiorEMenor(array, quantidade, &menor, &maior);

    printf("O menor elemento do array e: %d\n", menor);
    printf("O maior elemento do array e: %d\n", maior);

    return 0;
}
