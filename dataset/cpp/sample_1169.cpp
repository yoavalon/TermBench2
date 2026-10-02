#include <vector>
#include <cmath>
#include <limits>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double fitness;

    Particle(int dimensions) {
        position = std::vector<double>(dimensions, 0.0);
        velocity = std::vector<double>(dimensions, 0.0);
        best_position = position;
        fitness = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const Particle& gbest) {
        for (int i = 0; i < position.size(); ++i) {
            double r1 = 0.5;
            double r2 = 0.5;
            double inertia = 0.7;
            velocity[i] = inertia * velocity[i] + r1 * (best_position[i] - position[i]) + r2 * (gbest.position[i] - position[i]);
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            if (fitness > calculate_fitness()) {
                best_position = position;
                fitness = calculate_fitness();
            }
        }
    }

    double calculate_fitness() {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    Particle gbest;

    Swarm(int size, int dimensions) {
        particles = std::vector<Particle>(size, Particle(dimensions));
        gbest = particles[0];
    }

    void update_gbest() {
        for (const Particle& particle : particles) {
            if (particle.fitness < gbest.fitness) {
                gbest = particle;
            }
        }
    }

    void optimize() {
        while (true) {
            for (Particle& particle : particles) {
                particle.update_velocity(gbest);
                particle.update_position();
            }
            update_gbest();
        }
    }
};

void main() {
    Swarm swarm(10, 2);
    swarm.optimize();
}