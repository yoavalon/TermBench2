#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Swarm {
public:
    Swarm(int size, int dimensions, std::pair<double, double> search_space)
        : size(size), dimensions(dimensions), search_space(search_space) {
        particles.resize(size);
        for (int i = 0; i < size; ++i) {
            particles[i] = Particle(dimensions, search_space);
        }
    }

    void update() {
        for (int i = 0; i < size; ++i) {
            particles[i].update_velocity();
            particles[i].update_position();
        }
    }

private:
    int size;
    int dimensions;
    std::pair<double, double> search_space;
    std::vector<Particle> particles;
};

class Particle {
public:
    Particle(int dimensions, std::pair<double, double> search_space)
        : dimensions(dimensions), search_space(search_space) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = static_cast<double>(rand()) / RAND_MAX * (search_space.second - search_space.first) + search_space.first;
            velocity[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
            best_position[i] = position[i];
        }
        best_fitness = std::numeric_limits<double>::infinity();
    }

    void update_velocity() {
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        for (int i = 0; i < dimensions; ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < dimensions; ++i) {
            position[i] += velocity[i];
            position[i] = std::max(search_space.first, std::min(search_space.second, position[i]));
        }
    }

private:
    int dimensions;
    std::pair<double, double> search_space;
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness;
};

double fitness_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void optimize(Swarm& swarm, int max_iterations) {
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        for (Particle& particle : swarm.particles) {
            double current_fitness = fitness_function(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position;
            }
        }
        swarm.update();
    }
}

int main() {
    int size = 30;
    int dimensions = 2;
    std::pair<double, double> search_space = {-10, 10};
    int max_iterations = 100;
    Swarm swarm(size, dimensions, search_space);
    optimize(swarm, max_iterations);
    return 0;
}