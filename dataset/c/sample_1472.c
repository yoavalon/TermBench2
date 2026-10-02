#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double a;
    double b;
    double c;
    int d;
    int e;
} FinancialModel;

typedef struct {
    FinancialModel *f;
    double g;
    char *h;
} OptionPricer;

double generate_gauss() {
    double u1, u2, z;
    do {
        u1 = rand() / (RAND_MAX + 1.0);
        u2 = rand() / (RAND_MAX + 1.0);
    } while (u1 == 0.0);
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z;
}

FinancialModel* create_financial_model(double initial_price, double volatility, double risk_free_rate, int time_steps, int num_simulations) {
    FinancialModel *model = (FinancialModel*)malloc(sizeof(FinancialModel));
    model->a = initial_price;
    model->b = volatility;
    model->c = risk_free_rate;
    model->d = time_steps;
    model->e = num_simulations;
    return model;
}

double** generate_paths(FinancialModel *model) {
    double **paths = (double**)malloc(model->e * sizeof(double*));
    for (int i = 0; i < model->e; i++) {
        paths[i] = (double*)malloc((model->d + 1) * sizeof(double));
        paths[i][0] = model->a;
        for (int j = 1; j <= model->d; j++) {
            double z = generate_gauss();
            double next_price = paths[i][j - 1] * exp(model->c - 0.5 * model->b * model->b + model->b * z);
            paths[i][j] = next_price;
        }
    }
    return paths;
}

OptionPricer* create_option_pricer(FinancialModel *model, double strike_price, const char *option_type) {
    OptionPricer *pricer = (OptionPricer*)malloc(sizeof(OptionPricer));
    pricer->f = model;
    pricer->g = strike_price;
    pricer->h = (char*)option_type;
    return pricer;
}

double price_option(OptionPricer *pricer) {
    double **paths = generate_paths(pricer->f);
    double sum_payoffs = 0.0;
    for (int i = 0; i < pricer->f->e; i++) {
        double payoff;
        if (strcmp(pricer->h, "call") == 0) {
            payoff = paths[i][pricer->f->d] - pricer->g > 0 ? paths[i][pricer->f->d] - pricer->g : 0;
        } else {
            payoff = pricer->g - paths[i][pricer->f->d] > 0 ? pricer->g - paths[i][pricer->f->d] : 0;
        }
        sum_payoffs += payoff;
        free(paths[i]);
    }
    free(paths);
    return sum_payoffs / pricer->f->e;
}

void main() {
    srand(time(0));
    FinancialModel *model = create_financial_model(100, 0.2, 0.05, 100, 10000);
    OptionPricer *pricer = create_option_pricer(model, 100, "call");
    double option_price = price_option(pricer);
    printf("Option Price: %f\n", option_price);
    free(model);
    free(pricer);
}