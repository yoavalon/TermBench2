#include <vector>

class FluidCell {
public:
    FluidCell(double state) : state(state) {}

    void update_state(const std::vector<FluidCell*>& neighbors) {
        double sum = 0;
        for (const auto& n : neighbors) {
            sum += n->state;
        }
        state = sum / neighbors.size();
    }

    double state;
};

class FluidGrid {
public:
    FluidGrid(int size, double initial_state) : size(size) {
        grid.resize(size, std::vector<FluidCell>(size, FluidCell(initial_state)));
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<FluidCell*> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size && (dx != 0 || dy != 0)) {
                    neighbors.push_back(&grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void update_grid() {
        std::vector<std::vector<FluidCell>> new_grid(size, std::vector<FluidCell>(size, FluidCell(0)));
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                new_grid[x][y].update_state(neighbors);
            }
        }
        grid = new_grid;
    }

private:
    int size;
    std::vector<std::vector<FluidCell>> grid;
};

int main() {
    int size = 10;
    double initial_state = 1.0;
    FluidGrid grid(size, initial_state);
    while (true) {
        grid.update_grid();
    }
    return 0;
}