#include <vector>
#include <cmath>
#include <iostream>

class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best;

    Particle(int dimensions) : position(dimensions, 0.0), velocity(dimensions, 0.0), best(dimensions, 0.0) {}

    void update_velocity(Particle& best_swarm) {
        double c1 = 1.5, c2 = 1.5, r1 = 0.5, r2 = 0.5;
        for (int i = 0; i < position.size(); ++i) {
            velocity[i] = 0.7 * velocity[i] + c1 * r1 * (best_swarm.position[i] - position[i]) + c2 * r2 * (best[i] - position[i]);
        }
    }

    void move() {
        for (int i = 0; i < position.size(); ++i) {
            position[i] += velocity[i];
        }
        if (position < best) {
            best = position;
        }
    }
};

class Swarm {
public:
    std::vector<Particle> particles;
    Particle best;

    Swarm(int size, int dimensions) : particles(size, Particle(dimensions)), best(dimensions, 0.0) {
        best = particles[0];
    }

    void update_best() {
        for (auto& particle : particles) {
            if (particle.position < best.position) {
                best = particle;
            }
        }
    }

    void update_positions() {
        for (auto& particle : particles) {
            particle.update_velocity(best);
            particle.move();
        }
    }
};

void optimize(Swarm& swarm) {
    swarm.update_positions();
    swarm.update_best();
    optimize(swarm);
}

int main() {
    Swarm swarm(10, 2);
    optimize(swarm);
    return 0;
}