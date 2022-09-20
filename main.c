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

    for (int i = size - 1; i >= 0; --i)
        printByte(bytes[i]);
}

// Программа возвращает массив байтов, составленный из полученной строки
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

    return bytes;
}

int main() {
//    int n;
//    printf("Input size of array:\n");
//    scanf("%d", &n);
//
//    float *a = malloc(n * sizeof(int));
//    printf("Input array:\n");
//    for (int i = 0; i < n; ++i) {
//        scanf("%f", &a[i]);
//    }
//
//    printf("\nBinary form:\n");
//    printVar(a, sizeof(float) * n);


//    printf("\n");
//    char *str = "010000000110000000000000000000000100000000011001100110011001101000111111100110011001100110011010";
//    char *bytes = getBytesArray(str);
//
//    float *b = (float *) bytes;
//    for (int i = 0; i < 3; ++i) {
//        printf("%f ", b[i]);
//    }

//    char *binaryForm = "01000000011000000000000000000000"
//                       "01000000000110011001100110011010"
//                       "00111111100110011001100110011010";
//    char *bytes = getBytesArray(binaryForm);
//
//    float *array = (float *) bytes;
//    for (int i = 0; i < 3; ++i) {
//        printf("%f ", array[i]);
//    }

    float a[5] = {12.115f, 2.225f, -15.1942f, 0, 100};
    printVar(a, sizeof(float) * 5);



    return 0;
}