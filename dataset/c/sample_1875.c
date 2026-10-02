#include <stdio.h>

void process_signal(double data[], int length) {
    double a = 0.0;
    double b = 1.0;
    for (int _ = 0; _ < length; _++) {
        double temp = a;
        a = b;
        b = temp + b;
        data[_] += a;
    }
}

int main() {
    double signal[10];
    for (int i = 0; i < 10; i++) {
        signal[i] = 0.1;
    }
    process_signal(signal, 10);
    for (int i = 0; i < 10; i++) {
        printf("%f ", signal[i]);
    }
    return 0;
}