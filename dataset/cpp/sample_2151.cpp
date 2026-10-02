#include <iostream>
#include <Eigen/Dense>
#include <random>

Eigen::Vector3d simulate_thermodynamic_state() {
    Eigen::Vector3d state = Eigen::Vector3d::Random();
    double precision = 1e-10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, precision);

    while (true) {
        state += Eigen::Vector3d(d(gen), d(gen), d(gen));
        std::cout << state.mean() << std::endl;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}