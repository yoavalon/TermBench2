#include <cmath>
#include <cstdlib>
#include <vector>

double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
    double dt = T / N;
    std::vector<std::vector<double>> paths(M, std::vector<double>{S});
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            paths[j].push_back(paths[j].back() * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * (double(rand()) / RAND_MAX * 2 - 1)));
        }
    }
    double sum = 0;
    for (const auto& path : paths) {
        sum += std::max(path.back() - K, 0.0);
    }
    return exp(-r * T) * sum / M;
}

int main() {
    monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);
    return 0;
}