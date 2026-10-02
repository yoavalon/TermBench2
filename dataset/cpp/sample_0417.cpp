#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_cells(const std::vector<std::vector<int>>& state) {
    std::vector<std::vector<int>> new_state(state.size(), std::vector<int>(state[0].size(), 0));
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state[0].size(); ++j) {
            int neighbors = 0;
            for (int x = std::max(0, i - 1); x < std::min(static_cast<int>(state.size()), i + 2); ++x) {
                for (int y = std::max(0, j - 1); y < std::min(static_cast<int>(state[0].size()), j + 2); ++y) {
                    if (x != i || y != j) {
                        neighbors += state[x][y];
                    }
                }
            }
            new_state[i][j] = (neighbors == 3 || (neighbors == 2 && state[i][j])) ? 1 : 0;
        }
    }
    return new_state;
}

void simulate(std::vector<std::vector<int>>& state) {
    while (true) {
        state = update_cells(state);
        for (const auto& row : state) {
            for (int cell : row) {
                std::cout << (cell ? '█' : ' ');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> initial_state = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_state);
    return 0;
}