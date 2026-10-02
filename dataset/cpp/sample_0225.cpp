#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class PSOSettings {
public:
    int dimensions;
    int population_size;
    int max_iterations;
    double c1;
    double c2;
    double w;

    PSOSettings(int dimensions, int population_size, int max_iterations) {
        this->dimensions = dimensions;
        this->population_size = population_size;
        this->max_iterations = max_iterations;
        c1 = 2.0;
        c2 = 2.0;
        w = 0.7;
    }
};

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness;

    Particle(int dimensions, double lower_bound, double upper_bound) {
        position = std::vector<double>(dimensions);
        velocity = std::vector<double>(dimensions);
        best_position = std::vector<double>(dimensions);
        best_fitness = std::numeric_limits<double>::infinity();
        for (int i = 0; i < dimensions; ++i) {
            position[i] = lower_bound + (upper_bound - lower_bound) * ((double)rand() / RAND_MAX);
            velocity[i] = -1 + 2 * ((double)rand() / RAND_MAX);
            best_position[i] = position[i];
        }
    }
};

double fitness(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void update_velocity(Particle& particle, const std::vector<double>& global_best, const PSOSettings& settings) {
    for (int i = 0; i < settings.dimensions; ++i) {
        double r1 = ((double)rand() / RAND_MAX);
        double r2 = ((double)rand() / RAND_MAX);
        double cognitive = settings.c1 * r1 * (particle.best_position[i] - particle.position[i]);
        double social = settings.c2 * r2 * (global_best[i] - particle.position[i]);
        particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social;
    }
}

void update_position(Particle& particle, const PSOSettings& settings) {
    for (int i = 0; i < settings.dimensions; ++i) {
        particle.position[i] += particle.velocity[i];
        if (particle.position[i] < -10) {
            particle.position[i] = -10;
        } else if (particle.position[i] > 10) {
            particle.position[i] = 10;
        }
    }
}

std::pair<std::vector<double>, double> optimize(const PSOSettings& settings) {
    std::vector<Particle> population;
    for (int i = 0; i < settings.population_size; ++i) {
        population.push_back(Particle(settings.dimensions, -10, 10));
    }
    std::vector<double> global_best(settings.dimensions);
    double global_best_fitness = std::numeric_limits<double>::infinity();
    for (int iteration = 0; iteration < settings.max_iterations; ++iteration) {
        for (Particle& particle : population) {
            double current_fitness = fitness(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position;
            }
            if (current_fitness < global_best_fitness) {
                global_best_fitness = current_fitness;
                global_best = particle.position;
            }
        }
        for (Particle& particle : population) {
            update_velocity(particle, global_best, settings);
            update_position(particle, settings);
        }
    }
    return {global_best, global_best_fitness};
}

int main() {
    srand(time(0));
    PSOSettings settings(2, 30, 100);
    auto [best_position, best_fitness] = optimize(settings);
    std::cout << "Best position: ";
    for (double x : best_position) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Best fitness: " << best_fitness << std::endl;
    return 0;
}