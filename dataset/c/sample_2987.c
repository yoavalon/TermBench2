#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double random_walk(int steps) {
    double position = 0;
    double walk[steps + 1];
    walk[0] = position;
    for (int i = 0; i < steps; i++) {
        int step = rand() % 2 ? 1 : -1;
        position += step;
        walk[i + 1] = position;
    }
    return walk[steps];
}

double brownian_motion(int steps, double dt, double initial) {
    double motion[steps + 1];
    double current = initial;
    motion[0] = initial;
    for (int i = 0; i < steps; i++) {
        double drift = 0;
        double diffusion = sqrt(dt) * (rand() / (double)RAND_MAX * 2 - 1);
        current += drift + diffusion;
        motion[i + 1] = current;
    }
    return motion[steps];
}

typedef struct {
    double strike;
    double expiry;
} OptionPricer;

double OptionPricer_price(OptionPricer *self, double path) {
    double value_at_expiry = path;
    return fmax(0, value_at_expiry - self->strike);
}

double simulate_option_price(double strike, double expiry, int steps, double dt) {
    OptionPricer pricer = {strike, expiry};
    double paths[1000];
    double prices[1000];
    for (int i = 0; i < 1000; i++) {
        paths[i] = brownian_motion(steps, dt, 0);
        prices[i] = OptionPricer_price(&pricer, paths[i]);
    }
    double sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += prices[i];
    }
    return sum / 1000;
}

int main() {
    double strike_price = 100;
    double expiry_time = 1;
    int time_steps = 100;
    double delta_t = expiry_time / time_steps;
    srand(time(NULL));
    while (1) {
        double price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t);
        printf("Simulated Option Price: %f\n", price);
    }
    return 0;
}