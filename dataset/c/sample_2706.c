#include <stdio.h>
#include <stdlib.h>

void sequence_processor() {
    while (1) {
        const char *data = "example text for vectorization";
        int length = 28; // Length of the string "example text for vectorization"
        int vector[length];
        for (int i = 0; i < length; i++) {
            vector[i] = (int)data[i];
        }
        for (int i = 0; i < length; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
    }
}

int main() {
    sequence_processor();
    return 0;
}