#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions, std::pair<double, double> bounds) {
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = bounds.first + (bounds.second - bounds.first) * (static_cast<double>(rand()) / RAND_MAX);
            velocity[i] = 0.0;
            best_position[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::pair<double, double> bounds;
    double (*function)(const std::vector<double>&);
    double w, c1, c2;
    std::vector<double> best_swarm_position;
    double best_swarm_score;

    Swarm(int num_particles, std::pair<double, double> bounds, double (*function)(const std::vector<double>&), double w, double c1, double c2) {
        particles.resize(num_particles);
        this->bounds = bounds;
        this->function = function;
        this->w = w;
        this->c1 = c1;
        this->c2 = c2;
        best_swarm_position.resize(bounds.second - bounds.first);
        best_swarm_score = std::numeric_limits<double>::infinity();
    }

    void evaluate() {
        for (auto& particle : particles) {
            double score = function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = particle.position;
            }
            if (score < best_swarm_score) {
                best_swarm_score = score;
                best_swarm_position = particle.position;
            }
        }
    }

    void update() {
        for (auto& particle : particles) {
            for (int i = 0; i < particle.position.size(); ++i) {
                double r1 = static_cast<double>(rand()) / RAND_MAX;
                double r2 = static_cast<double>(rand()) / RAND_MAX;
                double velocity_cognitive = c1 * r1 * (particle.best_position[i] - particle.position[i]);
                double velocity_social = c2 * r2 * (best_swarm_position[i] - particle.position[i]);
                particle.velocity[i] = w * particle.velocity[i] + velocity_cognitive + velocity_social;
                particle.position[i] += particle.velocity[i];
                particle.position[i] = std::max(bounds.first, std::min(bounds.second, particle.position[i]));
            }
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

std::pair<std::vector<double>, double> optimize(int dimensions, std::pair<double, double> bounds, int num_particles, int max_iterations, double w, double c1, double c2) {
    std::vector<Particle> particles(num_particles, Particle(dimensions, bounds));
    Swarm swarm(num_particles, bounds, objective_function, w, c1, c2);
    for (int i = 0; i < max_iterations; ++i) {
        swarm.evaluate();
        swarm.update();
    }
    return {swarm.best_swarm_position, swarm.best_swarm_score};
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int dimensions = 2;
    std::pair<double, double> bounds = {-10, 10};
    int num_particles = 30;
    int max_iterations = 100;
    double w = 0.729;
    double c1 = 1.494;
    double c2 = 1.494;
    auto result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2);
    std::cout << "Best position: ";
    for (double pos : result.first) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best score: " << result.second << std::endl;
    return 0;
}