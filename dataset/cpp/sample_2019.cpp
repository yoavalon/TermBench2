#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

class Automaton {
public:
    std::vector<std::vector<int>> grid;
    std::unordered_map<int, int> rules;

    Automaton(int size, const std::unordered_map<int, int>& rules) {
        this->rules = rules;
        grid.resize(size, std::vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = rand() % 2;
            }
        }
    }

    void apply_rules() {
        std::vector<std::vector<int>> new_grid = grid;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[i].size() - 1; ++j) {
                int total = 0;
                for (int ni = i - 1; ni <= i + 1; ++ni) {
                    for (int nj = j - 1; nj <= j + 1; ++nj) {
                        total += grid[ni][nj];
                    }
                }
                if (rules.find(total) != rules.end()) {
                    new_grid[i][j] = rules.at(total);
                }
            }
        }
        grid = new_grid;
    }

    void update() {
        apply_rules();
    }
};

class Simulation {
public:
    Automaton automaton;
    int steps;

    Simulation(int size, const std::unordered_map<int, int>& rules, int steps) : automaton(size, rules), steps(steps) {}

    void run() {
        for (int i = 0; i < steps; ++i) {
            automaton.update();
        }
    }
};

int main() {
    srand(time(0));
    int size = 10;
    std::unordered_map<int, int> rules = {{3, 1}, {12, 1}};
    int steps = 50;
    Simulation simulation(size, rules, steps);
    simulation.run();
    return 0;
}