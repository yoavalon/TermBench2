#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FEATURES 100
#define MAX_DOCUMENTS 3
#define MAX_WORDS 10

typedef struct {
    int features[MAX_FEATURES];
} FeatureVector;

void process_text(char* data[MAX_DOCUMENTS], FeatureVector* result) {
    int word_count[MAX_FEATURES] = {0};
    char words[MAX_FEATURES][MAX_WORDS];

    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        char* token = strtok(data[i], " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < MAX_FEATURES; j++) {
                if (strcmp(words[j], token) == 0) {
                    word_count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (int j = 0; j < MAX_FEATURES; j++) {
                    if (words[j][0] == '\0') {
                        strcpy(words[j], token);
                        word_count[j]++;
                        break;
                    }
                }
            }
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < MAX_FEATURES; i++) {
        result->features[i] = word_count[i];
    }
}

int main() {
    char* data[MAX_DOCUMENTS] = {
        "hello world",
        "python programming",
        "natural language processing"
    };

    FeatureVector result;
    process_text(data, &result);

    for (int i = 0; i < MAX_FEATURES; i++) {
        printf("%d ", result.features[i]);
    }
    printf("\n");

    return 0;
}