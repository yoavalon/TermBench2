#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

class Particle {
public:
    Particle(int dimensions, const std::vector<double>* position = nullptr) {
        if (position) {
            this->position = *position;
        } else {
            for (int i = 0; i < dimensions; ++i) {
                this->position.push_back(static_cast<double>(rand()) / RAND_MAX * 2 - 1);
            }
        }
        for (int i = 0; i < dimensions; ++i) {
            velocity.push_back(static_cast<double>(rand()) / RAND_MAX * 2 - 1);
        }
        best_position = this->position;
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        for (size_t i = 0; i < position.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(const std::pair<double, double>& bounds) {
        for (size_t i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            if (bounds.first != bounds.second) {
                position[i] = std::max(bounds.first, std::min(bounds.second, position[i]));
            }
        }
    }

    void evaluate(double (*function)(const std::vector<double>&)) {
        current_score = function(position);
        if (current_score < best_score) {
            best_score = current_score;
            best_position = position;
        }
    }

    std::vector<double> position, velocity, best_position;
    double best_score, current_score;
};

class Swarm {
public:
    Swarm(int dimensions, int num_particles, const std::pair<double, double>& bounds) {
        for (int i = 0; i < num_particles; ++i) {
            particles.push_back(Particle(dimensions));
        }
        global_best_score = std::numeric_limits<double>::infinity();
        this->bounds = bounds;
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best = particle.best_position;
            }
        }
    }

    void optimize(double (*function)(const std::vector<double>&), int iterations) {
        for (int i = 0; i < iterations; ++i) {
            update_global_best();
            for (auto& particle : particles) {
                particle.update_velocity(global_best);
                particle.update_position(bounds);
                particle.evaluate(function);
            }
        }
    }

    std::vector<double> global_best;
    double global_best_score;
private:
    std::vector<Particle> particles;
    std::pair<double, double> bounds;
};

double objective_function(const std::vector<double>& x) {
    double sum = 0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int dimensions = 2;
    int num_particles = 30;
    std::pair<double, double> bounds = {-10, 10};
    int iterations = 100;
    Swarm swarm(dimensions, num_particles, bounds);
    swarm.optimize(objective_function, iterations);
    std::cout << "Global Best Position: ";
    for (double pos : swarm.global_best) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Global Best Score: " << swarm.global_best_score << std::endl;
    return 0;
}