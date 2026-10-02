#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

class Particle {
public:
    Particle(int dimensions, double lower_bound, double upper_bound) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower_bound, upper_bound);
        std::uniform_real_distribution<> vel_dis(-1, 1);

        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = vel_dis(gen);
            best_position[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best_position, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            velocity[i] = w * velocity[i] + c1 * r1 * (best_position[i] - position[i]) + c2 * r2 * (global_best_position[i] - position[i]);
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

    double best_score;
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
};

class Swarm {
public:
    Swarm(int size, int dimensions, double lower_bound, double upper_bound) {
        particles.resize(size);
        global_best_position.resize(dimensions);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower_bound, upper_bound);

        for (int i = 0; i < size; ++i) {
            particles[i] = Particle(dimensions, lower_bound, upper_bound);
        }

        for (int i = 0; i < dimensions; ++i) {
            global_best_position[i] = dis(gen);
        }
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best_position = particle.best_position;
            }
        }
    }

    void iterate(double (*fitness_function)(const std::vector<double>&), double w, double c1, double c2) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        update_global_best();
    }

    double global_best_score;
    std::vector<double> global_best_position;
    std::vector<Particle> particles;
};

double fitness_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    int dimensions = 2;
    double lower_bound = -10;
    double upper_bound = 10;
    int swarm_size = 30;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;

    Swarm swarm(swarm_size, dimensions, lower_bound, upper_bound);
    for (int i = 0; i < iterations; ++i) {
        swarm.iterate(fitness_function, w, c1, c2);
    }

    std::cout << "Global best score: " << swarm.global_best_score << std::endl;
    std::cout << "Global best position: ";
    for (double x : swarm.global_best_position) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}