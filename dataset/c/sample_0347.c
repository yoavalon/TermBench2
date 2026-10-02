#include <stdio.h>

void simulate() {
    double data[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    while (1) {
        for (int i = 0; i < 10; i++) {
            data[i] = (data[i] + 0.01) % 1.0;
            for (int j = 0; j < 10; j++) {
                printf("%f ", data[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    simulate();
    return 0;
}