#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_score;

    Particle(int dimensions, const std::pair<double, double>& search_space) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(search_space.first, search_space.second);

        position.resize(dimensions);
        velocity.resize(dimensions);
        best_position.resize(dimensions);

        for (int i = 0; i < dimensions; ++i) {
            position[i] = dis(gen);
            velocity[i] = 0.0;
            best_position[i] = position[i];
        }
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_velocity(const std::vector<double>& global_best) {
        double inertia = 0.5;
        double cognitive_factor = 1.5;
        double social_factor = 1.5;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < position.size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive = cognitive_factor * r1 * (best_position[i] - position[i]);
            double social = social_factor * r2 * (global_best[i] - position[i]);
            velocity[i] = inertia * velocity[i] + cognitive + social;
        }
    }

    void move() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
    }

    void evaluate() {
        score = objective_function();
        if (score < best_score) {
            best_score = score;
            best_position = position;
        }
    }

private:
    double objective_function() {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    double score;
};

class Swarm {
public:
    int size;
    int dimensions;
    std::pair<double, double> search_space;
    std::vector<Particle> particles;
    std::vector<double> best_position;
    double best_score;

    Swarm(int size, int dimensions, const std::pair<double, double>& search_space) 
        : size(size), dimensions(dimensions), search_space(search_space) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, size - 1);

        for (int i = 0; i < size; ++i) {
            particles.emplace_back(dimensions, search_space);
        }
        best_position = particles[dis(gen)].position;
        best_score = std::numeric_limits<double>::infinity();
    }

    void update_best_position() {
        for (const auto& particle : particles) {
            if (particle.best_score < best_score) {
                best_score = particle.best_score;
                best_position = particle.best_position;
            }
        }
    }

    void iterate() {
        for (auto& particle : particles) {
            particle.update_velocity(best_position);
            particle.move();
            particle.evaluate();
        }
    }

    void run(int iterations) {
        for (int i = 0; i < iterations; ++i) {
            iterate();
            update_best_position();
        }
    }
};

void main() {
    int swarm_size = 30;
    int dimensions = 2;
    std::pair<double, double> search_space = {-10, 10};
    int iterations = 100;
    Swarm swarm(swarm_size, dimensions, search_space);
    swarm.run(iterations);
    std::cout << "Best position: ";
    for (double pos : swarm.best_position) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << "Best score: " << swarm.best_score << std::endl;
}

int main() {
    main();
    return 0;
}