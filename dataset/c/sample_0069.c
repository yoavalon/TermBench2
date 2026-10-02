#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void vectorize_text(char* data[], int data_size, int vec[data_size][MAX_LENGTH]) {
    for (int i = 0; i < data_size; i++) {
        for (int j = 0; j < MAX_LENGTH && data[i][j] != '\0'; j++) {
            vec[i][j] = (unsigned char)data[i][j] % 256;
        }
    }
}

int main() {
    char* sample_data[] = {"hello", "world", "example"};
    int data_size = sizeof(sample_data) / sizeof(sample_data[0]);
    int result[data_size][MAX_LENGTH];

    vectorize_text(sample_data, data_size, result);

    for (int i = 0; i < data_size; i++) {
        for (int j = 0; j < MAX_LENGTH && sample_data[i][j] != '\0'; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}