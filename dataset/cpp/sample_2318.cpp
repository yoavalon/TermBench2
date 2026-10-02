#include <iostream>
#include <vector>
#include <random>
#include <cmath>

struct Particle {
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double fitness;
};

std::vector<Particle> initialize_particles(int dimensions, int count) {
    std::vector<Particle> particles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-10.0, 10.0);
    std::uniform_real_distribution<> dis_v(-1.0, 1.0);

    for (int i = 0; i < count; ++i) {
        Particle particle;
        for (int j = 0; j < dimensions; ++j) {
            particle.position.push_back(dis(gen));
            particle.velocity.push_back(dis_v(gen));
            particle.best_position.push_back(particle.position[j]);
        }
        particles.push_back(particle);
    }
    return particles;
}

void evaluate_fitness(std::vector<Particle>& particles, double (*objective_function)(const std::vector<double>&)) {
    for (auto& particle : particles) {
        particle.fitness = objective_function(particle.position);
    }
}

void update_particles(std::vector<Particle>& particles, const Particle& global_best, double inertia_weight, double cognitive_weight, double social_weight) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto& particle : particles) {
        for (int i = 0; i < particle.position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive_velocity = cognitive_weight * r1 * (particle.best_position[i] - particle.position[i]);
            double social_velocity = social_weight * r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = inertia_weight * particle.velocity[i] + cognitive_velocity + social_velocity;
            particle.position[i] += particle.velocity[i];
        }
        if (particle.fitness < particle.best_position.size() ? particle.fitness : std::numeric_limits<double>::max()) {
            particle.best_position = particle.position;
        }
    }
}

Particle find_global_best(const std::vector<Particle>& particles) {
    Particle global_best = particles[0];
    for (const auto& particle : particles) {
        if (particle.fitness < global_best.fitness) {
            global_best = particle;
        }
    }
    return global_best;
}

double objective_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    int dimensions = 2;
    int particle_count = 30;
    double inertia_weight = 0.7;
    double cognitive_weight = 1.5;
    double social_weight = 1.5;

    std::vector<Particle> particles = initialize_particles(dimensions, particle_count);
    while (true) {
        evaluate_fitness(particles, objective_function);
        Particle global_best = find_global_best(particles);
        update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight);
    }

    return 0;
}