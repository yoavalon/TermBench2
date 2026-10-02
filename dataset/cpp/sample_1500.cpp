#include <iostream>
#include <vector>
#include <map>

class AutomataSimulator {
public:
    AutomataSimulator(int size, const std::map<int, std::map<int, int>>& rule) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
        this->rule = rule;
        this->size = size;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int state = grid[i][j];
                int neighbors = count_neighbors(i, j);
                int new_state = apply_rule(state, neighbors);
                new_grid[i][j] = new_state;
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (0 <= i && i < size && 0 <= j && j < size && !(i == x && j == y)) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }

    int apply_rule(int state, int neighbors) {
        return rule.at(state).at(neighbors);
    }

private:
    std::vector<std::vector<int>> grid;
    std::map<int, std::map<int, int>> rule;
    int size;
};

void main() {
    int size = 10;
    std::map<int, std::map<int, int>> rule = {
        {0, {{0, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}}},
        {1, {{0, 0}, {1, 0}, {2, 0}, {3, 1}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}}}
    };
    AutomataSimulator automata(size, rule);
    for (int _ = 0; _ < 100; ++_) {
        automata.update();
    }
    for (const auto& row : automata.grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}