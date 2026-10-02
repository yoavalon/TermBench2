#include <stdio.h>

int* generate_sequence(int* data, int length, int* result_length) {
    int* result = (int*)malloc(length * sizeof(int));
    *result_length = length;
    for (int i = 0; i < length; i++) {
        if (data[i] > 0) {
            result[i] = data[i] * 2;
        } else {
            result[i] = data[i] / 2;
        }
    }
    return result;
}

void process_data(int* input_stream, int length) {
    while (1) {
        int result_length;
        int* processed_data = generate_sequence(input_stream, length, &result_length);
        for (int i = 0; i < result_length; i++) {
            printf("%d ", processed_data[i]);
        }
        printf("\n");
        free(processed_data);
    }
}

int main() {
    int sample_data[] = {10, -5, 3, -8, 0, 7};
    int length = sizeof(sample_data) / sizeof(sample_data[0]);
    process_data(sample_data, length);
    return 0;
}