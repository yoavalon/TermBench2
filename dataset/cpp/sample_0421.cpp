#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> initialize_particles(int dim, int num_particles) {
    std::vector<std::vector<double>> particles(num_particles, std::vector<double>(dim));
    std::vector<std::vector<double>> velocities(num_particles, std::vector<double>(dim));
    std::vector<std::vector<double>> best_positions(num_particles, std::vector<double>(dim));
    std::vector<double> best_scores(num_particles, std::numeric_limits<double>::infinity());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < num_particles; ++i) {
        for (int j = 0; j < dim; ++j) {
            particles[i][j] = dis(gen);
            velocities[i][j] = dis(gen);
            best_positions[i][j] = particles[i][j];
        }
    }

    return {particles, velocities, best_positions, best_scores};
}

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> update_particles(
    std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities,
    const std::vector<std::vector<double>>& best_positions, const std::vector<double>& best_scores,
    const std::vector<double>& global_best, double omega, double phi_p, double phi_g, const std::pair<double, double>& bounds) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < particles.size(); ++i) {
        for (int j = 0; j < particles[i].size(); ++j) {
            double r_p = dis(gen);
            double r_g = dis(gen);
            velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
            particles[i][j] = std::max(bounds.first, std::min(bounds.second, particles[i][j]));
        }
    }

    return {particles, velocities};
}

int main() {
    int dim = 2;
    int num_particles = 10;
    auto [particles, velocities, best_positions, best_scores] = initialize_particles(dim, num_particles);
    std::vector<double> global_best(dim, std::numeric_limits<double>::infinity());
    double omega = 0.7;
    double phi_p = 0.2;
    double phi_g = 0.3;
    std::pair<double, double> bounds = {0, 1};

    while (true) {
        std::tie(particles, velocities) = update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds);
    }

    return 0;
}