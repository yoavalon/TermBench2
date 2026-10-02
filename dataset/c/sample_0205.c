#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_ITEM_LENGTH 100

typedef struct {
    char data[MAX_ITEMS][MAX_ITEM_LENGTH];
    int data_count;
    int vectorized_data[MAX_ITEMS][MAX_ITEM_LENGTH];
} DataProcessor;

typedef struct {
    char* results[MAX_ITEMS];
    int counts[MAX_ITEMS];
} ReportGenerator;

void DataProcessor_init(DataProcessor* self, const char* data[], int data_count) {
    self->data_count = data_count;
    for (int i = 0; i < data_count; i++) {
        strcpy(self->data[i], data[i]);
    }
}

void DataProcessor_preprocess(DataProcessor* self) {
    for (int i = 0; i < self->data_count; i++) {
        for (int j = 0; self->data[i][j] != '\0'; j++) {
            if (ispunct(self->data[i][j])) {
                memmove(&self->data[i][j], &self->data[i][j + 1], strlen(self->data[i]) - j);
                j--;
            } else {
                self->data[i][j] = tolower(self->data[i][j]);
            }
        }
        strcpy(self->vectorized_data[i], self->data[i]);
    }
}

void DataProcessor_tokenize(DataProcessor* self) {
    // This is a placeholder for tokenization logic.
    // In a real scenario, you would use a library or implement a custom tokenizer.
    for (int i = 0; i < self->data_count; i++) {
        for (int j = 0; self->vectorized_data[i][j] != '\0'; j++) {
            if (isspace(self->vectorized_data[i][j])) {
                self->vectorized_data[i][j] = '\0';
                j++;
                while (isspace(self->vectorized_data[i][j])) {
                    j++;
                }
                j--;
            }
        }
    }
}

void DataProcessor_analyze(DataProcessor* self, ReportGenerator* reporter) {
    for (int i = 0; i < self->data_count; i++) {
        int word_count = 0;
        for (int j = 0; self->vectorized_data[i][j] != '\0'; j++) {
            if (isspace(self->vectorized_data[i][j])) {
                word_count++;
            }
        }
        word_count++; // Count the last word
        char key[50];
        sprintf(key, "item_%d", i);
        reporter->results[i] = strdup(key);
        reporter->counts[i] = word_count;
    }
}

void ReportGenerator_init(ReportGenerator* self) {
    // No initialization needed for this simple example.
}

void ReportGenerator_generate(ReportGenerator* self) {
    printf("Analysis Report:\n");
    for (int i = 0; self->results[i] != NULL; i++) {
        printf("%s: %d words\n", self->results[i], self->counts[i]);
    }
}

int main() {
    const char* data[] = {
        "Hello world!",
        "This is a test sentence.",
        "Natural language processing is fascinating.",
        "Python is great for data science.",
        "Machine learning and AI are changing the world."
    };
    int data_count = sizeof(data) / sizeof(data[0]);

    DataProcessor processor;
    ReportGenerator reporter;

    DataProcessor_init(&processor, data, data_count);
    DataProcessor_preprocess(&processor);
    DataProcessor_tokenize(&processor);
    DataProcessor_analyze(&processor, &reporter);

    ReportGenerator_init(&reporter);
    ReportGenerator_generate(&reporter);

    // Free allocated memory
    for (int i = 0; reporter.results[i] != NULL; i++) {
        free(reporter.results[i]);
    }

    return 0;
}