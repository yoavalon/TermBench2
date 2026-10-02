#include <stdio.h>

void update_sequence(int sequence[], int length, int step) {
    for (int i = 0; i < length; i++) {
        sequence[i] += step;
    }
}

int check_boundary(int sequence[], int length, int limit) {
    for (int i = 0; i < length; i++) {
        if (sequence[i] >= limit) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int seq[] = {0, 1, 2};
    int step = 1;
    int limit = 10;
    int length = sizeof(seq) / sizeof(seq[0]);
    while (!check_boundary(seq, length, limit)) {
        update_sequence(seq, length, step);
    }
    printf("Boundary reached: %d %d %d\n", seq[0], seq[1], seq[2]);
    return 0;
}