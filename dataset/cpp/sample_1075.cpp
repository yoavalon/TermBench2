#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

double random_double() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

std::vector<double> update_velocity(const std::vector<double>& p, const std::vector<double>& g, const std::vector<double>& l, double w, double c1, double c2) {
    std::vector<double> v(l.size());
    for (size_t j = 0; j < l.size(); ++j) {
        double r1 = random_double();
        double r2 = random_double();
        v[j] = w * l[j] + c1 * r1 * (p[j] - l[j]) + c2 * r2 * (g[j] - l[j]);
    }
    return v;
}

std::vector<double> update_position(const std::vector<double>& l, const std::vector<double>& v) {
    std::vector<double> p(l.size());
    for (size_t j = 0; j < l.size(); ++j) {
        p[j] = l[j] + v[j];
    }
    return p;
}

void swarm_search(std::function<double(const std::vector<double>&)> f, const std::vector<std::pair<double, double>>& bounds, int n_particles, double w, double c1, double c2) {
    std::vector<std::vector<double>> particles(n_particles, std::vector<double>(bounds.size()));
    std::vector<std::vector<double>> velocities(n_particles, std::vector<double>(bounds.size(), 0.0));
    std::vector<std::vector<double>> pbest = particles;
    std::vector<double> gbest(bounds.size());

    for (int i = 0; i < n_particles; ++i) {
        for (size_t j = 0; j < bounds.size(); ++j) {
            particles[i][j] = random_double() * (bounds[j].second - bounds[j].first) + bounds[j].first;
        }
    }

    gbest = *std::min_element(particles.begin(), particles.end(), [&f](const std::vector<double>& a, const std::vector<double>& b) {
        return f(a) < f(b);
    });

    while (true) {
        for (int i = 0; i < n_particles; ++i) {
            velocities[i] = update_velocity(pbest[i], gbest, particles[i], w, c1, c2);
            particles[i] = update_position(particles[i], velocities[i]);
        }

        for (int i = 0; i < n_particles; ++i) {
            if (f(particles[i]) < f(pbest[i])) {
                pbest[i] = particles[i];
            }
        }

        gbest = *std::min_element(particles.begin(), particles.end(), [&f](const std::vector<double>& a, const std::vector<double>& b) {
            return f(a) < f(b);
        });
    }
}

double objective(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    std::vector<std::pair<double, double>> bounds = { {-10, 10}, {-10, 10} };
    swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5);
    return 0;
}