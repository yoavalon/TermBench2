#include <iostream>
#include <vector>

class FluidCell {
public:
    int state;

    FluidCell(int state = 0) : state(state) {}

    void update_state(const std::vector<FluidCell*>& neighbors) {
        int count = 0;
        for (const auto& cell : neighbors) {
            if (cell->state == 1) {
                count++;
            }
        }
        if (count == 3) {
            state = 1;
        } else if (count < 2 || count > 3) {
            state = 0;
        }
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<FluidCell>> grid;

    Grid(int size, const std::vector<std::vector<int>>& initial_state) : size(size) {
        grid.resize(size, std::vector<FluidCell>(size));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = FluidCell(initial_state[i][j]);
            }
        }
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<std::vector<int>> directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        std::vector<FluidCell*> neighbors;
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.push_back(&grid[nx][ny]);
            }
        }
        return neighbors;
    }

    void update_grid() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::vector<FluidCell*> neighbors = get_neighbors(i, j);
                grid[i][j].update_state(neighbors);
                new_grid[i][j] = grid[i][j].state;
            }
        }
        grid.resize(size, std::vector<FluidCell>(size));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = FluidCell(new_grid[i][j]);
            }
        }
    }
};

int main() {
    int size = 10;
    std::vector<std::vector<int>> initial_state = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Grid grid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
    return 0;
}