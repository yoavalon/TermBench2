#include <stdio.h>

int optimize_logistics(int data[], int length, int result[], int cap) {
    int seq[100], total = 0;
    int seq_index = 0;

    for (int i = 0; i < length; i++) {
        if (total + data[i] <= cap) {
            seq[seq_index++] = data[i];
            total += data[i];
        } else {
            break;
        }
    }

    for (int i = 0; i < seq_index; i++) {
        result[i] = seq[i];
    }

    return seq_index;
}

int main() {
    int data[] = {10, 20, 30, 40, 50, 60};
    int result[100];
    int length = sizeof(data) / sizeof(data[0]);
    int result_length = optimize_logistics(data, length, result, 50);

    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}