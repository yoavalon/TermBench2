#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_text(const char* data[], int num_texts, float* vectors) {
    for (int i = 0; i < num_texts; i++) {
        for (int j = 0; j < 100 && data[i][j] != '\0'; j++) {
            vectors[i * 100 + j] = (float)(unsigned char)data[i][j] / 255.0f;
        }
    }
}

int main() {
    const char* data[] = {"example text", "another example"};
    int num_texts = sizeof(data) / sizeof(data[0]);
    float* vectors = (float*)malloc(num_texts * 100 * sizeof(float));

    process_text(data, num_texts, vectors);

    for (int i = 0; i < num_texts; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%f ", vectors[i * 100 + j]);
        }
        printf("\n");
    }

    free(vectors);
    return 0;
}