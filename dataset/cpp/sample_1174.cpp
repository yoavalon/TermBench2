#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) : position(dimensions, 0.0), velocity(dimensions, 0.0), best_position(dimensions, 0.0), best_score(std::numeric_limits<double>::infinity()) {}

    void update_velocity(const std::vector<double>& global_best, double w, double c1, double c2) {
        for (int i = 0; i < position.size(); ++i) {
            double r1 = 0.5, r2 = 0.5;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
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

    void evaluate(double (*score_function)(const std::vector<double>&)) {
        best_score = score_function(position);
        if (best_score < score_function(best_position)) {
            best_position = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best;
    double global_best_score;
    std::vector<std::pair<double, double>> bounds;
    double w, c1, c2;

    Swarm(int dimensions, int num_particles, const std::vector<std::pair<double, double>>& bounds, double w, double c1, double c2)
        : particles(num_particles, Particle(dimensions)), global_best(dimensions, 0.0), global_best_score(std::numeric_limits<double>::infinity()), bounds(bounds), w(w), c1(c1), c2(c2) {}

    void update_global_best() {
        for (const auto& particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best = particle.best_position;
            }
        }
    }

    void iterate(double (*score_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(bounds);
            particle.evaluate(score_function);
        }
        update_global_best();
    }
};

double score_function(const std::vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

int main() {
    int dimensions = 2;
    int num_particles = 10;
    std::vector<std::pair<double, double>> bounds = { {-10, 10}, {-10, 10} };
    double w = 0.7;
    double c1 = 2.0;
    double c2 = 2.0;

    Swarm swarm(dimensions, num_particles, bounds, w, c1, c2);
    while (true) {
        swarm.iterate(score_function);
    }
    return 0;
}