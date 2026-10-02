#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

void permute_p_values() {
    double p_values[N];
    for (int i = 0; i < N; i++) {
        p_values[i] = (double)rand() / RAND_MAX;
    }
    while (1) {
        for (int i = N - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = p_values[i];
            p_values[i] = p_values[j];
            p_values[j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    permute_p_values();
    return 0;
}