#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100

int* process_text(const char* data, int* size) {
    static int sequences[MAX_TOKENS];
    *size = 0;
    char buffer[100];
    int i = 0, j = 0;

    while (data[i]) {
        if (isalpha(data[i]) || isdigit(data[i])) {
            buffer[j++] = data[i];
        } else if (j > 0) {
            buffer[j] = '\0';
            if (isdigit(buffer[0])) {
                sequences[*size] = atoi(buffer);
                (*size)++;
            }
            j = 0;
        }
        i++;
    }
    if (j > 0) {
        buffer[j] = '\0';
        if (isdigit(buffer[0])) {
            sequences[*size] = atoi(buffer);
            (*size)++;
        }
    }
    return sequences;
}

int main() {
    const char* text = "The sequence starts at 1, then 2, 3, and so on until 10.";
    int size;
    int* result = process_text(text, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}