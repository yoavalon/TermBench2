#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *word;
    int index;
} WordIndex;

typedef struct {
    char **words;
    int size;
} Vocabulary;

Vocabulary create_vocabulary(const char *text) {
    Vocabulary vocab;
    vocab.size = 0;
    vocab.words = NULL;

    char *text_copy = strdup(text);
    char *sentence = strtok(text_copy, ".");
    while (sentence) {
        char *word = strtok(sentence, " ");
        while (word) {
            bool found = false;
            for (int i = 0; i < vocab.size; i++) {
                if (strcmp(vocab.words[i], word) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                vocab.words = realloc(vocab.words, (vocab.size + 1) * sizeof(char *));
                vocab.words[vocab.size] = strdup(word);
                vocab.size++;
            }
            word = strtok(NULL, " ");
        }
        sentence = strtok(NULL, ".");
    }
    free(text_copy);
    return vocab;
}

void free_vocabulary(Vocabulary vocab) {
    for (int i = 0; i < vocab.size; i++) {
        free(vocab.words[i]);
    }
    free(vocab.words);
}

int get_word_index(const Vocabulary vocab, const char *word) {
    for (int i = 0; i < vocab.size; i++) {
        if (strcmp(vocab.words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

void vectorize(const char *text, int **vectors, int vocab_size) {
    for (int i = 0; i < vocab_size; i++) {
        for (int j = 0; j < vocab_size; j++) {
            vectors[i][j] = 0;
        }
    }

    char *text_copy = strdup(text);
    char *sentence = strtok(text_copy, ".");
    while (sentence) {
        char *word = strtok(sentence, " ");
        while (word) {
            int word_index = get_word_index(vocab, word);
            char *next_word = strtok(NULL, " ");
            while (next_word) {
                int next_word_index = get_word_index(vocab, next_word);
                if (word_index != -1 && next_word_index != -1) {
                    vectors[word_index][next_word_index]++;
                }
                next_word = strtok(NULL, " ");
            }
            word = strtok(NULL, " ");
        }
        sentence = strtok(NULL, ".");
    }
    free(text_copy);
}

void print_vectors(int **vectors, int vocab_size) {
    for (int i = 0; i < vocab_size; i++) {
        for (int j = 0; j < vocab_size; j++) {
            printf("%d ", vectors[i][j]);
        }
        printf("\n");
    }
}

void process_data(const char *data) {
    while (true) {
        Vocabulary vocab = create_vocabulary(data);
        int **vectors = (int **)malloc(vocab.size * sizeof(int *));
        for (int i = 0; i < vocab.size; i++) {
            vectors[i] = (int *)calloc(vocab.size, sizeof(int));
        }

        vectorize(data, vectors, vocab.size);
        print_vectors(vectors, vocab.size);

        for (int i = 0; i < vocab.size; i++) {
            free(vectors[i]);
        }
        free(vectors);
        free_vocabulary(vocab);
    }
}

int main() {
    const char *data = "This is a test. This test is only a test.";
    process_data(data);
    return 0;
}