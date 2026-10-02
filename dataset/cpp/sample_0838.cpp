#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class Swarm {
public:
    Swarm(int size, int dimensions, const std::vector<std::pair<double, double>>& bounds)
        : size(size), dimensions(dimensions), bounds(bounds) {
        positions.resize(size, std::vector<double>(dimensions, 0.0));
        velocities.resize(size, std::vector<double>(dimensions, 0.0));
        pbest_positions.resize(size, std::vector<double>(dimensions, 0.0));
        pbest_scores.resize(size, std::numeric_limits<double>::infinity());
        gbest_position.resize(dimensions, 0.0);
        gbest_score = std::numeric_limits<double>::infinity();
    }

    void initialize() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] = (bounds[j].second - bounds[j].first) * static_cast<double>(rand()) / RAND_MAX + bounds[j].first;
                velocities[i][j] = (bounds[j].second - bounds[j].first) * static_cast<double>(rand()) / RAND_MAX - (bounds[j].second - bounds[j].first) / 2;
            }
        }
    }

    void evaluate(double (*function)(const std::vector<double>&)) {
        for (int i = 0; i < size; ++i) {
            double score = function(positions[i]);
            if (score < pbest_scores[i]) {
                pbest_scores[i] = score;
                pbest_positions[i] = positions[i];
            }
            if (score < gbest_score) {
                gbest_score = score;
                gbest_position = positions[i];
            }
        }
    }

    void update_velocities(double w, double c1, double c2) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                velocities[i][j] = w * velocities[i][j] + c1 * static_cast<double>(rand()) / RAND_MAX * (pbest_positions[i][j] - positions[i][j]) + c2 * static_cast<double>(rand()) / RAND_MAX * (gbest_position[j] - positions[i][j]);
            }
        }
    }

    void update_positions() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] += velocities[i][j];
                positions[i][j] = std::max(bounds[j].first, std::min(bounds[j].second, positions[i][j]));
            }
        }
    }

    double optimize(double (*function)(const std::vector<double>&), int iterations) {
        initialize();
        for (int _ = 0; _ < iterations; ++_) {
            evaluate(function);
            update_velocities(0.7, 1.5, 1.5);
            update_positions();
        }
        return gbest_score;
    }

private:
    int size;
    int dimensions;
    std::vector<std::pair<double, double>> bounds;
    std::vector<std::vector<double>> positions;
    std::vector<std::vector<double>> velocities;
    std::vector<std::vector<double>> pbest_positions;
    std::vector<double> pbest_scores;
    std::vector<double> gbest_position;
    double gbest_score;
};

double objective(const std::vector<double>& x) {
    double sum = 0.0;
    for (double xi : x) {
        sum += (xi - 0.5) * (xi - 0.5);
    }
    return sum;
}

int main() {
    int dimensions = 3;
    std::vector<std::pair<double, double>> bounds(dimensions, std::make_pair(-10.0, 10.0));
    int swarm_size = 30;
    int iterations = 100;
    Swarm swarm(swarm_size, dimensions, bounds);
    double best_score = swarm.optimize(objective, iterations);
    std::cout << best_score << std::endl;
    return 0;
}