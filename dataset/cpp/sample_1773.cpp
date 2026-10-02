#include <iostream>
#include <vector>

class FluidCell {
public:
    int state;

    FluidCell(int state) : state(state) {}

    void update_state(const std::vector<FluidCell*>& neighbors) {
        int active_neighbors = 0;
        for (const auto& neighbor : neighbors) {
            if (neighbor->state > 0) {
                active_neighbors++;
            }
        }
        if (active_neighbors > 4) {
            state = 2;
        } else if (active_neighbors < 2) {
            state = 0;
        } else {
            state = 1;
        }
    }
};

class FluidGrid {
public:
    std::vector<std::vector<FluidCell>> grid;
    int size;

    FluidGrid(int size) : size(size) {
        grid.resize(size, std::vector<FluidCell>(size, FluidCell(0)));
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<FluidCell*> neighbors;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i >= 0 && i < size && j >= 0 && j < size && (i != x || j != y)) {
                    neighbors.push_back(&grid[i][j]);
                }
            }
        }
        return neighbors;
    }

    void update_grid() {
        std::vector<std::vector<FluidCell>> new_grid(size, std::vector<FluidCell>(size, FluidCell(0)));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<FluidCell*> neighbors = get_neighbors(i, j);
                new_grid[i][j].update_state(neighbors);
            }
        }
        grid = new_grid;
    }
};

void main() {
    int size = 10;
    FluidGrid grid(size);
    while (true) {
        grid.update_grid();
    }
}