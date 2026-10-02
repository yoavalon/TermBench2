#include <vector>

class CellularAutomaton {
public:
    CellularAutomaton(int grid_size, int rule) : grid(grid_size, std::vector<int>(grid_size, 0)), rule(rule) {}

    void update_grid() {
        std::vector<std::vector<int>> new_grid = grid;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
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
        for (int i = std::max(0, x - 1); i < std::min((int)grid.size(), x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min((int)grid[i].size(), y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

    int apply_rule(int state, int neighbors) {
        if (rule == 1) {
            if (state == 0 && neighbors == 3) {
                return 1;
            } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                return 0;
            } else {
                return state;
            }
        }
        return state;
    }

private:
    std::vector<std::vector<int>> grid;
    int rule;
};

void main() {
    CellularAutomaton automaton(100, 1);
    while (true) {
        automaton.update_grid();
    }
}