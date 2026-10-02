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
        for (int i = 0; i < dimensions; ++i) {
            position.push_back(static_cast<double>(rand()) / RAND_MAX * 20 - 10);
            velocity.push_back(static_cast<double>(rand()) / RAND_MAX * 2 - 1);
        }
        best_position = position;
        best_score = std::numeric_limits<double>::max();
    }

    void update_velocity(Particle& global_best) {
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        for (int i = 0; i < position.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best.best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(-10.0, std::min(10.0, position[i]));
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        best_score = objective_function(position);
        if (best_score < best_score) {
            best_position = position;
        }
    }
};

class Swarm {
public:
    int size;
    int dimensions;
    std::vector<Particle> particles;
    Particle* global_best;

    Swarm(int size, int dimensions) : size(size), dimensions(dimensions) {
        for (int i = 0; i < size; ++i) {
            particles.push_back(Particle(dimensions));
        }
        global_best = nullptr;
    }

    void update_global_best() {
        for (Particle& particle : particles) {
            if (global_best == nullptr || particle.best_score < global_best->best_score) {
                global_best = &particle;
            }
        }
    }

    void update_particles() {
        for (Particle& particle : particles) {
            particle.update_velocity(*global_best);
            particle.update_position();
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

void main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int swarm_size = 30;
    int dimensions = 2;
    Swarm swarm(swarm_size, dimensions);
    for (int i = 0; i < 100; ++i) {
        swarm.update_global_best();
        for (Particle& particle : swarm.particles) {
            particle.evaluate(objective_function);
        }
        swarm.update_particles();
    }
    std::cout << swarm.global_best->best_score << " ";
    for (double pos : swarm.global_best->best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}