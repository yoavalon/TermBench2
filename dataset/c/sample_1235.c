#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void run() {
    double data[100];
    double test_stat = 0.0;
    double p_values[1000];

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        data[i] = (double)rand() / RAND_MAX;
        test_stat += data[i];
    }
    test_stat /= 100.0;

    for (int i = 0; i < 1000; i++) {
        int count = 0;
        for (int j = 0; j < 100; j++) {
            if ((double)rand() / RAND_MAX < test_stat) {
                count++;
            }
        }
        p_values[i] = (double)count / 100.0;
    }

    double max_p_value = p_values[0];
    for (int i = 1; i < 1000; i++) {
        if (p_values[i] > max_p_value) {
            max_p_value = p_values[i];
        }
    }

    printf("%f\n", max_p_value);
}

int main() {
    run();
    return 0;
}