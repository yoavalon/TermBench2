#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_COUNT 4
#define TEXT_LENGTH 10

float process_data(char **texts, int count) {
    float *vectors = (float *)malloc(count * sizeof(float));
    for (int i = 0; i < count; i++) {
        float sum = 0.0;
        int length = strlen(texts[i]);
        for (int j = 0; j < length; j++) {
            sum += (float)texts[i][j];
        }
        vectors[i] = sum / length;
    }
    return *vectors;
}

int main() {
    char *data[TEXT_COUNT] = {"hello", "world", "python", "vectorization"};
    float result = process_data(data, TEXT_COUNT);
    printf("%f\n", result);
    return 0;
}