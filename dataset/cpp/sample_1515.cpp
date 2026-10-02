#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> simulate() {
    std::srand(std::time(0));
    std::vector<std::vector<int>> state(50, std::vector<int>(50));
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            state[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        std::vector<std::vector<int>> new_state(50, std::vector<int>(50, 0));
        for (int i = 1; i < 49; ++i) {
            for (int j = 1; j < 49; ++j) {
                int neighbors = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        neighbors += state[i + di][j + dj];
                    }
                }
                neighbors -= state[i][j];
                if (state[i][j] && (neighbors == 2 || neighbors == 3)) {
                    new_state[i][j] = 1;
                } else if (!state[i][j] && neighbors == 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        state = new_state;
    }
    return state;
}

int main() {
    simulate();
    return 0;
}