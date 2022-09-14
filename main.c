#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

void printByte(unsigned char a) {
    for (int i = 7; i >= 0; --i) {
        printf("%d", (a >> i) & 1);
    }
}

void printVar(void *a, size_t size) {
    char *var = (char *) a;

    char *bytes = (char *) malloc(size);

    for (int i = 0; i < size; ++i) {
        int r = var[i];
        bytes[i] = var[i];
    }

    for (int i = 0; i < size; ++i) {
        printf("%d\n", bytes[i]);
    }

    for (int i = size - 1; i >= 0; --i)
        printByte(bytes[i]);

    printf("\n");

    int *v = bytes;
    printf("%ld\n", *v);
}

char *getBytesArray(char *str) {
    size_t size = strlen(str) / 8;
    char *bytes = calloc(size / 8, sizeof(char));

    int index = 0;
    for (int i = size - 1; i >= 0; --i) {
        int power = 0;
        for (int j = 7; j >= 0; --j) {
            if (str[i * 8 + j] == '1')
                bytes[index] |= 1 << power;

            power++;
        }
        index++;
    }

    for (int i = 0; i < size; ++i) {
        printf("%d\n", bytes[i]);
    }

    for (int i = size - 1; i >= 0; --i)
        printByte(bytes[i]);

    printf("\n");

    return bytes;
}

int main() {
    int v = 12345; // 00000000000000000011000000111001
    printVar(&v, sizeof(int));
    printf("\n");

    char *str = "00000000000000000011000000111001";
    char *bytes = getBytesArray(str);

    int *var = (int *) bytes;
    printf("%d", var);

    return 0;
}