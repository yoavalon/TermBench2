#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void optimize() {
    int n = 10, d = 3;
    double p = 0.1;
    std::vector<std::vector<double>> particles(n, std::vector<double>(d));
    std::srand(std::time(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            particles[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }

    for (int _ = 0; _ < 100; ++_) {
        std::vector<std::vector<double>> velocities(n, std::vector<double>(d));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < d; ++j) {
                velocities[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
                particles[i][j] += velocities[i][j] * p;
            }
        }
    }
}

int main() {
    optimize();
    return 0;
}