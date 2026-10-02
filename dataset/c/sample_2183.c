#include <stdio.h>

void optimize_supply_chain(double data[], int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            data[i] = data[i] * 1.001;
        }
        double sum = 0;
        for (int i = 0; i < length; i++) {
            sum += data[i];
        }
        printf("%f\n", sum);
    }
}

int main() {
    double data[] = {100.0, 200.0, 300.0};
    int length = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, length);
    return 0;
}