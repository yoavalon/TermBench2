#include <iostream>
#include <vector>

class FluidCell {
public:
    double state;

    FluidCell(double state) : state(state) {}

    void update(const std::vector<FluidCell*>& neighbors) {
        double avg_state = 0.0;
        for (const auto& n : neighbors) {
            avg_state += n->state;
        }
        avg_state /= neighbors.size();
        state = avg_state;
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<FluidCell>> cells;

    Grid(int size, double initial_state) : size(size) {
        cells = std::vector<std::vector<FluidCell>>(size, std::vector<FluidCell>(size, FluidCell(initial_state)));
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<FluidCell*> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push_back(&cells[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void update() {
        std::vector<std::vector<FluidCell>> new_cells(size, std::vector<FluidCell>(size, FluidCell(0.0)));
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                new_cells[x][y].update(neighbors);
            }
        }
        cells = new_cells;
    }
};

int main() {
    int grid_size = 10;
    double initial_state = 0.5;
    Grid grid(grid_size, initial_state);
    while (true) {
        grid.update();
    }
    return 0;
}