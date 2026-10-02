#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> initialize_particles(int num_particles, int dimensions, std::vector<double> bounds) {
    std::vector<std::vector<double>> particles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(bounds[0], bounds[1]);
    for (int _ = 0; _ < num_particles; ++_) {
        std::vector<double> particle;
        for (int _ = 0; _ < dimensions; ++_) {
            particle.push_back(dis(gen));
        }
        particles.push_back(particle);
    }
    return particles;
}

std::vector<std::vector<double>> update_positions(std::vector<std::vector<double>> particles, std::vector<std::vector<double>> velocities, std::vector<double> bounds) {
    std::vector<std::vector<double>> new_positions;
    for (int i = 0; i < particles.size(); ++i) {
        std::vector<double> new_position;
        for (int j = 0; j < particles[i].size(); ++j) {
            new_position.push_back(std::max(bounds[0], std::min(bounds[1], particles[i][j] + velocities[i][j])));
        }
        new_positions.push_back(new_position);
    }
    return new_positions;
}

int main() {
    int num_particles = 30;
    int dimensions = 2;
    std::vector<double> bounds = {0, 10};
    std::vector<std::vector<double>> particles = initialize_particles(num_particles, dimensions, bounds);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    std::vector<std::vector<double>> velocities;
    for (int _ = 0; _ < num_particles; ++_) {
        std::vector<double> velocity;
        for (int _ = 0; _ < dimensions; ++_) {
            velocity.push_back(dis(gen));
        }
        velocities.push_back(velocity);
    }
    for (int _ = 0; _ < 100; ++_) {
        particles = update_positions(particles, velocities, bounds);
    }
    for (const auto& particle : particles) {
        for (double val : particle) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}