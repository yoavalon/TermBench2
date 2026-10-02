#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
    double d;
    double e;
} FinancialModel;

typedef struct {
    FinancialModel *f;
} PricingEngine;

double gauss() {
    double x1, x2, w;
    do {
        x1 = 2.0 * ((double)rand() / RAND_MAX) - 1.0;
        x2 = 2.0 * ((double)rand() / RAND_MAX) - 1.0;
        w = x1 * x1 + x2 * x2;
    } while (w >= 1.0);
    return x1 * sqrt(-2.0 * log(w) / w);
}

void simulate_paths(FinancialModel *model, double paths[100][252], int n) {
    for (int i = 0; i < n; i++) {
        paths[i][0] = model->a;
        for (int j = 1; j < 252; j++) {
            double z = gauss();
            paths[i][j] = paths[i][j - 1] * (1 + model->c / 252 + model->b * z / 100);
        }
    }
}

double payoff(FinancialModel *model, double path[252]) {
    return fmax(path[251] - model->d, 0);
}

double price_option(PricingEngine *engine, int simulations) {
    double total = 0;
    for (int i = 0; i < simulations; i++) {
        double paths[100][252];
        simulate_paths(engine->f, paths, 100);
        double payoff_sum = 0;
        for (int j = 0; j < 100; j++) {
            payoff_sum += payoff(engine->f, paths[j]);
        }
        total += payoff_sum / 100;
    }
    return total / simulations * exp(-engine->f->c * engine->f->e);
}

void main() {
    FinancialModel model = {100, 20, 0.05, 100, 1};
    PricingEngine engine = {&model};
    double price = price_option(&engine, 1000);
    printf("%f\n", price);
}