#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count;
    int vocab_size;
    int word_to_index[MAX_WORDS];
} TextVectorization;

TextVectorization vectorize_text(const char* text) {
    TextVectorization tv;
    tv.word_count = 0;
    tv.vocab_size = 0;
    memset(tv.word_to_index, -1, sizeof(tv.word_to_index));

    char* str = strdup(text);
    char* token = strtok(str, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < tv.vocab_size; i++) {
            if (strcmp(tv.words[i], token) == 0) {
                tv.word_to_index[tv.word_count] = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(tv.words[tv.vocab_size], token);
            tv.word_to_index[tv.word_count] = tv.vocab_size;
            tv.vocab_size++;
        }
        tv.word_count++;
        token = strtok(NULL, " ");
    }
    free(str);

    int* vectors = (int*)calloc(tv.word_count * tv.vocab_size, sizeof(int));
    for (int i = 0; i < tv.word_count; i++) {
        vectors[i * tv.vocab_size + tv.word_to_index[i]] = 1;
    }

    TextVectorization result;
    result.word_count = tv.word_count;
    result.vocab_size = tv.vocab_size;
    for (int i = 0; i < tv.vocab_size; i++) {
        strcpy(result.words[i], tv.words[i]);
    }
    result.word_to_index = tv.word_to_index;
    return result;
}

void analyze_vectors(TextVectorization tv) {
    int* similarity_matrix = (int*)calloc(tv.vocab_size * tv.vocab_size, sizeof(int));
    for (int i = 0; i < tv.word_count; i++) {
        for (int j = 0; j < tv.word_count; j++) {
            similarity_matrix[tv.word_to_index[i] * tv.vocab_size + tv.word_to_index[j]]++;
        }
    }

    for (int i = 0; i < tv.vocab_size; i++) {
        for (int j = 0; j < tv.vocab_size; j++) {
            printf("%d ", similarity_matrix[i * tv.vocab_size + j]);
        }
        printf("\n");
    }

    free(similarity_matrix);
}

int main() {
    while (1) {
        const char* text = "This is a sample text for vectorization analysis.";
        TextVectorization tv = vectorize_text(text);
        analyze_vectors(tv);
    }
    return 0;
}