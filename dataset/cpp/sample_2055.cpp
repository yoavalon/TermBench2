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
        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = dis(gen) / 10.0;
            best_position[i] = position[i];
        }
        best_score = INFINITY;
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    std::vector<double> global_best_position;
    double global_best_score;

    Swarm(int num_particles, int dimensions) {
        particles.resize(num_particles);
        global_best_position.resize(dimensions);
        for (int i = 0; i < dimensions; ++i) {
            global_best_position[i] = 0.0;
        }
        global_best_score = INFINITY;
        for (int i = 0; i < num_particles; ++i) {
            particles[i] = Particle(dimensions);
        }
    }

    void update_global_best() {
        for (auto& particle : particles) {
            double score = evaluate(particle.position);
            if (score < global_best_score) {
                global_best_score = score;
                global_best_position = particle.position;
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

    void update_particles(double w, double c1, double c2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (auto& particle : particles) {
            for (int i = 0; i < particle.position.size(); ++i) {
                double r1 = dis(gen);
                double r2 = dis(gen);
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (global_best_position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
                double current_score = evaluate(particle.position);
                if (current_score < particle.best_score) {
                    particle.best_score = current_score;
                    particle.best_position = particle.position;
                }
            }
        }
    }
};

int main() {
    int dimensions = 30;
    int num_particles = 30;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    int iterations = 100;
    Swarm swarm(num_particles, dimensions);
    for (int i = 0; i < iterations; ++i) {
        swarm.update_global_best();
        swarm.update_particles(w, c1, c2);
    }
    std::cout << "Best score: " << swarm.global_best_score << std::endl;
    return 0;
}