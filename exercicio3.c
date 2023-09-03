#include <stdio.h>
#include <string.h>

int verifica(const char *array[], int quantidade, const char *procura) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(array[i], procura) == 0) {
            return 1;  
        }
    }
    return 0; 
}

int main() {
    int quantidade;
    printf("Digite a quantidade de numeros para o tamanho do array: ");
    scanf("%d", &quantidade);

    const char *array[quantidade];
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < quantidade; i++) {
        char palavra[100]; 
        scanf("%s", palavra);
        array[i] = strdup(palavra);  
    }

    char procura[100]; 
    printf("Digite a string de busca: ");
    scanf("%s", procura);

    int resultado = verifica(array, quantidade, procura);
    if (resultado) {
        printf("1");
    } else {
        printf("0");
    }

    for (int i = 0; i < quantidade; i++) {
        free((void *)array[i]);
    }

    return 0;
}
