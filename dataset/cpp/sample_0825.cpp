#include <vector>
#include <cmath>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    double fitness;

    Particle(int dimensions) : position(dimensions, 0.0), velocity(dimensions, 0.0), fitness(0.0) {}

    void update_velocity(const std::vector<double>& best_position) {
        double w = 0.7, c1 = 1.5, c2 = 1.5;
        for (int i = 0; i < position.size(); ++i) {
            double r1 = 0.5, r2 = 0.5;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
        fitness = calculate_fitness();
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
    std::vector<double> best_position;

    Swarm(int size, int dimensions) : particles(size, Particle(dimensions)) {
        best_position = particles[0].position;
    }

    void update_best_position() {
        for (const Particle& particle : particles) {
            if (particle.fitness > fitness(best_position)) {
                best_position = particle.position;
            }
        }
    }

    void update_particles(int iterations) {
        if (iterations > 0) {
            for (Particle& particle : particles) {
                particle.update_velocity(best_position);
                particle.update_position();
            }
            update_best_position();
            update_particles(iterations - 1);
        }
    }

    double fitness(const std::vector<double>& position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }
};

void optimize(Swarm& swarm, int iterations) {
    swarm.update_particles(iterations);
}

int main() {
    int dimensions = 2;
    int swarm_size = 10;
    int iterations = 50;
    Swarm swarm(swarm_size, dimensions);
    optimize(swarm, iterations);
    return 0;
}