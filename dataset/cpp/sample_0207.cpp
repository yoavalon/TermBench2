#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Particle {
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
};

std::vector<Particle> initialize_particles(int num_particles, int num_dimensions) {
    std::vector<Particle> particles;
    for (int _ = 0; _ < num_particles; ++_) {
        Particle particle;
        particle.position.resize(num_dimensions);
        particle.velocity.resize(num_dimensions);
        particle.best_position.resize(num_dimensions);
        for (int i = 0; i < num_dimensions; ++i) {
            particle.position[i] = static_cast<double>(rand()) / RAND_MAX * 20 - 10;
            particle.velocity[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
            particle.best_position[i] = particle.position[i];
        }
        particles.push_back(particle);
    }
    return particles;
}

void update_velocity(std::vector<Particle>& particles, const Particle& global_best, double w, double c1, double c2) {
    for (auto& particle : particles) {
        double r1 = static_cast<double>(rand()) / RAND_MAX;
        double r2 = static_cast<double>(rand()) / RAND_MAX;
        for (int i = 0; i < particle.position.size(); ++i) {
            double cognitive_velocity = c1 * r1 * (particle.best_position[i] - particle.position[i]);
            double social_velocity = c2 * r2 * (global_best.position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive_velocity + social_velocity;
        }
    }
}

void update_position(std::vector<Particle>& particles) {
    for (auto& particle : particles) {
        for (int i = 0; i < particle.position.size(); ++i) {
            particle.position[i] += particle.velocity[i];
        }
    }
}

Particle evaluate_fitness(std::vector<Particle>& particles, double (*fitness_function)(const std::vector<double>&)) {
    Particle global_best = particles[0];
    for (auto& particle : particles) {
        double fitness = fitness_function(particle.position);
        if (fitness < fitness_function(particle.best_position)) {
            particle.best_position = particle.position;
        }
        if (fitness < fitness_function(global_best.best_position)) {
            global_best = particle;
        }
    }
    return global_best;
}

double fitness_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int num_particles = 20;
    int num_dimensions = 2;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int max_iterations = 100;

    std::vector<Particle> particles = initialize_particles(num_particles, num_dimensions);
    Particle global_best = evaluate_fitness(particles, fitness_function);
    for (int _ = 0; _ < max_iterations; ++_) {
        update_velocity(particles, global_best, w, c1, c2);
        update_position(particles);
        global_best = evaluate_fitness(particles, fitness_function);
    }
    std::cout << "Best position found: ";
    for (double x : global_best.best_position) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Fitness value: " << fitness_function(global_best.best_position) << std::endl;
    return 0;
}