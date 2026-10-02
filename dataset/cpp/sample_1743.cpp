#include <vector>
#include <iostream>

class FluidCell {
public:
    int state;

    FluidCell(int state) : state(state) {}

    void update_state(const std::vector<FluidCell*>& neighbors) {
        int sum = 0;
        for (const auto& n : neighbors) {
            sum += n->state;
        }
        state = sum / 3;
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<FluidCell>> cells;

    Grid(int size) : size(size), cells(size, std::vector<FluidCell>(size, FluidCell(0))) {}

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<FluidCell*> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                    neighbors.push_back(&cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void update_grid() {
        std::vector<std::vector<FluidCell>> new_cells(size, std::vector<FluidCell>(size, FluidCell(0)));
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                new_cells[x][y].update_state(neighbors);
            }
        }
        cells = new_cells;
    }
};

int main() {
    int grid_size = 10;
    Grid grid(grid_size);
    while (true) {
        grid.update_grid();
    }
    return 0;
}