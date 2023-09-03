#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void lerPontosArquivo(const char *nomeArquivo, Ponto **pontos, int *numPontos) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    int numRegistros = 0;
    while (!feof(arquivo)) {
        int x;
        float y;
        if (fscanf(arquivo, "%d,%f\n", &x, &y) == 2) {
            numRegistros++;
        }
    }

    *numPontos = numRegistros;
    *pontos = (Ponto *)malloc(numRegistros * sizeof(Ponto));

    fseek(arquivo, 0, SEEK_SET);
    int i = 0;
    while (!feof(arquivo)) {
        int x;
        float y;
        if (fscanf(arquivo, "%d,%f\n", &x, &y) == 2) {
            (*pontos)[i].x = x;
            (*pontos)[i].y = y;
            i++;
        }
    }

    fclose(arquivo);
}

void regressaoLinear(const Ponto *pontos, int numPontos, float *coeficienteAngular, float *coeficienteLinear) {
    int somX = 0;
    float somY = 0.0;
    float somXY = 0.0;
    float somXQuadrado = 0.0;

    for (int i = 0; i < numPontos; i++) {
        somX += pontos[i].x;
        somY += pontos[i].y;
        somXY += pontos[i].x * pontos[i].y;
        somXQuadrado += pontos[i].x * pontos[i].x;
    }

    float medX = (float)somX / numPontos;
    float medY = somY / numPontos;

    *coeficienteAngular = (somXY - numPontos * medX * medY) / (somXQuadrado - numPontos * medX * medX);
    *coeficienteLinear = medY - (*coeficienteAngular) * medX;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s <dados.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *nomeArquivo = argv[1];
    Ponto *pontos;
    int numPontos;

    lerPontosArquivo(nomeArquivo, &pontos, &numPontos);

    float coeficienteAngular, coeficienteLinear;
    regressaoLinear(pontos, numPontos, &coeficienteAngular, &coeficienteLinear);

    printf("Equacao: y = %.2fx + %.2f\n", coeficienteAngular, coeficienteLinear);

    free(pontos);

    return EXIT_SUCCESS;
}
