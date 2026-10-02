#include <vector>
#include <iostream>

class Grid {
public:
    int size;
    std::vector<std::vector<int>> grid;
    std::string boundary;

    Grid(int size, std::string boundary) : size(size), boundary(boundary) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<int> neighbors = boundary_condition(i, j);
                new_grid[i][j] = apply_rules(neighbors, grid[i][j]);
            }
        }
        grid = new_grid;
    }

    std::vector<int> boundary_condition(int x, int y) {
        std::vector<int> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx, ny = y + dy;
                if (boundary == "fixed") {
                    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                        neighbors.push_back(grid[nx][ny]);
                    }
                } else if (boundary == "periodic") {
                    neighbors.push_back(grid[(nx + size) % size][(ny + size) % size]);
                }
            }
        }
        return neighbors;
    }

    int apply_rules(std::vector<int> neighbors, int current) {
        int count = 0;
        for (int neighbor : neighbors) {
            count += neighbor;
        }
        if (current == 1) {
            if (count < 2 || count > 3) {
                return 0;
            }
            return 1;
        } else {
            if (count == 3) {
                return 1;
            }
            return 0;
        }
    }
};

void main() {
    int size = 10;
    std::string boundary = "periodic";
    Grid grid(size, boundary);
    int steps = 50;
    for (int _ = 0; _ < steps; ++_) {
        grid.update();
    }
}