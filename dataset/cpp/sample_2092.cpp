#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        for (int i = 0; i < dimensions; ++i) {
            position.push_back(dis(gen));
            velocity.push_back(dis(gen) / 10.0);
        }
        best_position = position;
        best_score = std::numeric_limits<double>::infinity();
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> gbest_position;
    double gbest_score;

    Swarm(int num_particles, int dimensions) {
        for (int i = 0; i < num_particles; ++i) {
            particles.push_back(Particle(dimensions));
        }
        gbest_score = std::numeric_limits<double>::infinity();
    }

    void update_gbest() {
        for (const auto& particle : particles) {
            if (particle.best_score < gbest_score) {
                gbest_score = particle.best_score;
                gbest_position = particle.best_position;
            }
        }
    }

    void update_particles(double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (auto& particle : particles) {
            for (int i = 0; i < particle.position.size(); ++i) {
                double r1 = dis(gen);
                double r2 = dis(gen);
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (gbest_position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        for (auto& particle : particles) {
            double score = objective_function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = particle.position;
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

int main() {
    int dimensions = 3;
    int num_particles = 20;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;
    Swarm swarm(num_particles, dimensions);
    for (int i = 0; i < iterations; ++i) {
        swarm.update_gbest();
        swarm.update_particles(w, c1, c2);
        swarm.evaluate(objective_function);
    }
    std::cout << "Best score: " << swarm.gbest_score << std::endl;
    std::cout << "Best position: ";
    for (double pos : swarm.gbest_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    return 0;
}