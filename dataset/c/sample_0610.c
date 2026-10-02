#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int simulate(int state, int threshold, int step) {
    if (abs(state) > threshold) {
        return state;
    }
    return simulate(state + step, threshold, step);
}

int main() {
    int result = simulate(0, 10, 1);
    printf("%d\n", result);
    return 0;
}