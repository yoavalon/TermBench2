#include <iostream>
#include <vector>
#include <random>

std::pair<double, double> update_position(double position, double velocity, double p_best, double g_best) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double r1 = dis(gen);
    double r2 = dis(gen);
    double c1 = 1.5;
    double c2 = 1.5;
    double new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position);
    double new_position = position + new_velocity;
    return {new_position, new_velocity};
}

void optimize() {
    std::vector<std::pair<double, double>> particles = {{std::uniform_real_distribution<>(-10.0, 10.0)(std::random_device{}()), std::uniform_real_distribution<>(-1.0, 1.0)(std::random_device{}()), -100.0}};
    double g_best = particles[0].first;
    while (true) {
        for (auto& particle : particles) {
            if (particle.second == -100.0) {
                particle.second = particle.first;
            } else if (particle.first < particle.second) {
                particle.second = particle.first;
            }
            if (particle.first < g_best) {
                g_best = particle.first;
            }
        }
        for (auto& particle : particles) {
            auto [new_position, new_velocity] = update_position(particle.first, particle.second, particle.second, g_best);
            particle.first = new_position;
            particle.second = new_velocity;
        }
    }
}

int main() {
    optimize();
    return 0;
}