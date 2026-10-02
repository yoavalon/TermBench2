#include <iostream>
#include <vector>

class Cell {
public:
    int state;

    Cell(int state = 0) : state(state) {}

    void update(const std::vector<Cell*>& neighbors) {
        int live_neighbors = 0;
        for (const auto& cell : neighbors) {
            if (cell->state == 1) {
                live_neighbors++;
            }
        }
        if (state == 1) {
            state = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
        } else {
            state = (live_neighbors == 3) ? 1 : 0;
        }
    }
};

class Grid {
public:
    int width, height;
    std::vector<std::vector<Cell>> grid;

    Grid(int width, int height, const std::vector<std::vector<int>>& initial_state = {}) : width(width), height(height) {
        grid.resize(height, std::vector<Cell>(width));
        if (!initial_state.empty()) {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    grid[i][j] = Cell(initial_state[i][j]);
                }
            }
        }
    }

    std::vector<Cell*> get_neighbors(int x, int y) {
        std::vector<std::vector<int>> directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        std::vector<Cell*> neighbors;
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                neighbors.push_back(&grid[ny][nx]);
            }
        }
        return neighbors;
    }

    void update() {
        std::vector<std::vector<Cell>> new_grid(height, std::vector<Cell>(width));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                new_grid[i][j] = Cell(grid[i][j].state);
            }
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::vector<Cell*> neighbors = get_neighbors(j, i);
                new_grid[i][j].update(neighbors);
            }
        }
        grid = new_grid;
    }
};

void main() {
    std::vector<std::vector<int>> initial_state = { {0, 1, 0}, {0, 1, 0}, {0, 1, 0} };
    Grid grid(3, 3, initial_state);
    while (true) {
        grid.update();
    }
}