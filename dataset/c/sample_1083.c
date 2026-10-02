c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simulate_price(double *path, double strike, double rate, double vol, double time, int steps) {
    double dt = time / steps;
    for (int i = 0; i < steps; i++) {
        double rand = ((double)rand() / RAND_MAX) * 2 - 1;
        double drift = (rate - 0.5 * vol * vol) * dt;
        double diffusion = vol * rand * sqrt(dt);
        path[i + 1] = path[i] * (1 + drift + diffusion);
    }
}

double option_price(double **paths, double strike, double r, double t, int num_paths) {
    double payoff = 0;
    for (int i = 0; i < num_paths; i++) {
        payoff += fmax(paths[i][num_paths - 1] - strike, 0);
    }
    return payoff * pow(1 / r, t);
}

int main() {
    double strike = 100, rate = 0.05, vol = 0.2, time = 1, dt = time / 252;
    double paths[10000][253];
    paths[0][0] = 100;
    simulate_price(paths[0], strike, rate, vol, time, 252);
    int num_paths = 1;
    while (1) {
        paths[num_paths][0] = 100;
        simulate_price(paths[num_paths], strike, rate, vol, time, 252);
        printf("%f\n", option_price(paths, strike, rate, time, num_paths + 1));
        num_paths++;
    }
    return 0;
}