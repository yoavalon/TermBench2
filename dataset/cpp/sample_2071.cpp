#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>

class Particle {
public:
    Particle(int dim, const std::vector<std::pair<double, double>>& bounds) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1, 1);
        std::uniform_real_distribution<> dis_bound(0, 1);

        position.resize(dim);
        velocity.resize(dim);
        best_pos.resize(dim);

        for (int i = 0; i < dim; ++i) {
            position[i] = dis_bound(gen) * (bounds[i].second - bounds[i].first) + bounds[i].first;
            velocity[i] = dis(gen);
            best_pos[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = c1 * r1 * (best_pos[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[i].first, std::min(position[i], bounds[i].second));
        }
    }

    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_pos;
    double best_score;
};

class Swarm {
public:
    Swarm(int dim, int num_particles, const std::vector<std::pair<double, double>>& bounds) {
        particles.resize(num_particles);
        global_best.resize(dim);
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dim, bounds);
        }
        for (int i = 0; i < dim; ++i) {
            global_best[i] = std::numeric_limits<double>::infinity();
        }
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (auto& particle : particles) {
            double score = evaluate(particle.position);
            if (score < global_best_score) {
                global_best = particle.position;
                global_best_score = score;
                particle.best_score = score;
                particle.best_pos = particle.position;
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

    void run(int iterations) {
        for (int iter = 0; iter < iterations; ++iter) {
            for (auto& particle : particles) {
                particle.update_velocity(global_best);
                particle.update_position(bounds);
            }
            update_global_best();
        }
    }

private:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    std::vector<std::pair<double, double>> bounds;
    double global_best_score;
};

int main() {
    int dim = 3;
    int num_particles = 20;
    std::vector<std::pair<double, double>> bounds(dim, std::make_pair(-10, 10));
    Swarm swarm(dim, num_particles, bounds);
    swarm.run(100);
    std::cout << "Global Best Position: ";
    for (double x : swarm.global_best) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Global Best Score: " << swarm.global_best_score << std::endl;
    return 0;
}