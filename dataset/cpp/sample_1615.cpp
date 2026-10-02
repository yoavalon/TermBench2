#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

double evaluate(const vector<double>& position) {
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

vector<double> initialize_position(int dimensions) {
    vector<double> position(dimensions);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-10.0, 10.0);
    for (int i = 0; i < dimensions; ++i) {
        position[i] = dis(gen);
    }
    return position;
}

vector<vector<double>> initialize_particles(int dimensions, int population_size) {
    vector<vector<double>> particles;
    for (int i = 0; i < population_size; ++i) {
        vector<double> position = initialize_position(dimensions);
        vector<double> velocity(dimensions, 0.0);
        particles.push_back({position, velocity, position});
    }
    return particles;
}

vector<double> find_global_best(const vector<vector<double>>& particles) {
    vector<double> global_best = particles[0];
    for (const auto& particle : particles) {
        if (evaluate(particle[0]) < evaluate(global_best)) {
            global_best = particle[0];
        }
    }
    return global_best;
}

void update_particles(vector<vector<double>>& particles, const vector<double>& global_best) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    for (auto& particle : particles) {
        for (int i = 0; i < particle[0].size(); ++i) {
            double r1 = dis(gen);
            double r2 = dis(gen);
            double cognitive_velocity = r1 * (particle[2][i] - particle[0][i]);
            double social_velocity = r2 * (global_best[i] - particle[0][i]);
            particle[1][i] = 0.7 * particle[1][i] + cognitive_velocity + social_velocity;
            particle[0][i] += particle[1][i];
        }
        if (evaluate(particle[0]) < evaluate(particle[2])) {
            particle[2] = particle[0];
        }
    }
}

int main() {
    int dimensions = 2;
    int population_size = 10;
    vector<vector<double>> particles = initialize_particles(dimensions, population_size);
    vector<double> global_best = find_global_best(particles);
    while (true) {
        update_particles(particles, global_best);
        global_best = find_global_best(particles);
    }
    return 0;
}