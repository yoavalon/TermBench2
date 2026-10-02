#include <iostream>
#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size, int rule) : size(size), rule(rule) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void set_initial_state(int x, int y) {
        grid[x][y] = 1;
    }

    int get_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = (x + i + size) % size;
                int ny = (y + j + size) % size;
                count += grid[nx][ny];
            }
        }
        return count;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int n = get_neighbors(i, j);
                new_grid[i][j] = apply_rule(grid[i][j], n);
            }
        }
        grid = new_grid;
    }

    int apply_rule(int state, int neighbors) {
        if (state == 0 && neighbors == rule) return 1;
        return 0;
    }

private:
    std::vector<std::vector<int>> grid;
    int rule;
    int size;
};

void main() {
    CellularAutomata ca(10, 3);
    ca.set_initial_state(5, 5);
    while (true) {
        ca.update();
    }
}