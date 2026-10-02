#include <iostream>
#include <vector>

class Automaton {
public:
    Automaton(int size) : size(size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 0) {
                    if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
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
                int ni = x + i;
                int nj = y + j;
                if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                    count += grid[ni][nj];
                }
            }
        }
        return count;
    
    std::vector<std::vector<int>> grid;
    int size;
};

void display(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell ? '#' : ' ');
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 10;
    Automaton automaton(size);
    automaton.grid[5][5] = 1;
    automaton.grid[5][6] = 1;
    automaton.grid[6][5] = 1;
    automaton.grid[6][6] = 1;
    while (true) {
        display(automaton.grid);
        automaton.update();
    }
    return 0;
}