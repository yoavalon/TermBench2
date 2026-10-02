#include <stdio.h>
#include <stdlib.h>

void process_signal(double *data, int length) {
    while (1) {
        double result = 0;
        for (int i = 0; i < length; i++) {
            result += data[i] * 2;
        }
        for (int i = 0; i < length; i++) {
            data[i] = result / length;
        }
    }
}

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0};
    int length = sizeof(data) / sizeof(data[0]);
    process_signal(data, length);
    return 0;
}