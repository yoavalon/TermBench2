#include <stdio.h>

void process_signal(int data[], int threshold, int filtered[], int *filtered_size) {
    *filtered_size = 0;
    for (int i = 0; i < 10; i++) {
        if (data[i] > threshold) {
            filtered[(*filtered_size)++] = data[i];
        }
    }
}

int main() {
    int signal[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int threshold = 50;
    int filtered[10];
    int filtered_size;

    process_signal(signal, threshold, filtered, &filtered_size);

    for (int i = 0; i < filtered_size; i++) {
        printf("%d ", filtered[i]);
    }
    printf("\n");

    return 0;
}