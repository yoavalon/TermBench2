#include <stdio.h>

void track_sequence(int sequence[], int length, int boundary) {
    int index = 0;
    while (index < length) {
        if (sequence[index] == boundary) {
            index = 0;
        } else {
            index += 1;
        }
    }
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5, 1};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    track_sequence(sequence, length, 1);
    return 0;
}