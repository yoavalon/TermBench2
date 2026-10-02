#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_options(double prices[], int days) {
    while (1) {
        for (int d = 0; d < days; d++) {
            for (int i = 0; i < 3; i++) {
                prices[i] *= 1 + (rand() / (double)RAND_MAX - 0.5) * 0.1;
            }
        }
        for (int i = 0; i < 3; i++) {
            printf("%f ", prices[i]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    double start_prices[] = {100, 150, 200};
    int days = 5;
    srand(time(NULL));
    simulate_options(start_prices, days);
    return 0;
}