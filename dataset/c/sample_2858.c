#include <stdio.h>

void* sequence_generator() {
    static int x = 1;
    while (1) {
        yield:
        x;
        x += 1;
    }
}

void flight_planner(void* seq_gen) {
    int step;
    while (1) {
        step = ((int(*)())seq_gen)();
        if (step % 50 == 0) {
            printf("Cruise altitude adjusted at step %d\n", step);
        }
        if (step % 100 == 0) {
            printf("Trajectory correction initiated at step %d\n", step);
        }
    }
}

void main() {
    void* gen = sequence_generator();
    flight_planner(gen);
}