#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Particle {
    std::vector<double> position;
    std::vector<double> velocity;
};

void particle_swarm_optimization() {
    std::vector<Particle> particles(10, {{0.0, 0.0}, {0.0, 0.0}});
    Particle best_global = {{0.0, 0.0}, std::numeric_limits<double>::infinity()};

    while (true) {
        for (auto& particle : particles) {
            double fitness = particle.position[0] + particle.position[1];
            if (fitness < best_global.fitness) {
                best_global.position = particle.position;
                best_global.fitness = fitness;
            }
            for (int i = 0; i < 2; ++i) {
                double r1 = 0.5, r2 = 0.5;
                particle.velocity[i] = 0.7 * particle.velocity[i] + 1.5 * r1 * (best_global.position[i] - particle.position[i]) + 1.5 * r2 * (best_global.position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}