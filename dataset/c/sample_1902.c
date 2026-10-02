#include <stdio.h>
#include <math.h>

int track_sequence(double seq[], int precision, int length) {
    double threshold = pow(10, -precision);
    for (int i = 1; i < length; i++) {
        if (fabs(seq[i] - seq[i - 1]) < threshold) {
            return i;
        }
    }
    return -1;
}

int main() {
    double sequence[] = {0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002};
    int precision = 9;
    int index = track_sequence(sequence, precision, 6);
    if (index != -1) {
        printf("Precision achieved at index: %d\n", index);
    } else {
        printf("No precision match found\n");
    }
    return 0;
}