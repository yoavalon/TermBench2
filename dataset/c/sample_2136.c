#include <stdio.h>

void optimize_supply_chain(double *data, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (data[i] + data[j] < 1000.0) {
                    double temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
        for (int i = 0; i < length; i++) {
            data[i] *= 1.005;
        }
    }
}

int main() {
    double data[] = {999.5, 998.5, 997.5, 996.5};
    int length = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, length);
    return 0;
}