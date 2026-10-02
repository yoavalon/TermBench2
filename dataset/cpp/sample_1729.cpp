#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best;

    Particle(double x, double y) {
        position = {x, y};
        velocity = {0.0, 0.0};
        best = position;
    }

    double evaluate() {
        return -(position[0] * position[0] + position[1] * position[1]);
    }

    void update_velocity(const Particle& global_best) {
        const double inertia = 0.7;
        const double cognitive = 1.5;
        const double social = 1.5;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < 2; ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive_component = cognitive * r1 * (best[i] - position[i]);
            double social_component = social * r2 * (global_best.position[i] - position[i]);
            velocity[i] = inertia * velocity[i] + cognitive_component + social_component;
        }
    }

    void move() {
        for (int i = 0; i < 2; ++i) {
            position[i] += velocity[i];
            position[i] = std::max(-1.0, std::min(1.0, position[i]));
        }
        if (evaluate() < best[0]) {
            best = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    Particle best;

    Swarm(int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);

        for (int i = 0; i < size; ++i) {
            particles.emplace_back(dis(gen), dis(gen));
        }
        best = *std::min_element(particles.begin(), particles.end(), [](const Particle& a, const Particle& b) {
            return a.evaluate() < b.evaluate();
        });
    }

    void update() {
        for (auto& particle : particles) {
            particle.update_velocity(best);
            particle.move();
        }
        best = *std::min_element(particles.begin(), particles.end(), [](const Particle& a, const Particle& b) {
            return a.evaluate() < b.evaluate();
        });
    }
};

void run() {
    int swarm_size = 30;
    Swarm swarm(swarm_size);
    while (true) {
        swarm.update();
    }
}

int main() {
    run();
    return 0;
}