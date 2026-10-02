#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<std::vector<double>> initialize_particles(int dim, int num_particles) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);
    std::vector<std::vector<double>> particles(num_particles, std::vector<double>(dim));
    std::vector<std::vector<double>> velocities(num_particles, std::vector<double>(dim));
    std::vector<std::vector<double>> pbest_positions(num_particles, std::vector<double>(dim));
    std::vector<double> pbest_values(num_particles, std::numeric_limits<double>::infinity());
    std::vector<double> gbest_position(dim);
    double gbest_value = std::numeric_limits<double>::infinity();

    for (int i = 0; i < num_particles; ++i) {
        for (int j = 0; j < dim; ++j) {
            particles[i][j] = dis(gen);
            velocities[i][j] = dis(gen) / 10.0;
            pbest_positions[i][j] = particles[i][j];
        }
    }

    return {particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value};
}

std::tuple<double, std::vector<double>, std::vector<double>, std::vector<std::vector<double>>>
update_pbest(double gbest_value, const std::vector<double>& gbest_position,
             const std::vector<double>& pbest_values, const std::vector<std::vector<double>>& pbest_positions,
             const std::vector<std::vector<double>>& particles, double (*fitness_func)(const std::vector<double>&)) {
    for (int i = 0; i < particles.size(); ++i) {
        double current_value = fitness_func(particles[i]);
        if (current_value < pbest_values[i]) {
            pbest_values[i] = current_value;
            pbest_positions[i] = particles[i];
        }
        if (current_value < gbest_value) {
            gbest_value = current_value;
            gbest_position = particles[i];
        }
    }
    return {gbest_value, gbest_position, pbest_values, pbest_positions};
}

void update_particles(std::vector<std::vector<double>>& particles, std::vector<std::vector<double>>& velocities,
                      const std::vector<std::vector<double>>& pbest_positions, const std::vector<double>& gbest_position,
                      double w, double c1, double c2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < particles.size(); ++i) {
        for (int j = 0; j < particles[i].size(); ++j) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
        }
    }
}

double fitness_func(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    int dim = 2;
    int num_particles = 10;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;

    auto [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value] = initialize_particles(dim, num_particles);

    while (true) {
        std::tie(gbest_value, gbest_position, pbest_values, pbest_positions) = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func);
        update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2);
    }

    return 0;
}