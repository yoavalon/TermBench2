#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(-10, 10);
uniform_real_distribution<> dis_vel(-1, 1);
uniform_real_distribution<> dis_rand(0, 1);

struct Particle {
    vector<double> position;
    vector<double> velocity;
    vector<double> pbest_position;
    double pbest_value;
};

vector<Particle> initialize_particles(int size, int dimensions) {
    vector<Particle> particles;
    for (int _ = 0; _ < size; ++_) {
        Particle particle;
        for (int _ = 0; _ < dimensions; ++_) {
            particle.position.push_back(dis(gen));
            particle.velocity.push_back(dis_vel(gen));
        }
        particle.pbest_position = particle.position;
        particle.pbest_value = numeric_limits<double>::infinity();
        particles.push_back(particle);
    }
    return particles;
}

void update_velocity(vector<Particle>& particles, const vector<double>& gbest_position, double w = 0.7, double c1 = 1.5, double c2 = 1.5) {
    for (auto& particle : particles) {
        for (int i = 0; i < particle.position.size(); ++i) {
            double r1 = dis_rand(gen);
            double r2 = dis_rand(gen);
            double cognitive = c1 * r1 * (particle.pbest_position[i] - particle.position[i]);
            double social = c2 * r2 * (gbest_position[i] - particle.position[i]);
            particle.velocity[i] = w * particle.velocity[i] + cognitive + social;
        }
    }
}

void update_position(vector<Particle>& particles, const pair<double, double>& bounds) {
    for (auto& particle : particles) {
        for (int i = 0; i < particle.position.size(); ++i) {
            particle.position[i] += particle.velocity[i];
            particle.position[i] = max(bounds.first, min(particle.position[i], bounds.second));
        }
    }
}

void evaluate(vector<Particle>& particles, function<double(const vector<double>&)> objective_function) {
    for (auto& particle : particles) {
        double value = objective_function(particle.position);
        if (value < particle.pbest_value) {
            particle.pbest_value = value;
            particle.pbest_position = particle.position;
        }
    }
}

vector<double> find_gbest(const vector<Particle>& particles) {
    double gbest_value = numeric_limits<double>::infinity();
    vector<double> gbest_position;
    for (const auto& particle : particles) {
        if (particle.pbest_value < gbest_value) {
            gbest_value = particle.pbest_value;
            gbest_position = particle.pbest_position;
        }
    }
    return gbest_position;
}

vector<double> optimize(function<double(const vector<double>&)> objective_function, int dimensions, int size, int iterations, const pair<double, double>& bounds) {
    vector<Particle> particles = initialize_particles(size, dimensions);
    vector<double> gbest_position = find_gbest(particles);
    for (int _ = 0; _ < iterations; ++_) {
        update_velocity(particles, gbest_position);
        update_position(particles, bounds);
        evaluate(particles, objective_function);
        gbest_position = find_gbest(particles);
    }
    return gbest_position;
}

double sphere_function(const vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += xi * xi;
    }
    return sum;
}

int main() {
    int dimensions = 30;
    int size = 30;
    int iterations = 100;
    pair<double, double> bounds = {-10, 10};
    vector<double> result = optimize(sphere_function, dimensions, size, iterations, bounds);
    for (double val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}