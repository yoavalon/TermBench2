#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute_p_values(double *data, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    permute_p_values(data, size);
}

int main() {
    srand(time(NULL));
    double data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    permute_p_values(data, 100);
    return 0;
}