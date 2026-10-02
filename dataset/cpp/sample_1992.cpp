#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

double fitness_function(double x) {
    return x * x;
}

std::pair<double, double> update_position(double position, double velocity, double w, double c1, double c2, double pbest, double gbest) {
    double r1 = static_cast<double>(rand()) / RAND_MAX;
    double r2 = static_cast<double>(rand()) / RAND_MAX;
    velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position);
    position = position + velocity;
    return std::make_pair(position, velocity);
}

double optimize(int iterations, double w, double c1, double c2, std::pair<double, double> bounds) {
    std::vector<double> particles(30);
    std::vector<double> velocities(30, 0.0);
    std::vector<double> pbests(30);
    for (int i = 0; i < 30; ++i) {
        particles[i] = bounds.first + static_cast<double>(rand()) / RAND_MAX * (bounds.second - bounds.first);
        pbests[i] = particles[i];
    }
    double gbest = *std::min_element(particles.begin(), particles.end(), [](double a, double b) {
        return fitness_function(a) < fitness_function(b);
    });
    for (int _ = 0; _ < iterations; ++_) {
        for (int i = 0; i < 30; ++i) {
            auto [new_position, new_velocity] = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest);
            particles[i] = new_position;
            velocities[i] = new_velocity;
            if (fitness_function(particles[i]) < fitness_function(pbests[i])) {
                pbests[i] = particles[i];
            }
        }
        gbest = *std::min_element(particles.begin(), particles.end(), [](double a, double b) {
            return fitness_function(a) < fitness_function(b);
        });
    }
    return gbest;
}

int main() {
    int iterations = 100;
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    std::pair<double, double> bounds = {-10, 10};
    double result = optimize(iterations, w, c1, c2, bounds);
    std::cout << result << std::endl;
    return 0;
}