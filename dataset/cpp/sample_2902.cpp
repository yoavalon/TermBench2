#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_fitness;

    Particle(int dimensions) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1, 1);
        for (int i = 0; i < dimensions; ++i) {
            position.push_back(dis(gen));
            velocity.push_back(dis(gen));
        }
        best_position = position;
        best_fitness = INFINITY;
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[i].first, std::min(bounds[i].second, position[i]));
        }
    }

    void evaluate_fitness(double (*fitness_function)(const std::vector<double>&)) {
        double fitness = fitness_function(position);
        if (fitness < best_fitness) {
            best_fitness = fitness;
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double global_best_fitness;
    double (*fitness_function)(const std::vector<double>&);
    std::vector<std::pair<double, double>> bounds;

    Swarm(int num_particles, int dimensions, const std::vector<std::pair<double, double>>& bounds, double (*fitness_function)(const std::vector<double>&)) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1, 1);
        for (int i = 0; i < num_particles; ++i) {
            particles.push_back(Particle(dimensions));
        }
        global_best = std::vector<double>(dimensions, 0);
        for (int i = 0; i < dimensions; ++i) {
            global_best[i] = dis(gen);
        }
        global_best_fitness = INFINITY;
        this->fitness_function = fitness_function;
        this->bounds = bounds;
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position;
            }
        }
    }

    void optimize(double w, double c1, double c2) {
        while (true) {
            for (auto& particle : particles) {
                particle.update_velocity(global_best, w, c1, c2);
                particle.update_position(bounds);
                particle.evaluate_fitness(fitness_function);
            }
            update_global_best();
        }
    }
};

double fitness_function(const std::vector<double>& x) {
    double result = 0;
    for (double xi : x) {
        result += xi * xi;
    }
    return result;
}

int main() {
    int dimensions = 2;
    int num_particles = 30;
    std::vector<std::pair<double, double>> bounds = { {-10, 10}, {-10, 10} };
    Swarm swarm(num_particles, dimensions, bounds, fitness_function);
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    swarm.optimize(w, c1, c2);
    return 0;
}