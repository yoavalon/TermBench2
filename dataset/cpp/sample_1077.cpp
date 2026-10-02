#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

double update_velocity(double p, double g, double v, double w, double c1, double c2) {
    double r1 = static_cast<double>(rand()) / RAND_MAX;
    double r2 = static_cast<double>(rand()) / RAND_MAX;
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p);
}

double update_position(double p, double v) {
    return p + v;
}

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>> optimize(
    const std::vector<double>& particles, 
    const std::vector<double>& velocities, 
    const std::vector<double>& best_positions, 
    double global_best, 
    double w, 
    double c1, 
    double c2) {
    
    std::vector<double> new_particles;
    std::vector<double> new_velocities;
    std::vector<double> new_best_positions;
    
    for (size_t i = 0; i < particles.size(); ++i) {
        double v = update_velocity(particles[i], global_best, velocities[i], w, c1, c2);
        double p = update_position(particles[i], v);
        new_particles.push_back(p);
        new_velocities.push_back(v);
        if (p < best_positions[i]) {
            new_best_positions.push_back(p);
        } else {
            new_best_positions.push_back(best_positions[i]);
        }
    }
    
    return {new_particles, new_velocities, new_best_positions};
}

void swarm() {
    std::vector<double> particles(10);
    std::vector<double> velocities(10);
    std::vector<double> best_positions(10);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (size_t i = 0; i < 10; ++i) {
        particles[i] = static_cast<double>(rand()) / RAND_MAX;
        velocities[i] = static_cast<double>(rand()) / RAND_MAX;
        best_positions[i] = particles[i];
    }
    
    double global_best = *std::min_element(particles.begin(), particles.end());
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    
    while (true) {
        auto [new_particles, new_velocities, new_best_positions] = optimize(particles, velocities, best_positions, global_best, w, c1, c2);
        particles = new_particles;
        velocities = new_velocities;
        best_positions = new_best_positions;
        global_best = *std::min_element(best_positions.begin(), best_positions.end());
    }
}

int main() {
    swarm();
    return 0;
}