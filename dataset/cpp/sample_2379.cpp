#include <vector>
#include <iostream>

class FluidCell {
public:
    int x, y;
    double pressure;
    std::pair<double, double> velocity;

    FluidCell(int x, int y) : x(x), y(y), pressure(0.0), velocity(0.0, 0.0) {}

    void update_pressure(const std::vector<FluidCell*>& neighbors) {
        double total_pressure = 0.0;
        for (const auto& cell : neighbors) {
            total_pressure += cell->pressure;
        }
        pressure = total_pressure / neighbors.size();
    }

    void update_velocity(const std::vector<FluidCell*>& neighbors) {
        double dx = 0.0, dy = 0.0;
        for (const auto& cell : neighbors) {
            dx += cell->velocity.first;
            dy += cell->velocity.second;
        }
        velocity = {dx / neighbors.size(), dy / neighbors.size()};
    }
};

std::vector<FluidCell*> get_neighbors(std::vector<std::vector<FluidCell>>& grid, int x, int y) {
    std::vector<FluidCell*> neighbors;
    std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (const auto& [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
            neighbors.push_back(&grid[nx][ny]);
        }
    }
    return neighbors;
}

void simulate(std::vector<std::vector<FluidCell>>& grid) {
    while (true) {
        for (auto& row : grid) {
            for (auto& cell : row) {
                auto neighbors = get_neighbors(grid, cell.x, cell.y);
                cell.update_pressure(neighbors);
                cell.update_velocity(neighbors);
            }
        }
    }
}

int main() {
    int width = 10, height = 10;
    std::vector<std::vector<FluidCell>> grid(width, std::vector<FluidCell>(height));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            grid[x][y] = FluidCell(x, y);
        }
    }
    simulate(grid);
    return 0;
}