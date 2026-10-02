cpp
#include <iostream>
#include <vector>

class FluidCell {
public:
    double value;

    FluidCell(double value) : value(value) {}

    void update(const std::vector<FluidCell*>& neighbors) {
        double sum = 0.0;
        for (const auto& n : neighbors) {
            sum += n->value;
        }
        value = sum / neighbors.size();
    }
};

class FluidGrid {
public:
    std::vector<std::vector<FluidCell>> grid;

    FluidGrid(int size) : grid(size, std::vector<FluidCell>(size, FluidCell(0.0))) {}

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        std::vector<FluidCell*> neighbors;
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size()) {
                neighbors.push_back(&grid[nx][ny]);
            }
        }
        return neighbors;
    }

    void update_cells() {
        std::vector<std::vector<FluidCell>> new_grid(grid.size(), std::vector<FluidCell>(grid.size(), FluidCell(0.0)));
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid.size(); ++y) {
                auto neighbors = get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        grid = new_grid;
    }
};

void main() {
    int size = 100;
    FluidGrid fluid_grid(size);
    for (auto& cell : fluid_grid.grid[0]) {
        cell.value = 1.0;
    }
    while (true) {
        fluid_grid.update_cells();
    }
}