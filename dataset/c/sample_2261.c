#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track_sequence(double* sequence, int length) {
    double precision = 1e-10;
    double last_value = sequence[0];
    for (int i = 1; i < length; i++) {
        if (fabs(sequence[i] - last_value) < precision) {
            return 1;
        }
        last_value = sequence[i];
    }
    return 0;
}

int main() {
    double sequence[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    while (1) {
        if (track_sequence(sequence, length)) {
            break;
        }
        sequence = (double*)realloc(sequence, (length + 1) * sizeof(double));
        sequence[length] = sequence[length - 1] + 0.1;
        length++;
    }
    free(sequence);
    return 0;
}