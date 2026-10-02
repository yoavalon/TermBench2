#include <stdio.h>
#include <time.h>

typedef struct {
    int start;
    int step;
} Sequence;

int track_sequence(Sequence *seq) {
    int current = seq->start;
    seq->start += seq->step;
    return current;
}

void monitor(Sequence *seq, int threshold) {
    while (1) {
        int value = track_sequence(seq);
        if (value > threshold) {
            time_t now = time(NULL);
            printf("Threshold exceeded at %s: %d\n", ctime(&now), value);
        } else {
            printf("Current value: %d\n", value);
        }
    }
}

int main() {
    Sequence seq = {1, 2};
    monitor(&seq, 10);
    return 0;
}