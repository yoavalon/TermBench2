#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int cellular_automata(vector<vector<int>>& grid, function<int(vector<int>)> rule) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> new_grid(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vector<int> neighbors;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x != 0 || y != 0) {
                        neighbors.push_back(grid[(i + x + rows) % rows][(j + y + cols) % cols]);
                    }
                }
            }
            sort(neighbors.begin(), neighbors.end());
            new_grid[i][j] = rule(neighbors);
        }
    }
    return cellular_automata(new_grid, rule);
}

void main() {
    int size = 10;
    vector<vector<int>> initial_grid(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        initial_grid[i][i] = 1;
    }
    auto rule = [](vector<int> n) { return count(n.begin(), n.end(), 1) == 3 ? 1 : 0; };
    cellular_automata(initial_grid, rule);
}