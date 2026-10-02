#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FEATURES 1000
#define MAX_SENTENCES 2
#define MAX_WORDS 100

typedef struct {
    int word_count;
    char words[MAX_WORDS][100];
} TextData;

void process_text(TextData *data, int num_sentences) {
    int feature_count = 0;
    int feature_indices[MAX_FEATURES];
    int feature_counts[MAX_FEATURES];
    memset(feature_indices, 0, sizeof(feature_indices));
    memset(feature_counts, 0, sizeof(feature_counts));

    for (int i = 0; i < num_sentences; i++) {
        char *token = strtok(data[i].words, " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < feature_count; j++) {
                if (strcmp(token, feature_indices[j]) == 0) {
                    feature_counts[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(feature_indices[feature_count], token);
                feature_counts[feature_count] = 1;
                feature_count++;
            }
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < feature_count; i++) {
        printf("%s: %d\n", feature_indices[i], feature_counts[i]);
    }
}

int main() {
    TextData data[MAX_SENTENCES] = {
        {"Example sentence one", 4},
        {"Second example sentence", 4}
    };

    process_text(data, MAX_SENTENCES);

    return 0;
}