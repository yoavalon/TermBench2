#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

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
            position[i] = (double(rand()) / RAND_MAX) * 20 - 10;
            velocity[i] = (double(rand()) / RAND_MAX) * 2 - 1;
            best_position[i] = position[i];
        }
        best_score = INFINITY;
    }

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        for (int i = 0; i < position.size(); ++i) {
            double r1 = (double(rand()) / RAND_MAX);
            double r2 = (double(rand()) / RAND_MAX);
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            if (position[i] < -10) {
                position[i] = -10;
            } else if (position[i] > 10) {
                position[i] = 10;
            }
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double global_best_score;

    Swarm(int num_particles, int dimensions) {
        particles.resize(num_particles);
        global_best.resize(dimensions, INFINITY);
        global_best_score = INFINITY;
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions);
        }
    }

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best = particle.best_position;
                global_best_score = particle.best_score;
            }
        }
    }

    void optimize(int iterations, double w, double c1, double c2) {
        for (int _ = 0; _ < iterations; ++_) {
            update_global_best();
            for (auto& particle : particles) {
                particle.update_velocity(global_best, w, c1, c2);
                particle.update_position();
            }
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double result = 0.0;
    for (double xi : x) {
        result += xi * xi;
    }
    return result;
}

void main() {
    int dimensions = 30;
    int num_particles = 30;
    int iterations = 100;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;
    Swarm swarm(num_particles, dimensions);
    for (auto& particle : swarm.particles) {
        double score = objective_function(particle.position);
        if (score < particle.best_score) {
            particle.best_score = score;
        }
    }
    swarm.optimize(iterations, w, c1, c2);
    double best_score = swarm.global_best_score;
    std::cout << "Best Score: " << best_score << std::endl;
}

int main() {
    main();
    return 0;
}