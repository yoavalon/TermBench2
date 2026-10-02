#include <vector>
#include <cmath>
#include <limits>

class Swarm {
public:
    Swarm(int size, int dimensions) {
        this->size = size;
        this->dimensions = dimensions;
        particles.resize(size, std::vector<double>(dimensions, 0.0));
        velocities.resize(size, std::vector<double>(dimensions, 0.0));
        best_positions.resize(size, std::vector<double>(dimensions, 0.0));
        best_scores.resize(size, std::numeric_limits<double>::infinity());
        global_best.resize(dimensions, 0.0);
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (int i = 0; i < size; ++i) {
            if (best_scores[i] < global_best_score) {
                global_best_score = best_scores[i];
                global_best = best_positions[i];
            }
        }
    }

    void update_particles() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                double r1 = 0.5, r2 = 0.5;
                double cognitive = r1 * (best_positions[i][j] - particles[i][j]);
                double social = r2 * (global_best[j] - particles[i][j]);
                velocities[i][j] += cognitive + social;
                particles[i][j] += velocities[i][j];
            }
        }
    }

    void evaluate(double (*objective_function)(const std::vector<double>&)) {
        for (int i = 0; i < size; ++i) {
            double score = objective_function(particles[i]);
            if (score < best_scores[i]) {
                best_scores[i] = score;
                best_positions[i] = particles[i];
            }
        }
        update_global_best();
    }

private:
    int size;
    int dimensions;
    std::vector<std::vector<double>> particles;
    std::vector<std::vector<double>> velocities;
    std::vector<std::vector<double>> best_positions;
    std::vector<double> best_scores;
    std::vector<double> global_best;
    double global_best_score;
};

class Optimization {
public:
    Optimization(Swarm& swarm, double (*objective_function)(const std::vector<double>&)) {
        this->swarm = &swarm;
        this->objective_function = objective_function;
    }

    void run() {
        while (true) {
            swarm->update_particles();
            swarm->evaluate(objective_function);
        }
    }

private:
    Swarm* swarm;
    double (*objective_function)(const std::vector<double>&);
};

double objective_function(const std::vector<double>& position) {
    double result = 0.0;
    for (double x : position) {
        result += x * x;
    }
    return result;
}

void main() {
    int size = 30;
    int dimensions = 2;
    Swarm swarm(size, dimensions);
    Optimization optimization(swarm, objective_function);
    optimization.run();
}