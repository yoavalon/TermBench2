#include <vector>
#include <iostream>

class FluidCell {
public:
    int state;

    FluidCell(int state = 0) : state(state) {}

    void update(const std::vector<FluidCell*>& neighbors) {
        int sum_state = 0;
        for (const auto* n : neighbors) {
            sum_state += n->state;
        }
        state = sum_state / neighbors.size();
    }
};

class Grid {
public:
    int width;
    int height;
    std::vector<std::vector<FluidCell>> grid;

    Grid(int width, int height, int initial_state = 0) : width(width), height(height) {
        grid.resize(height, std::vector<FluidCell>(width, FluidCell(initial_state)));
    }

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        std::vector<FluidCell*> neighbors;
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                neighbors.push_back(&grid[ny][nx]);
            }
        }
        return neighbors;
    }

    void update_cells() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                grid[y][x].update(neighbors);
            }
        }
    }
};

class Simulation {
public:
    Grid* grid;

    Simulation(Grid* grid) : grid(grid) {}

    void run() {
        while (true) {
            grid->update_cells();
        }
    }
};

int main() {
    Grid grid(10, 10, 50);
    Simulation simulation(&grid);
    simulation.run();
    return 0;
}