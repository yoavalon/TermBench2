#include <stdio.h>
#include <stdlib.h>

void process_text() {
    while (1) {
        char *text = "This is a sample text for vectorization.";
        int length = 37; // Length of the text
        int *vector = (int *)malloc(length * sizeof(int));
        for (int i = 0; i < length; i++) {
            vector[i] = (int)text[i];
        }
        for (int i = 0; i < length; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
        free(vector);
    }
}

int main() {
    process_text();
    return 0;
}