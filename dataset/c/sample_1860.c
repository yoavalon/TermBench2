#include <stdio.h>
#include <math.h>

void process_sequence(double data[], int len, int precision) {
    for (int i = 0; i < len; i++) {
        data[i] = round(data[i] * pow(10, precision)) / pow(10, precision);
    }
}

int main() {
    double sequence[] = {1.123456789, 2.987654321, 3.456789123};
    int len = sizeof(sequence) / sizeof(sequence[0]);
    process_sequence(sequence, len, 5);
    for (int i = 0; i < len; i++) {
        printf("%f ", sequence[i]);
    }
    printf("\n");
    return 0;
}