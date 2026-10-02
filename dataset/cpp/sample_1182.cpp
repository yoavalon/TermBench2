#include <iostream>
#include <vector>

class Automata {
public:
    Automata(int size) {
        this->size = size;
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
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
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    count += grid[nx][ny];
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
    int size;
};

void main() {
    int size = 50;
    Automata automata(size);
    automata.grid[25][25] = 1;
    automata.grid[26][25] = 1;
    automata.grid[27][25] = 1;
    while (true) {
        automata.update();
    }
}