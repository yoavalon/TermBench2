#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>

class Swarm {
public:
    Swarm(int size, int dimensions, std::vector<double> bounds) 
        : size(size), dimensions(dimensions), bounds(bounds) {
        for (int i = 0; i < size; ++i) {
            particles.push_back(Particle(dimensions, bounds));
        }
        gbest = nullptr;
    }

    void update_gbest() {
        for (auto& particle : particles) {
            if (gbest == nullptr || particle.fitness < gbest->fitness) {
                gbest = &particle;
            }
        }
    }

    void update_particles() {
        for (auto& particle : particles) {
            particle.update_velocity(gbest);
            particle.update_position();
        }
    }

private:
    int size;
    int dimensions;
    std::vector<double> bounds;
    std::vector<Particle> particles;
    Particle* gbest;
};

class Particle {
public:
    Particle(int dimensions, std::vector<double> bounds) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = random_double(bounds[0], bounds[1]);
            velocity[i] = random_double(-1, 1);
            best_position[i] = position[i];
        }
        fitness = std::numeric_limits<double>::infinity();
    }

    void update_velocity(Particle* gbest) {
        double w = 0.5, c1 = 1.5, c2 = 1.5;
        for (int i = 0; i < dimensions; ++i) {
            double r1 = random_double(), r2 = random_double();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (gbest->position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < dimensions; ++i) {
            position[i] += velocity[i];
            if (position[i] < bounds[0]) {
                position[i] = bounds[0];
            }
            if (position[i] > bounds[1]) {
                position[i] = bounds[1];
            }
        }
    }

private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double fitness;
};

double objective_function(const std::vector<double>& x) {
    double sum = 0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

void optimize(Swarm& swarm, int max_iterations) {
    for (int i = 0; i < max_iterations; ++i) {
        swarm.update_gbest();
        for (auto& particle : swarm.particles) {
            particle.fitness = objective_function(particle.position);
        }
        swarm.update_particles();
    }
}

double random_double(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    int size = 30;
    int dimensions = 2;
    std::vector<double> bounds = {-10, 10};
    int max_iterations = 100;
    Swarm swarm(size, dimensions, bounds);
    optimize(swarm, max_iterations);
    for (double pos : swarm.gbest->position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    return 0;
}