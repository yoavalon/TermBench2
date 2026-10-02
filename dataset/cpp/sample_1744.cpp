cpp
#include <vector>
#include <cmath>
#include <algorithm>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;

    Particle(int dimensions) : position(dimensions, 0.0), velocity(dimensions, 0.0), best_position(position) {}

    void update(const std::vector<double>& global_best) {
        double w = 0.7, c1 = 1.5, c2 = 1.5;
        for (size_t i = 0; i < position.size(); ++i) {
            double r1 = 0.6, r2 = 0.3;
            double velocity_component_1 = w * velocity[i];
            double velocity_component_2 = c1 * r1 * (best_position[i] - position[i]);
            double velocity_component_3 = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3;
            position[i] += velocity[i];
            if (position[i] < -10 || position[i] > 10) {
                position[i] = best_position[i];
            }
        }
    }
};

class Swarm {
public:
    int size;
    int dimensions;
    std::vector<Particle> particles;

    Swarm(int size, int dimensions) : size(size), dimensions(dimensions), particles(size) {
        for (auto& particle : particles) {
            particle = Particle(dimensions);
        }
    }

    void update(const std::vector<double>& global_best) {
        for (auto& particle : particles) {
            particle.update(global_best);
        }
    }
};

double objective_function(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

void main() {
    int dimensions = 5;
    int swarm_size = 10;
    Swarm swarm(swarm_size, dimensions);
    std::vector<double> global_best(dimensions, 0.0);
    while (true) {
        for (const auto& particle : swarm.particles) {
            if (objective_function(particle.position) < objective_function(global_best)) {
                global_best = particle.position;
            }
        }
        swarm.update(global_best);
    }
}