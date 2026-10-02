#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char **corpus;
    int corpus_size;
    int vocabulary_size;
    char **vocabulary;
    int *vocabulary_count;
} Vectorizer;

typedef struct {
    Vectorizer *vectorizer;
} Analysis;

void init_vectorizer(Vectorizer *vectorizer, char **corpus, int corpus_size) {
    vectorizer->corpus = corpus;
    vectorizer->corpus_size = corpus_size;
    vectorizer->vocabulary_size = 0;
    vectorizer->vocabulary = NULL;
    vectorizer->vocabulary_count = NULL;
}

void build_vocabulary(Vectorizer *vectorizer, int index) {
    if (index >= vectorizer->corpus_size) {
        return;
    }
    char *text = vectorizer->corpus[index];
    char *token = strtok(text, " ");
    while (token != NULL) {
        bool found = false;
        for (int i = 0; i < vectorizer->vocabulary_size; i++) {
            if (strcmp(vectorizer->vocabulary[i], token) == 0) {
                vectorizer->vocabulary_count[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            vectorizer->vocabulary = realloc(vectorizer->vocabulary, (vectorizer->vocabulary_size + 1) * sizeof(char *));
            vectorizer->vocabulary_count = realloc(vectorizer->vocabulary_count, (vectorizer->vocabulary_size + 1) * sizeof(int));
            vectorizer->vocabulary[vectorizer->vocabulary_size] = strdup(token);
            vectorizer->vocabulary_count[vectorizer->vocabulary_size] = 1;
            vectorizer->vocabulary_size++;
        }
        token = strtok(NULL, " ");
    }
    build_vocabulary(vectorizer, index + 1);
}

int vectorize(Vectorizer *vectorizer, char *text) {
    int similarity = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < vectorizer->vocabulary_size; i++) {
            if (strcmp(vectorizer->vocabulary[i], token) == 0) {
                similarity += vectorizer->vocabulary_count[i];
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return similarity;
}

void init_analysis(Analysis *analysis, Vectorizer *vectorizer) {
    analysis->vectorizer = vectorizer;
}

int compare_texts(Analysis *analysis, char *text1, char *text2) {
    int vec1 = vectorize(analysis->vectorizer, text1);
    int vec2 = vectorize(analysis->vectorizer, text2);
    return vec1 + vec2;
}

int main() {
    char *corpus[] = {
        "Natural language processing is fascinating",
        "Vectorization is a core technique in NLP",
        "This example demonstrates recursion",
        "Recursion is useful in many algorithms"
    };
    int corpus_size = sizeof(corpus) / sizeof(corpus[0]);

    Vectorizer vectorizer;
    init_vectorizer(&vectorizer, corpus, corpus_size);
    build_vocabulary(&vectorizer, 0);

    Analysis analysis;
    init_analysis(&analysis, &vectorizer);

    int similarity = compare_texts(&analysis, "Natural language processing", "Vectorization in NLP");
    printf("Similarity: %d\n", similarity);

    return 0;
}