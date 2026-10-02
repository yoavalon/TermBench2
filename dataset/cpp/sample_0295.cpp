#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double* S0, double K, double T, double r, double sigma, int N) {
        this->S0 = new double[N];
        std::copy(S0, S0 + N, this->S0);
        this->K = K;
        this->T = T;
        this->r = r;
        this->sigma = sigma;
        this->N = N;
        this->dt = T / N;
    }

    ~FinancialModel() {
        delete[] S0;
    }

    std::vector<std::vector<double>> simulate_paths() {
        std::vector<std::vector<double>> paths(N + 1, std::vector<double>(N));
        std::copy(S0, S0 + N, paths[0].begin());
        for (int t = 1; t <= N; ++t) {
            std::vector<double> z(N);
            for (double& zi : z) {
                zi = generate_standard_normal();
            }
            for (int i = 0; i < N; ++i) {
                paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    std::vector<double> payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoff(N);
        for (int i = 0; i < N; ++i) {
            payoff[i] = std::max(paths[N][i] - K, 0.0);
        }
        return payoff;
    }

private:
    double* S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;
    double dt;

    double generate_standard_normal() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::normal_distribution<> d(0, 1);
        return d(gen);
    }
};

class OptionPricer {
public:
    OptionPricer(FinancialModel* financial_model, int M) {
        this->financial_model = financial_model;
        this->M = M;
    }

    double price_option() {
        std::vector<double> payoffs(M);
        for (int i = 0; i < M; ++i) {
            auto paths = financial_model->simulate_paths();
            auto payoff = financial_model->payoff(paths);
            payoffs[i] = payoff[0]; // Assuming single asset for simplicity
        }
        double option_price = exp(-financial_model->r * financial_model->T) * mean(payoffs);
        return option_price;
    }

private:
    FinancialModel* financial_model;
    int M;

    double mean(const std::vector<double>& data) {
        double sum = 0.0;
        for (double x : data) {
            sum += x;
        }
        return sum / data.size();
    }
};

int main() {
    double S0[] = {100, 100, 100};
    double K = 100;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    int M = 10000;
    FinancialModel financial_model(S0, K, T, r, sigma, N);
    OptionPricer option_pricer(&financial_model, M);
    std::cout << option_pricer.price_option() << std::endl;
    return 0;
}