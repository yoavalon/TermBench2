#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = static_cast<double>(rand()) / RAND_MAX * 20 - 10;
            velocity[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
            best_position[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best_position, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        for (int i = 0; i < velocity.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double (*cost_function)(const std::vector<double>&)) {
        double score = cost_function(position);
        if (score < best_score) {
            best_score = score;
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_score;

    Swarm(int size, int dimensions) {
        for (int i = 0; i < size; ++i) {
            particles.push_back(Particle(dimensions));
        }
        global_best_position.resize(dimensions);
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

    void update_swarm() {
        for (auto& particle : particles) {
            particle.update_velocity(global_best_position);
            particle.update_position();
        }
    }
};

double cost_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int dimensions = 10;
    int swarm_size = 20;
    Swarm swarm(swarm_size, dimensions);
    while (true) {
        for (auto& particle : swarm.particles) {
            particle.evaluate(cost_function);
        }
        swarm.update_global_best();
        swarm.update_swarm();
    }
    return 0;
}