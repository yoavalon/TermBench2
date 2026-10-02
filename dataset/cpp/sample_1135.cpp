#include <vector>

class Automaton {
public:
    std::vector<std::vector<int>> grid;

    Automaton(int size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        int size = grid.size();
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int ni = x + i;
                int nj = y + j;
                if (0 <= ni && ni < grid.size() && 0 <= nj && nj < grid[i].size()) {
                    count += grid[ni][nj];
                }
            }
        }
        return count;
    }
};

void main() {
    int size = 50;
    Automaton automaton(size);
    automaton.grid[size / 2][size / 2] = 1;
    automaton.update();
    while (true) {
        automaton.update();
    }
}