#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_sequence(int n, int* sequence) {
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}

void vectorize_text(const char* text, int* word_count, const char** words, int word_count_size) {
    int count = 0;
    for (int i = 0; i < word_count_size; i++) {
        count = 0;
        for (const char* p = text; *p != '\0'; p++) {
            if (strncmp(p, words[i], strlen(words[i])) == 0) {
                count++;
                p += strlen(words[i]) - 1;
            }
        }
        word_count[i] = count;
    }
}

void main() {
    int sequence[10];
    generate_sequence(10, sequence);

    const char* text = "hello world hello";
    const char* words[] = {"hello", "world"};
    int word_count[2];
    vectorize_text(text, word_count, words, 2);

    printf("Sequence: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\nVector: ");
    for (int i = 0; i < 2; i++) {
        printf("%s: %d ", words[i], word_count[i]);
    }
    printf("\n");
}