#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_paths(int steps, int simulations, int paths[][100]) {
    for (int i = 0; i < simulations; i++) {
        paths[i][0] = 0;
        for (int j = 1; j < steps; j++) {
            paths[i][j] = paths[i][j - 1] + (rand() % 2 ? 1 : -1);
        }
    }
}

double calculate_option_value(int paths[][100], int simulations, int strike_price, int payoff) {
    double values = 0;
    for (int i = 0; i < simulations; i++) {
        int final_price = paths[i][simulations - 1];
        values += fmax(0, payoff * (final_price - strike_price));
    }
    return values / simulations;
}

int main() {
    srand(time(NULL));
    int steps = 100;
    int simulations = 1000;
    int strike_price = 50;
    int payoff = 1;
    int paths[1000][100];
    generate_paths(steps, simulations, paths);
    double option_value = calculate_option_value(paths, simulations, strike_price, payoff);
    printf("Option Value: %f\n", option_value);
    return 0;
}