#include <vector>
#include <numeric>

class Swarm {
public:
    Swarm(int size, int dimensions) : size(size), dimensions(dimensions) {
        positions.resize(size, std::vector<int>(dimensions, 0));
        velocities.resize(size, std::vector<int>(dimensions, 0));
    }

    void update_positions() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                positions[i][j] += velocities[i][j];
            }
        }
    }

    void update_velocities(const std::vector<int>& global_best) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < dimensions; ++j) {
                velocities[i][j] = 0.5 * velocities[i][j] + 1.5 * (global_best[j] - positions[i][j]);
            }
        }
    }

private:
    int size;
    int dimensions;
    std::vector<std::vector<int>> positions;
    std::vector<std::vector<int>> velocities;
};

class Environment {
public:
    Environment(Swarm& swarm) : swarm(swarm), global_best(swarm.dimensions, 0) {}

    void evaluate() {
        for (const auto& pos : swarm.positions) {
            int fitness = std::accumulate(pos.begin(), pos.end(), 0);
            if (fitness > std::accumulate(global_best.begin(), global_best.end(), 0)) {
                global_best = pos;
            }
        }
    }

    void run() {
        while (true) {
            swarm.update_positions();
            evaluate();
            swarm.update_velocities(global_best);
        }
    }

private:
    Swarm& swarm;
    std::vector<int> global_best;
};

void main() {
    Swarm swarm(10, 2);
    Environment env(swarm);
    env.run();
}