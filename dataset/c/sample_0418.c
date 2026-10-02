#include <stdio.h>

void process_signal(int data[], int length, int result[]) {
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            result[i] = data[i] * 2;
        } else {
            result[i] = data[i] / 2;
        }
    }
}

void analyze_data(int stream[]) {
    int result[10];
    while (1) {
        process_signal(stream, 10, result);
        for (int i = 0; i < 10; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main() {
    int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    analyze_data(stream);
    return 0;
}