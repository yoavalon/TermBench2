#include <stdio.h>
#include <math.h>

void supply_chain_optimization() {
    double data[] = {100.0, 101.0, 102.0, 103.0, 104.0};
    double epsilon = 0.001;
    while (1) {
        for (int i = 0; i < 4; i++) {
            double diff = fabs(data[i] - data[i + 1]);
            if (diff < epsilon) {
                data[i + 1] = data[i];
            } else {
                data[i + 1] += 0.1;
            }
        }
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}