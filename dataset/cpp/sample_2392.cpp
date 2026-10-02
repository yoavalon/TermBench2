#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

struct Particle {
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double fitness;
};

std::vector<Particle> initialize_particles(int num_particles, int dimensions) {
    std::vector<Particle> particles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_pos(-10.0, 10.0);
    std::uniform_real_distribution<> dis_vel(-1.0, 1.0);

    for (int i = 0; i < num_particles; ++i) {
        Particle particle;
        for (int j = 0; j < dimensions; ++j) {
            particle.position.push_back(dis_pos(gen));
            particle.velocity.push_back(dis_vel(gen));
            particle.best_position.push_back(particle.position[j]);
        }
        particles.push_back(particle);
    }
    return particles;
}

void evaluate_fitness(std::vector<Particle>& particles, double (*fitness_function)(const std::vector<double>&)) {
    for (auto& particle : particles) {
        particle.fitness = fitness_function(particle.position);
    }
}

void update_particles(std::vector<Particle>& particles, const std::vector<double>& global_best_position, double inertia_weight, double cognitive_weight, double social_weight) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto& particle : particles) {
        for (int i = 0; i < particle.position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive_velocity = cognitive_weight * r1 * (particle.best_position[i] - particle.position[i]);
            double social_velocity = social_weight * r2 * (global_best_position[i] - particle.position[i]);
            particle.velocity[i] = inertia_weight * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        if (fitness_function(particle.position) < fitness_function(particle.best_position)) {
            particle.best_position = particle.position;
        }
    }
}

std::vector<double> find_global_best(const std::vector<Particle>& particles) {
    auto best_particle = *std::min_element(particles.begin(), particles.end(), [](const Particle& a, const Particle& b) {
        return a.fitness < b.fitness;
    });
    return best_particle.best_position;
}

double fitness_function(const std::vector<double>& position) {
    double fitness = 0.0;
    for (double x : position) {
        fitness += x * x;
    }
    return fitness;
}

int main() {
    int num_particles = 30;
    int dimensions = 2;
    double inertia_weight = 0.7;
    double cognitive_weight = 1.5;
    double social_weight = 1.5;
    std::vector<Particle> particles = initialize_particles(num_particles, dimensions);

    while (true) {
        evaluate_fitness(particles, fitness_function);
        std::vector<double> global_best_position = find_global_best(particles);
        update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight);
    }

    return 0;
}