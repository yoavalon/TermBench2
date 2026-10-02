#include <iostream>
#include <vector>

class Cell {
public:
    int state;

    Cell(int state) : state(state) {}

    void update(const std::vector<Cell>& neighbors) {
        int alive_neighbors = 0;
        for (const auto& n : neighbors) {
            if (n.state == 1) {
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

class Grid {
public:
    int width;
    int height;
    std::vector<std::vector<Cell>> grid;

    Grid(int width, int height, const std::vector<std::vector<int>>& initial_state) : width(width), height(height) {
        grid.resize(width, std::vector<Cell>(height));
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                grid[x][y] = Cell(initial_state[x][y]);
            }
        }
    }

    std::vector<Cell> get_neighbors(int x, int y) {
        std::vector<Cell> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    neighbors.push_back(grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void update() {
        std::vector<std::vector<Cell>> new_grid(width, std::vector<Cell>(height, Cell(0)));
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                Cell& cell = grid[x][y];
                std::vector<Cell> neighbors = get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        grid = new_grid;
    }
};

void main() {
    int width = 10;
    int height = 10;
    std::vector<std::vector<int>> initial_state = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Grid grid(width, height, initial_state);
    while (true) {
        grid.update();
    }
}