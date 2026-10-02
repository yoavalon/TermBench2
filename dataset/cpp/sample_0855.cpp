#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);

        position = std::vector<double>(dimensions);
        velocity = std::vector<double>(dimensions);
        best_position = std::vector<double>(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen);
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best, double inertia, double cognitive, double social) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            velocity[i] = inertia * velocity[i] + cognitive * r1 * (best_position[i] - position[i]) + social * r2 * (global_best[i] - position[i]);
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double (*fitness_function)(const std::vector<double>&)) {
        double score = fitness_function(position);
        if (score < best_score) {
            best_score = score;
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    double (*fitness_function)(const std::vector<double>&);
    int max_iterations;
    double inertia;
    double cognitive;
    double social;
    std::vector<double> global_best;
    double global_best_score;

    Swarm(int size, int dimensions, double (*fitness_function)(const std::vector<double>&), int max_iterations, double inertia, double cognitive, double social) {
        particles = std::vector<Particle>(size);
        for (int i = 0; i < size; ++i) {
            particles[i] = Particle(dimensions);
        }
        this->fitness_function = fitness_function;
        this->max_iterations = max_iterations;
        this->inertia = inertia;
        this->cognitive = cognitive;
        this->social = social;
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best = particle.best_position;
            }
        }
    }

    void optimize() {
        for (int i = 0; i < max_iterations; ++i) {
            for (auto& particle : particles) {
                particle.update_velocity(global_best, inertia, cognitive, social);
                particle.update_position();
                particle.evaluate(fitness_function);
            }
            update_global_best();
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
    int dimensions = 2;
    int size = 30;
    int max_iterations = 100;
    double inertia = 0.5;
    double cognitive = 1.5;
    double social = 1.5;
    Swarm swarm(size, dimensions, sphere_function, max_iterations, inertia, cognitive, social);
    swarm.optimize();
    std::cout << "Best position: ";
    for (double x : swarm.global_best) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Best score: " << swarm.global_best_score << std::endl;
    return 0;
}