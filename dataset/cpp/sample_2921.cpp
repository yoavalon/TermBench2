#include <vector>
#include <iostream>

class Rule {
public:
    Rule(int threshold) : threshold(threshold) {}

    int operator()(int count) {
        return count > threshold ? 1 : 0;
    }

private:
    int threshold;
};

class Automaton {
public:
    Automaton(int grid_size, Rule rule) : grid_size(grid_size), rule(rule) {
        grid.resize(grid_size, std::vector<int>(grid_size, 0));
    }

    void set_initial_state(const std::vector<std::vector<int>>& state) {
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                grid[i][j] = state[i][j];
            }
        }
    }

    void update() {
        std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size, 0));
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                int neighbors = (grid[(i - 1 + grid_size) % grid_size][(j - 1 + grid_size) % grid_size] +
                                 grid[(i - 1 + grid_size) % grid_size][j] +
                                 grid[(i - 1 + grid_size) % grid_size][(j + 1) % grid_size] +
                                 grid[i][(j - 1 + grid_size) % grid_size] +
                                 grid[i][(j + 1) % grid_size] +
                                 grid[(i + 1) % grid_size][(j - 1 + grid_size) % grid_size] +
                                 grid[(i + 1) % grid_size][j] +
                                 grid[(i + 1) % grid_size][(j + 1) % grid_size]);
                new_grid[i][j] = apply_rule(neighbors);
            }
        }
        grid = new_grid;
    }

    int apply_rule(int neighbors) {
        return rule(neighbors);
    }

private:
    int grid_size;
    std::vector<std::vector<int>> grid;
    Rule rule;
};

void main() {
    int grid_size = 10;
    std::vector<std::vector<int>> initial_state = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Rule rule(3);
    Automaton automaton(grid_size, rule);
    automaton.set_initial_state(initial_state);
    while (true) {
        automaton.update();
    }
}