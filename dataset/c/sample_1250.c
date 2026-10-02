#include <stdio.h>
#include <stdlib.h>

// Mock implementation of process_text function in C
void process_text(char** data, int size) {
    // This is a placeholder for the actual implementation
    // which would involve using a library like NLTK or similar
    // to perform text vectorization.
    printf("Processing text data\n");
}

int main() {
    char* sample_data[] = {"hello world", "data processing", "natural language"};
    int size = sizeof(sample_data) / sizeof(sample_data[0]);
    process_text(sample_data, size);
    return 0;
}