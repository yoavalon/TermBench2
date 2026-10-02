#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void simulate() {
    const int size = 20;
    std::vector<std::vector<int>> state(size, std::vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            state[i][j] = std::rand() % 2;
        }
    }

    auto update = [&state, size]() {
        std::vector<std::vector<int>> new_state(size, std::vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = 0;
                if (i > 0) neighbors += state[i - 1][j];
                if (i < size - 1) neighbors += state[i + 1][j];
                if (j > 0) neighbors += state[i][j - 1];
                if (j < size - 1) neighbors += state[i][j + 1];

                if (state[i][j] == 1 && neighbors < 2) {
                    new_state[i][j] = 0;
                } else if (state[i][j] == 1 && neighbors > 3) {
                    new_state[i][j] = 0;
                } else if (state[i][j] == 0 && neighbors == 3) {
                    new_state[i][j] = 1;
                } else {
                    new_state[i][j] = state[i][j];
                }
            }
        }
        return new_state;
    };

    while (true) {
        state = update();
    }
}

int main() {
    std::srand(std::time(0));
    simulate();
    return 0;
}