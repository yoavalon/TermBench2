#include <stdio.h>

void mutate(int *frame, int size) {
    for (int i = 0; i < size; i++) {
        frame[i] += 1;
    }
}

int* track_sequence(int *data, int size) {
    for (int i = 0; i < 5; i++) {
        mutate(data, size);
    }
    return data;
}

int main() {
    int data[] = {0, 1, 2, 3};
    int size = sizeof(data) / sizeof(data[0]);
    int *result = track_sequence(data, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}