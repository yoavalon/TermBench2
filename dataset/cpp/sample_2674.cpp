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
    double best_value;

    Particle(int dimensions) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = ((double)rand() / RAND_MAX) * 20 - 10;
            velocity[i] = ((double)rand() / RAND_MAX) * 2 - 1;
            best_position[i] = position[i];
        }
        best_value = calculate_value();
    }

    double calculate_value() {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void update(const std::vector<double>& global_best) {
        const double w = 0.7;
        const double c1 = 1.5;
        const double c2 = 1.5;
        for (int i = 0; i < position.size(); ++i) {
            double r1 = ((double)rand() / RAND_MAX);
            double r2 = ((double)rand() / RAND_MAX);
            velocity[i] = w * velocity[i] + c1 * r1 * (best_position[i] - position[i]) + c2 * r2 * (global_best[i] - position[i]);
            position[i] += velocity[i];
        }
        best_value = calculate_value();
        if (best_value < best_value) {
            best_value = best_value;
            best_position = position;
        }
    }
};

class Swarm {
public:
    int size;
    int dimensions;
    std::vector<Particle> particles;
    std::vector<double> best_position;
    double best_value;

    Swarm(int size, int dimensions) : size(size), dimensions(dimensions), particles(size), best_value(INFINITY) {
        best_position.resize(dimensions);
        for (int i = 0; i < size; ++i) {
            particles[i] = Particle(dimensions);
        }
    }

    void update_best() {
        for (const Particle& particle : particles) {
            if (particle.best_value < best_value) {
                best_value = particle.best_value;
                best_position = particle.best_position;
            }
        }
    }

    void optimize(int iterations) {
        for (int _ = 0; _ < iterations; ++_) {
            for (Particle& particle : particles) {
                particle.update(best_position);
            }
            update_best();
        }
    }
};

void main() {
    srand(time(0));
    int dimensions = 2;
    int swarm_size = 30;
    int iterations = 100;
    Swarm swarm(swarm_size, dimensions);
    swarm.optimize(iterations);
    std::cout << "Best position: ";
    for (double x : swarm.best_position) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Best value: " << swarm.best_value << std::endl;
}

int main() {
    main();
    return 0;
}