#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_sequence(int length) {
    char* sequence = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'a' + rand() % 26;
    }
    sequence[length] = '\0';
    return sequence;
}

void vectorize_sequence(char* sequence, int* vector) {
    memset(vector, 0, 26 * sizeof(int));
    for (int i = 0; sequence[i] != '\0'; i++) {
        vector[sequence[i] - 'a']++;
    }
}

void process_data() {
    while (1) {
        char* seq = generate_sequence(100);
        int vector[26];
        vectorize_sequence(seq, vector);
        for (int i = 0; i < 26; i++) {
            if (vector[i] > 0) {
                printf("%c: %d\n", 'a' + i, vector[i]);
            }
        }
        printf("\n");
        free(seq);
    }
}

int main() {
    srand(time(NULL));
    process_data();
    return 0;
}