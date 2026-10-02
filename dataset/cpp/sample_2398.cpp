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

    Particle(int dimensions, double lower_bound, double upper_bound) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower_bound, upper_bound);
        std::uniform_real_distribution<> dis_v(-1.0, 1.0);

        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis_v(gen);
            best_position[i] = position[i];
        }
        best_fitness = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best_position, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive_velocity = c1 * r1 * (best_position[i] - position[i]);
            double social_velocity = c2 * r2 * (global_best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive_velocity + social_velocity;
        }
    }

    void update_position(double lower_bound, double upper_bound) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(lower_bound, std::min(upper_bound, position[i]));
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_fitness;

    Swarm(int num_particles, int dimensions, double lower_bound, double upper_bound) {
        particles.resize(num_particles);
        global_best_position.resize(dimensions);

        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions, lower_bound, upper_bound);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(lower_bound, upper_bound);

        for (int i = 0; i < dimensions; ++i) {
            global_best_position[i] = dis(gen);
        }
        global_best_fitness = std::numeric_limits<double>::infinity();
    }

    void evaluate_fitness(double (*objective_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            double fitness = objective_function(particle.position);
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

    void update_particles(double w, double c1, double c2) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best_position, w, c1, c2);
            particle.update_position(-10, 10);
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double result = 0.0;
    for (int i = 0; i < x.size(); ++i) {
        result += std::sin(x[i]) * std::sin(x[i] + (i + 1) * M_PI / x.size());
    }
    return result;
}

int main() {
    int num_particles = 30;
    int dimensions = 30;
    double lower_bound = -10;
    double upper_bound = 10;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;

    Swarm swarm(num_particles, dimensions, lower_bound, upper_bound);
    while (true) {
        swarm.evaluate_fitness(objective_function);
        swarm.update_particles(w, c1, c2);
    }

    return 0;
}