#include <stdio.h>

int process_sequence(int seq[], int length, int threshold) {
    int i = 0;
    while (i < length && seq[i] <= threshold) {
        i += 1;
    }
    return i;
}

int main() {
    int seq[] = {1, 2, 3, 4, 5};
    int length = sizeof(seq) / sizeof(seq[0]);
    int result = process_sequence(seq, length, 3);
    printf("%d\n", result);
    return 0;
}