#include <vector>

class FluidCell {
public:
    int state;

    FluidCell(int state) : state(state) {}

    void update_state(const std::vector<FluidCell*>& neighbors) {
        int active_neighbors = 0;
        for (const auto& cell : neighbors) {
            if (cell->state == 1) {
                active_neighbors++;
            }
        }
        if (active_neighbors == 2 || active_neighbors == 3) {
            state = 1;
        } else {
            state = 0;
        }
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<FluidCell>> grid;

    Grid(int size) : size(size) {
        grid.resize(size, std::vector<FluidCell>(size, FluidCell(0)));
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<std::vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        std::vector<FluidCell*> neighbors;
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                neighbors.push_back(&grid[nx][ny]);
            }
        }
        return neighbors;
    }

    void update_grid() {
        std::vector<std::vector<FluidCell>> new_grid(size, std::vector<FluidCell>(size, FluidCell(0)));
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        grid = new_grid;
    }
};

void main() {
    int grid_size = 50;
    Grid simulation(grid_size);
    while (true) {
        simulation.update_grid();
    }
}