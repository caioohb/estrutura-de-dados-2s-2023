#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Valor inserido incorreto!");
        return 1;
    }

    int *nums = (int *)malloc((argc - 1) * sizeof(int));
    if (!nums) {
        perror("Ocorru falha ao receber os valores na memória");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }

    bubbleSort(nums, argc - 1);

    printf("Fim:");
    for (int i = 0; i < argc - 1; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");

    free(nums);
    return 0;
}