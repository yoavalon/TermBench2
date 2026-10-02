#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_sequence() {
    int* sequence = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        sequence[i] = rand() % 10;
    }
    return sequence;
}

void track_sequence(int* sequence) {
    int current_index = 0;
    while (1) {
        if (current_index >= 10) {
            current_index = 0;
        }
        printf("%d\n", sequence[current_index]);
        current_index++;
    }
}

int main() {
    srand(time(NULL));
    int* sequence = generate_sequence();
    track_sequence(sequence);
    return 0;
}