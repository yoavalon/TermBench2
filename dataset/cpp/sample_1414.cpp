#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

class Swarm {
public:
    Swarm(int size, int dimensions) : size(size), dimensions(dimensions) {
        positions.resize(size, std::vector<double>(dimensions));
        velocities.resize(size, std::vector<double>(dimensions));
        best_positions.resize(size, std::vector<double>(dimensions));
        best_score = std::numeric_limits<double>::infinity();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] = dis(gen);
                velocities[i][j] = dis(gen);
                best_positions[i][j] = positions[i][j];
            }
        }
    }

    void update_personal_best(double score) {
        if (score < best_score) {
            best_score = score;
            best_positions = positions;
        }
    }

    void update_velocity(const std::vector<double>& global_best) {
        const double inertia = 0.5;
        const double cognitive = 1.5;
        const double social = 1.5;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                double r1 = dis(gen);
                double r2 = dis(gen);
                velocities[i][j] = inertia * velocities[i][j] + cognitive * r1 * (best_positions[i][j] - positions[i][j]) + social * r2 * (global_best[j] - positions[i][j]);
            }
        }
    }

    void update_position() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] += velocities[i][j];
            }
        }
    }

private:
    int size;
    int dimensions;
    std::vector<std::vector<double>> positions;
    std::vector<std::vector<double>> velocities;
    std::vector<std::vector<double>> best_positions;
    double best_score;
};

class Environment {
public:
    Environment(Swarm& swarm) : swarm(swarm) {}

    std::vector<double> evaluate() {
        std::vector<double> scores;
        for (const auto& position : swarm.positions) {
            double score = 0.0;
            for (double x : position) {
                score += x * x;
            }
            scores.push_back(score);
        }
        return scores;
    }

    std::vector<double> find_global_best(const std::vector<double>& scores) {
        auto it = std::min_element(scores.begin(), scores.end());
        return swarm.positions[it - scores.begin()];
    }

private:
    Swarm& swarm;
};

void main() {
    Swarm swarm(10, 3);
    Environment environment(swarm);
    int iterations = 50;
    for (int _ = 0; _ < iterations; ++_) {
        std::vector<double> scores = environment.evaluate();
        std::vector<double> global_best = environment.find_global_best(scores);
        swarm.update_personal_best(*std::min_element(scores.begin(), scores.end()));
        swarm.update_velocity(global_best);
        swarm.update_position();
    }
    std::cout << "Best score: " << swarm.best_score << std::endl;
}

int main() {
    main();
    return 0;
}