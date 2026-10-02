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
    double best_fitness;

    Particle(int dim) {
        position.resize(dim);
        velocity.resize(dim);
        best_position.resize(dim);
        best_fitness = std::numeric_limits<double>::infinity();
        for (int i = 0; i < dim; ++i) {
            position[i] = static_cast<double>(rand()) / RAND_MAX * 20 - 10;
            velocity[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
            best_position[i] = position[i];
        }
    }

    void update_velocity(const std::vector<double>& global_best, double w = 0.5, double c1 = 1.5, double c2 = 1.5) {
        for (int i = 0; i < position.size(); ++i) {
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
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
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_fitness;

    Swarm(int dim, int num_particles) {
        particles.resize(num_particles);
        global_best_position.resize(dim);
        global_best_fitness = std::numeric_limits<double>::infinity();
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dim);
        }
    }

    void update_global_best() {
        for (auto& particle : particles) {
            double fitness = evaluate(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                particle.best_position = particle.position;
            }
            if (fitness < global_best_fitness) {
                global_best_fitness = fitness;
                global_best_position = particle.position;
            }
        }
    }

    double evaluate(const std::vector<double>& position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void iterate() {
        update_global_best();
        for (auto& particle : particles) {
            particle.update_velocity(global_best_position);
            particle.update_position();
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int dim = 2;
    int num_particles = 10;
    Swarm swarm(dim, num_particles);
    while (true) {
        swarm.iterate();
    }
    return 0;
}