#include <vector>
#include <cmath>
#include <limits>

class Swarm {
public:
    Swarm(int size, int dimensions) : size(size), dimensions(dimensions) {
        positions.resize(size, std::vector<double>(dimensions, 0.0));
        velocities.resize(size, std::vector<double>(dimensions, 0.0));
        best_positions.resize(size, std::vector<double>(dimensions, 0.0));
        best_scores.resize(size, std::numeric_limits<double>::infinity());
        global_best_position.resize(dimensions, 0.0);
        global_best_score = std::numeric_limits<double>::infinity();
    }

    void update_global_best() {
        for (int i = 0; i < size; ++i) {
            double score = evaluate(best_positions[i]);
            if (score < global_best_score) {
                global_best_score = score;
                global_best_position = best_positions[i];
            }
        }
    }

    double evaluate(const std::vector<double>& position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void update_particles() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                double r1 = 0.5, r2 = 0.5;
                double c1 = 2.0, c2 = 2.0;
                velocities[i][j] = 0.7 * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j]);
                positions[i][j] += velocities[i][j];
            }
            best_scores[i] = evaluate(positions[i]);
            if (best_scores[i] < global_best_score) {
                best_positions[i] = positions[i];
            }
        }
    }

    void iterate() {
        update_global_best();
        update_particles();
        iterate();
    }

private:
    int size, dimensions;
    std::vector<std::vector<double>> positions;
    std::vector<std::vector<double>> velocities;
    std::vector<std::vector<double>> best_positions;
    std::vector<double> best_scores;
    std::vector<double> global_best_position;
    double global_best_score;
};

int main() {
    Swarm swarm(30, 2);
    swarm.iterate();
    return 0;
}