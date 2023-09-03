#include <stdio.h>
#include <stdlib.h>

int verificaPrimo(int numero) {
    if (numero <= 1) {
        return 0;  
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  
        }
    }

    return 1; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(" %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (verificaPrimo(numero)) {
        printf("1 O numero %d e primo.\n", numero);
    } else {
        printf("0 - O numero %d nao e primo.\n", numero);
    }

    return 0;
}
