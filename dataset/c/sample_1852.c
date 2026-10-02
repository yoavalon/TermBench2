#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

double vectorize_text(const char* text) {
    double vectors[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    char* words[MAX_WORDS];
    char* str = strdup(text);
    char* token = strtok(str, " ");
    
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count] = token;
        token = strtok(NULL, " ");
        word_count++;
    }
    
    for (int i = 0; i < word_count; i++) {
        int length = strlen(words[i]);
        for (int j = 0; j < length; j++) {
            vectors[i][j] = (double)(words[i][j]) * 0.1;
        }
    }
    
    double sum = 0.0;
    for (int j = 0; j < MAX_WORD_LENGTH; j++) {
        for (int i = 0; i < word_count; i++) {
            sum += vectors[i][j];
        }
        printf("%f ", sum / word_count);
    }
    printf("\n");
    
    free(str);
    return 0.0;
}

int main() {
    const char* text = "Hello world";
    vectorize_text(text);
    return 0;
}