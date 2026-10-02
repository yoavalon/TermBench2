#include <vector>
#include <iostream>

class FluidSimulator {
public:
    FluidSimulator(int size, const std::vector<std::vector<int>>& initial_state) 
        : size(size), state(initial_state) {}

    void update_state() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<int> neighbors = get_neighbors(i, j);
                new_state[i][j] = apply_rules(neighbors);
            }
        }
        state = new_state;
    }

private:
    std::vector<std::vector<int>> get_neighbors(int x, int y) {
        std::vector<std::pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        std::vector<int> neighbors;
        for (const auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.push_back(state[nx][ny]);
            }
        }
        return neighbors;
    }

    int apply_rules(const std::vector<int>& neighbors) {
        int active_neighbors = 0;
        for (int neighbor : neighbors) {
            active_neighbors += neighbor;
        }
        if (state[0][0] == 1) {
            return active_neighbors >= 2 ? 1 : 0;
        } else {
            return active_neighbors == 3 ? 1 : 0;
        }
    }

    int size;
    std::vector<std::vector<int>> state;
};

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = (i % 2 && j % 2) ? 0 : 1;
        }
    }
    return grid;
}

int main() {
    int grid_size = 10;
    std::vector<std::vector<int>> initial_state = initialize_grid(grid_size);
    FluidSimulator simulator(grid_size, initial_state);
    while (true) {
        simulator.update_state();
    }
    return 0;
}