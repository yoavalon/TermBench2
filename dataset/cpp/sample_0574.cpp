cpp
#include <vector>
#include <iostream>

class Cell {
public:
    int state;

    Cell(int state) : state(state) {}

    void update(const std::vector<Cell*>& neighbors) {
        int live_neighbors = 0;
        for (const auto& cell : neighbors) {
            if (cell->state == 1) {
                live_neighbors++;
            }
        }
        if (state == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
            state = 0;
        } else if (state == 0 && live_neighbors == 3) {
            state = 1;
        }
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<Cell>> cells;

    Grid(int size, const std::vector<std::vector<int>>& initial_state) : size(size) {
        cells.resize(size, std::vector<Cell>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cells[i][j] = Cell(initial_state[i][j]);
            }
        }
    }

    std::vector<Cell*> get_neighbors(int x, int y) {
        std::vector<Cell*> neighbors;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i, ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push_back(&cells[nx][ny]);
                } else {
                    neighbors.push_back(new Cell(0));
                }
            }
        }
        return neighbors;
    }

    void update() {
        std::vector<std::vector<Cell>> new_cells(size, std::vector<Cell>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<Cell*> neighbors = get_neighbors(i, j);
                new_cells[i][j].update(neighbors);
                for (const auto& neighbor : neighbors) {
                    delete neighbor;
                }
            }
        }
        cells = new_cells;
    }
};

void main() {
    int size = 10;
    std::vector<std::vector<int>> initial_state(size, std::vector<int>(size, 0));
    initial_state[4][4] = 1;
    initial_state[4][5] = 1;
    initial_state[5][4] = 1;
    initial_state[5][5] = 1;
    Grid grid(size, initial_state);
    while (true) {
        grid.update();
    }
}