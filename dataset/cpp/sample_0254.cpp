#include <iostream>
#include <vector>

class FluidCell {
public:
    int state;

    FluidCell(int state) : state(state) {}

    void update(const std::vector<FluidCell*>& neighbors) {
        int sum = 0;
        for (const auto& n : neighbors) {
            sum += n->state;
        }
        state = sum / neighbors.size();
    }
};

class Grid {
public:
    int size;
    std::vector<std::vector<FluidCell>> cells;

    Grid(int size) : size(size), cells(size, std::vector<FluidCell>(size, FluidCell(0))) {}

    std::vector<FluidCell*> get_neighbors(int x, int y) {
        std::vector<FluidCell*> neighbors;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.push_back(&cells[nx][ny]);
            }
        }
        return neighbors;
    }

    void update() {
        std::vector<std::vector<FluidCell>> new_grid(size, std::vector<FluidCell>(size, FluidCell(0)));
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<FluidCell*> neighbors = get_neighbors(x, y);
                new_grid[x][y].update(neighbors);
            }
        }
        cells = new_grid;
    }
};

class Simulation {
public:
    Grid grid;
    int steps;

    Simulation(int grid_size, int steps) : grid(grid_size), steps(steps) {}

    void run() {
        for (int i = 0; i < steps; ++i) {
            grid.update();
        }
    }
};

int main() {
    Simulation simulation(10, 50);
    simulation.run();
    return 0;
}