#include <vector>
#include <cmath>

class Particle {
public:
    double position;
    double velocity;
    double best_position;

    Particle(double position, double velocity, double best_position)
        : position(position), velocity(velocity), best_position(best_position) {}

    void update_velocity(double global_best, double w, double c1, double c2) {
        double r1 = 0.5, r2 = 0.3;
        double new_velocity = w * velocity + c1 * r1 * (best_position - position) + c2 * r2 * (global_best - position);
        velocity = new_velocity;
    }

    void update_position() {
        position += velocity;
        if (position < best_position) {
            best_position = position;
        }
    }
};

double update_global_best(const std::vector<Particle>& particles) {
    double best = particles[0].best_position;
    for (const auto& particle : particles) {
        if (particle.best_position < best) {
            best = particle.best_position;
        }
    }
    return best;
}

double optimize(std::vector<Particle>& particles, double global_best, double w, double c1, double c2, int iterations) {
    if (iterations == 0) {
        return global_best;
    }
    for (auto& particle : particles) {
        particle.update_velocity(global_best, w, c1, c2);
        particle.update_position();
    }
    double new_global_best = update_global_best(particles);
    return optimize(particles, new_global_best, w, c1, c2, iterations - 1);
}

int main() {
    int num_particles = 10;
    std::vector<double> initial_positions(num_particles, 0.0);
    std::vector<double> initial_velocities(num_particles, 0.1);
    std::vector<double> best_positions(num_particles, 0.0);
    std::vector<Particle> particles;
    for (int i = 0; i < num_particles; ++i) {
        particles.emplace_back(initial_positions[i], initial_velocities[i], best_positions[i]);
    }
    double global_best = update_global_best(particles);
    double w = 0.7, c1 = 1.5, c2 = 1.5;
    int iterations = std::numeric_limits<int>::max();
    optimize(particles, global_best, w, c1, c2, iterations);
    return 0;
}