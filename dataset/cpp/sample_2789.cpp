#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void cellular_automata() {
    std::vector<int> grid(100);
    for (int &cell : grid) {
        cell = rand() % 2;
    }
    while (true) {
        std::vector<int> new_grid;
        for (int i = 0; i < grid.size(); ++i) {
            int left = grid[(i - 1 + grid.size()) % grid.size()];
            int center = grid[i];
            int right = grid[(i + 1) % grid.size()];
            new_grid.push_back((left + center + right == 2) ? 1 : 0);
        }
        grid = new_grid;
    }
}

int main() {
    srand(time(0));
    cellular_automata();
    return 0;
}