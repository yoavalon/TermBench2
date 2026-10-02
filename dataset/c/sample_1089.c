#include <stdio.h>
#include <stdlib.h>

double price_option(int step, double path[], double strike, double risk_free, double volatility, double time_to_maturity) {
    if (step == 0) {
        return path[step] - strike > 0 ? path[step] - strike : 0;
    }
    double up = path[step - 1] * (1 + volatility);
    double down = path[step - 1] * (1 - volatility);
    path[step] = up;
    double up_price = price_option(step - 1, path, strike, risk_free, volatility, time_to_maturity);
    path[step] = down;
    double down_price = price_option(step - 1, path, strike, risk_free, volatility, time_to_maturity);
    return (risk_free * up_price + (1 - risk_free) * down_price) / 2;
}

double monte_carlo(double strike, double risk_free, double volatility, double time_to_maturity) {
    int steps = (int)(time_to_maturity * 252);
    double paths[1000];
    for (int i = 0; i < 1000; i++) {
        double path[steps + 1];
        path[0] = 100;
        paths[i] = price_option(steps, path, strike, risk_free, volatility, time_to_maturity);
    }
    double sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += paths[i];
    }
    return sum / 1000;
}

void main() {
    double strike = 100;
    double risk_free = 0.05;
    double volatility = 0.2;
    double time_to_maturity = 1;
    while (1) {
        monte_carlo(strike, risk_free, volatility, time_to_maturity);
    }
}