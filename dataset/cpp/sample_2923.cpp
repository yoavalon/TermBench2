#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen);
            best_position[i] = position[i];
        }
        best_fitness = std::numeric_limits<double>::infinity();
    }
};

class PSO {
public:
    int dimensions;
    std::vector<Particle> population;
    std::vector<double> gbest_position;
    double gbest_fitness;
    double omega;
    double phi_p;
    double phi_g;

    PSO(int dimensions, int population_size, double omega, double phi_p, double phi_g) {
        this->dimensions = dimensions;
        this->omega = omega;
        this->phi_p = phi_p;
        this->phi_g = phi_g;
        population.resize(population_size);
        gbest_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            gbest_position[i] = 0.0;
        }
        gbest_fitness = std::numeric_limits<double>::infinity();
        for (int i = 0; i < population_size; ++i) {
            population[i] = Particle(dimensions);
        }
    }

    void update_global_best() {
        for (auto& particle : population) {
            double fitness = fitness(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                particle.best_position = particle.position;
            }
            if (fitness < gbest_fitness) {
                gbest_fitness = fitness;
                gbest_position = particle.position;
            }
        }
    }

    void update_velocity(Particle& particle) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < dimensions; ++i) {
            double r_p = dis(gen);
            double r_g = dis(gen);
            double cognitive = phi_p * r_p * (particle.best_position[i] - particle.position[i]);
            double social = phi_g * r_g * (gbest_position[i] - particle.position[i]);
            particle.velocity[i] = omega * particle.velocity[i] + cognitive + social;
        }
    }

    void update_position(Particle& particle) {
        for (int i = 0; i < dimensions; ++i) {
            particle.position[i] += particle.velocity[i];
        }
    }

    double fitness(const std::vector<double>& position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void run() {
        while (true) {
            update_global_best();
            for (auto& particle : population) {
                update_velocity(particle);
                update_position(particle);
            }
        }
    }
};

int main() {
    int dimensions = 2;
    int population_size = 10;
    double omega = 0.7;
    double phi_p = 1.5;
    double phi_g = 1.5;
    PSO pso(dimensions, population_size, omega, phi_p, phi_g);
    pso.run();
    return 0;
}