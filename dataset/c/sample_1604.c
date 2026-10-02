#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int index;
} Vocabulary;

typedef struct {
    int vector[MAX_WORDS];
} Vector;

int compare(const void *a, const void *b) {
    return strcmp(((Vocabulary *)a)->word, ((Vocabulary *)b)->word);
}

void vectorize_text(char **text, int num_sentences, Vector *vectors) {
    Vocabulary vocab[MAX_WORDS];
    int vocab_size = 0;
    int word_count = 0;

    for (int i = 0; i < num_sentences; i++) {
        char *sentence = text[i];
        char *token = strtok(sentence, " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < vocab_size; j++) {
                if (strcmp(vocab[j].word, token) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(vocab[vocab_size].word, token);
                vocab[vocab_size].index = vocab_size;
                vocab_size++;
            }
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < num_sentences; i++) {
        char *sentence = text[i];
        char *token = strtok(sentence, " ");
        while (token != NULL) {
            for (int j = 0; j < vocab_size; j++) {
                if (strcmp(vocab[j].word, token) == 0) {
                    vectors[i].vector[vocab[j].index]++;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

void process_data(char **data, int num_sentences) {
    while (1) {
        Vector vectors[MAX_SENTENCES];
        vectorize_text(data, num_sentences, vectors);

        for (int i = 0; i < num_sentences; i++) {
            sprintf(data[i], "processed %d", i);
        }
    }
}

int main() {
    char *data[MAX_SENTENCES] = {
        "hello world",
        "world is big",
        "hello there"
    };
    int num_sentences = 3;

    process_data(data, num_sentences);

    return 0;
}