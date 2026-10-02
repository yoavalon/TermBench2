#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class AutomatonCell {
public:
    int state;

    AutomatonCell(int state) : state(state) {}

    void update_state(const std::vector<AutomatonCell*>& neighbors) {
        int alive_neighbors = 0;
        for (const auto& cell : neighbors) {
            if (cell->state == 1) {
                alive_neighbors++;
            }
        }
        if (state == 1) {
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                state = 0;
            }
        } else if (alive_neighbors == 3) {
            state = 1;
        }
    }
};

class AutomatonGrid {
public:
    std::vector<std::vector<AutomatonCell*>> grid;

    AutomatonGrid(int size) {
        grid.resize(size, std::vector<AutomatonCell*>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = new AutomatonCell(rand() % 2);
            }
        }
    }

    ~AutomatonGrid() {
        for (auto& row : grid) {
            for (auto& cell : row) {
                delete cell;
            }
        }
    }

    std::vector<AutomatonCell*> get_neighbors(int x, int y) {
        int size = grid.size();
        std::vector<AutomatonCell*> neighbors;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push_back(grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void update_grid() {
        int size = grid.size();
        std::vector<std::vector<AutomatonCell*>> new_grid(size, std::vector<AutomatonCell*>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                new_grid[i][j] = new AutomatonCell(0);
            }
        }
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<AutomatonCell*> neighbors = get_neighbors(x, y);
                new_grid[x][y]->update_state(neighbors);
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                delete grid[i][j];
            }
        }
        grid = new_grid;
    }
};

void simulate() {
    int size = 50;
    AutomatonGrid grid(size);
    while (true) {
        grid.update_grid();
    }
}

int main() {
    srand(time(0));
    simulate();
    return 0;
}