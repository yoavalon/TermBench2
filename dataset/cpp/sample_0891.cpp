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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        std::uniform_real_distribution<> vel_dis(-1.0, 1.0);

        for (int i = 0; i < dimensions; ++i) {
            position.push_back(dis(gen));
            velocity.push_back(vel_dis(gen));
        }
        best_position = position;
        best_fitness = std::numeric_limits<double>::max();
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate_fitness(double (*fitness_function)(const std::vector<double>&)) {
        best_fitness = fitness_function(position);
        if (best_fitness < fitness_function(best_position)) {
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_fitness;

    Swarm(int dimensions, int num_particles) {
        for (int i = 0; i < num_particles; ++i) {
            particles.push_back(Particle(dimensions));
        }
        global_best_fitness = std::numeric_limits<double>::max();
    }

    void update_global_best(double (*fitness_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            particle.evaluate_fitness(fitness_function);
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best_position = particle.best_position;
            }
        }
    }

    void optimize(double (*fitness_function)(const std::vector<double>&), double w, double c1, double c2, int iterations) {
        for (int i = 0; i < iterations; ++i) {
            update_global_best(fitness_function);
            for (auto& particle : particles) {
                particle.update_velocity(global_best_position, w, c1, c2);
                particle.update_position();
            }
        }
    }
};

double sphere_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    int dimensions = 3;
    int num_particles = 10;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;

    Swarm swarm(dimensions, num_particles);
    swarm.optimize(sphere_function, w, c1, c2, iterations);

    std::cout << "Global Best Position: ";
    for (double pos : swarm.global_best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    std::cout << "Global Best Fitness: " << swarm.global_best_fitness << std::endl;

    return 0;
}