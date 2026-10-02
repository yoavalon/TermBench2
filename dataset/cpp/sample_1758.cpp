#include <iostream>
#include <vector>

class FluidSimulator {
public:
    FluidSimulator(int grid_size) : size(grid_size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int x = 0; x < size; ++x) {
            for (int y = 0; y < size; ++y) {
                std::vector<int> neighbors = get_neighbors(x, y);
                if (grid[x][y] == 1) {
                    if (sum(neighbors) < 2 || sum(neighbors) > 3) {
                        new_grid[x][y] = 0;
                    } else {
                        new_grid[x][y] = 1;
                    }
                } else if (sum(neighbors) == 3) {
                    new_grid[x][y] = 1;
                }
            }
        }
        grid = new_grid;
    }

    std::vector<int> get_neighbors(int x, int y) {
        std::vector<int> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors.push_back(grid[nx][ny]);
                }
            }
        }
        return neighbors;
    }

    void display() {
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell == 1 ? '#' : ' ');
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> grid;
    int size;

    int sum(const std::vector<int>& vec) {
        int total = 0;
        for (int num : vec) {
            total += num;
        }
        return total;
    }
};

int main() {
    FluidSimulator simulator(10);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    simulator.grid[5][5] = 1;
    while (true) {
        simulator.display();
        simulator.update();
    }
    return 0;
}