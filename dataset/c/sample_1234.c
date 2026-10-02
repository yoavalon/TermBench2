#include <stdio.h>
#include <stdbool.h>

bool track_sequence(int seq[], int target, int max_steps) {
    int step = 0;
    while (seq[0] != '\0' && step < max_steps) {
        if (seq[0] == target) {
            return true;
        }
        seq = &seq[1];
        step += 1;
    }
    return false;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5, '\0'};
    bool result = track_sequence(sequence, 4, 10);
    printf("%d\n", result);
    return 0;
}