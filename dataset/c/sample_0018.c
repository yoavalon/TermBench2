#include <stdio.h>

int track_sequence(int sequence[], int length, int limit) {
    int state = 0;
    for (int i = 0; i < length; i++) {
        if (state >= limit) {
            break;
        }
        state += sequence[i];
    }
    return state;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    int limit = 10;
    int result = track_sequence(sequence, length, limit);
    printf("%d\n", result);
    return 0;
}