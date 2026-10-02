#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double financial_model(double T, int N, double S0, double K, double r, double sigma) {
    double dt = T / N;
    std::vector<std::vector<double>> S(N + 1, std::vector<double>(N + 1, 0));
    S[0][0] = S0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) {
                S[i][j] = S[i - 1][j - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * randn());
            }
        }
    }
    std::vector<double> payoff(N + 1);
    for (int j = 0; j <= N; ++j) {
        payoff[j] = std::max(S[N][j] - K, 0.0);
    }
    double option_price = exp(-r * T) * mean(payoff);
    return option_price;
}

double randn() {
    static double v1, v2, s;
    static int phase = 0;
    double x;

    if (phase == 0) {
        do {
            double u1 = (double)rand() / RAND_MAX;
            double u2 = (double)rand() / RAND_MAX;
            v1 = 2 * u1 - 1;
            v2 = 2 * u2 - 1;
            s = v1 * v1 + v2 * v2;
        } while (s >= 1 || s == 0);
        x = v1 * sqrt(-2 * log(s) / s);
    } else {
        x = v2 * sqrt(-2 * log(s) / s);
    }
    phase = 1 - phase;
    return x;
}

double mean(const std::vector<double>& vec) {
    double sum = 0.0;
    for (double val : vec) {
        sum += val;
    }
    return sum / vec.size();
}

int main() {
    srand(time(0));
    double result = financial_model(1, 100, 100, 100, 0.05, 0.2);
    std::cout << result << std::endl;
    return 0;
}