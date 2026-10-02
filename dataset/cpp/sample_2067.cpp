#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_pos;
    double best_score;

    Particle(int dim) : position(dim, 0.0), velocity(dim, 0.0), best_pos(dim, 0.0), best_score(std::numeric_limits<double>::max()) {}

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            velocity[i] = w * velocity[i] + c1 * r1 * (best_pos[i] - position[i]) + c2 * r2 * (global_best[i] - position[i]);
        }
    }

    void update_position(const std::vector<std::vector<double>>& bounds) {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
            position[i] = std::max(bounds[0][i], std::min(bounds[1][i], position[i]));
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> best_global_pos;
    double best_global_score;

    Swarm(int num_particles, int dim, const std::vector<std::vector<double>>& bounds) 
        : particles(num_particles, Particle(dim)), best_global_pos(dim, 0.0), best_global_score(std::numeric_limits<double>::max()) {}

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < best_global_score) {
                best_global_score = particle.best_score;
                best_global_pos = particle.best_pos;
            }
        }
    }

    void optimize(double (*fitness_func)(const std::vector<double>&), int max_iter, double w, double c1, double c2) {
        for (int _ = 0; _ < max_iter; ++_) {
            for (auto& particle : particles) {
                particle.update_velocity(best_global_pos, w, c1, c2);
                particle.update_position(bounds);
                double score = fitness_func(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_pos = particle.position;
                }
            }
            update_global_best();
        }
    }
};

double fitness_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void main() {
    int num_particles = 30;
    int dim = 2;
    std::vector<std::vector<double>> bounds = {{0.0, 0.0}, {10.0, 10.0}};
    int max_iter = 100;
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;
    Swarm swarm(num_particles, dim, bounds);
    swarm.optimize(fitness_function, max_iter, w, c1, c2);
    std::cout << "Best global position: ";
    for (double pos : swarm.best_global_pos) {
        std::cout << pos << " ";
    }
    std::cout << "Best global score: " << swarm.best_global_score << std::endl;
}

int main() {
    main();
    return 0;
}