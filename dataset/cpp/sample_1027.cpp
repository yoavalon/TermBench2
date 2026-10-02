#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<double> update_velocity(const std::vector<double>& pos, const std::vector<double>& vel, const std::vector<double>& best_pos, const std::vector<double>& global_best) {
    double w = 0.7;
    double c1 = 1.5;
    double c2 = 1.5;
    double r1 = 0.5;
    double r2 = 0.5;
    std::vector<double> new_vel(pos.size());
    for (size_t j = 0; j < pos.size(); ++j) {
        new_vel[j] = w * vel[j] + c1 * r1 * (best_pos[j] - pos[j]) + c2 * r2 * (global_best[j] - pos[j]);
    }
    return new_vel;
}

std::vector<double> update_position(const std::vector<double>& pos, const std::vector<double>& vel) {
    std::vector<double> new_pos(pos.size());
    for (size_t j = 0; j < pos.size(); ++j) {
        new_pos[j] = pos[j] + vel[j];
    }
    return new_pos;
}

void optimize(double (*func)(double), const std::vector<double>& bounds, int n_particles = 30, int max_iter = 1000) {
    std::vector<double> particles(n_particles);
    std::vector<double> velocities(n_particles, 0.0);
    std::vector<double> personal_best(n_particles);
    double global_best;

    for (int i = 0; i < n_particles; ++i) {
        particles[i] = bounds[0] + (bounds[1] - bounds[0]) * i / n_particles;
        personal_best[i] = particles[i];
    }
    global_best = *std::min_element(particles.begin(), particles.end(), [func](double a, double b) { return func(a) < func(b); });

    auto iterate = [&func, &particles, &velocities, &personal_best, &global_best, n_particles, &iterate](int i) {
        for (int j = 0; j < n_particles; ++j) {
            velocities[j] = update_velocity({particles[j]}, {velocities[j]}, {personal_best[j]}, {global_best})[0];
            particles[j] = update_position({particles[j]}, {velocities[j]})[0];
            if (func(particles[j]) < func(personal_best[j])) {
                personal_best[j] = particles[j];
            }
        }
        global_best = *std::min_element(personal_best.begin(), personal_best.end(), [func](double a, double b) { return func(a) < func(b); });
        iterate(i + 1);
    };
    iterate(0);
}

double test_func(double x) {
    return x * x;
}

int main() {
    std::vector<double> bounds = {-100, 100};
    optimize(test_func, bounds);
    return 0;
}