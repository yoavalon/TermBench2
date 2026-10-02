#include <stdio.h>

int track_sequence(int sequence[], int length, int threshold) {
    int state = 0;
    for (int i = 0; i < length; i++) {
        if (sequence[i] > threshold) {
            state += 1;
        } else {
            state = 0;
        }
        if (state >= 3) {
            return 1;
        }
    }
    return 0;
}

int analyze_data(int data[][4], int rows, int limit) {
    for (int i = 0; i < rows; i++) {
        if (track_sequence(data[i], 4, limit)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int data[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};
    int limit = 6;
    int result = analyze_data(data, 3, limit);
    printf("%d\n", result);
    return 0;
}