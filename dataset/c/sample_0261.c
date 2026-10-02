#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_DATA 3
#define MAX_WORD_LENGTH 50

typedef struct {
    char words[MAX_DATA][MAX_WORDS][MAX_WORD_LENGTH];
    int word_counts[MAX_DATA][MAX_WORDS];
    int vocab_count;
} Vectorizer;

typedef struct {
    Vectorizer *vectorizer;
} Processor;

void Vectorizer_init(Vectorizer *v, const char *data[]) {
    for (int i = 0; i < MAX_DATA; i++) {
        char *token = strtok((char *)data[i], " ");
        int word_index = 0;
        while (token != NULL) {
            for (int j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }
            strcpy(v->words[i][word_index], token);
            word_index++;
            token = strtok(NULL, " ");
        }
    }
}

void Vectorizer_create_vocabulary(Vectorizer *v) {
    bool vocab[MAX_WORDS];
    memset(vocab, 0, sizeof(vocab));
    v->vocab_count = 0;
    for (int i = 0; i < MAX_DATA; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (v->words[i][j][0] == '\0') break;
            bool is_new = true;
            for (int k = 0; k < v->vocab_count; k++) {
                if (strcmp(v->words[i][j], v->words[k][0]) == 0) {
                    is_new = false;
                    break;
                }
            }
            if (is_new) {
                strcpy(v->words[v->vocab_count][0], v->words[i][j]);
                v->vocab_count++;
            }
        }
    }
}

void Vectorizer_vectorize(Vectorizer *v) {
    memset(v->word_counts, 0, sizeof(v->word_counts));
    for (int i = 0; i < MAX_DATA; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (v->words[i][j][0] == '\0') break;
            for (int k = 0; k < v->vocab_count; k++) {
                if (strcmp(v->words[i][j], v->words[k][0]) == 0) {
                    v->word_counts[i][k]++;
                    break;
                }
            }
        }
    }
}

void Processor_init(Processor *p, Vectorizer *v) {
    p->vectorizer = v;
}

void Processor_run_pipeline(Processor *p) {
    Vectorizer_create_vocabulary(p->vectorizer);
    Vectorizer_vectorize(p->vectorizer);
}

void main() {
    const char *data[] = {
        "The quick brown fox jumps over the lazy dog",
        "Never jump over a lazy dog quickly",
        "A quick brown dog outpaces a lazy fox"
    };
    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, data);
    Processor processor;
    Processor_init(&processor, &vectorizer);
    Processor_run_pipeline(&processor);
    for (int i = 0; i < MAX_DATA; i++) {
        for (int j = 0; j < vectorizer.vocab_count; j++) {
            printf("%d ", vectorizer.word_counts[i][j]);
        }
        printf("\n");
    }
}