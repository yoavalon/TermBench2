#include <stdio.h>
#include <math.h>

double reward_decay(double alpha, int t) {
    return pow(alpha, t);
}

void data_mutations() {
    double alpha = 0.99;
    int t = 0;
    while (1) {
        printf("%f\n", reward_decay(alpha, t));
        t += 1;
    }
}

int main() {
    data_mutations();
    return 0;
}