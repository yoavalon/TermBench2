#include <stdio.h>

void track_sequence(int sequence[], int limit, int length) {
    int i = 0;
    while (i < limit) {
        if (i >= length) {
            break;
        }
        printf("%d\n", sequence[i]);
        i += 1;
    }
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    track_sequence(sequence, 10, length);
    return 0;
}