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
    char *begin = (char *) a;

    char *bytes = (char *) malloc(size);

    for (int i = 0; i < size; ++i) {
        bytes[i] = begin[i];
    }

    for (int i = size - 1; i >= 0; --i) {
        printByte(bytes[i]);
    }
}

char *getBytesArray(char *str) {
    size_t size = strlen(str) / 8;
//    char *rbegin = str + size - 1;
//    char *rend = str;
    char *bytes = calloc(size / 8, sizeof(char));
//    int j = 0;
//    while (rbegin > rend) {
//        for (int i = 0; i < 8; ++i) {
//            int k = *rbegin == '1' << i;
//            bytes[j] |= k;
//            rbegin--;
//        }
//        j++;
//    }

    for (int i = 0; i < size ; ++i) {
        int power = 0;
        for (int j = 7; j >= 0; --j) {
            int r;
            char l = str[i + j];
            int k = (l == '1') << power++;
            bytes[i] |= k;
            r = bytes[i];
        }
    }

    return bytes;
}

int getDecimal(char *str) {
    int dec = 0;
    size_t power = strlen(str) - 1;
    int flag = *str;
    while (*str != '\0') {
        if (*str == '1')
            dec += 1 << power;

        power--;
        str++;
    }

    if (flag)
        return -dec;

    return dec;
}

int main() {
//    while(1) {
//        float a;
//        printf("Number:\n");
//        scanf("%f", &a);
//        printf("Binary form:");
//        printVar(&a, sizeof(float));
//        printf("\n");
//    }

//    char *str = "12341";
//    char *rbegin = str + strlen(str) - 1;
////    printf("%d\n", strlen(str));
//    printf("%c\n", *rbegin);
//    rbegin--;
//    printf("%c\n", *rbegin);
//    rbegin--;
//    printf("%c\n", *rbegin);
//    printf("%c\n", *str);

    char *s = "10001010";

    char *bytes = getBytesArray(s);

    for (int i = 0; i < 1; ++i) {
        printf("%d", bytes[i]);
    }


    return 0;
}
