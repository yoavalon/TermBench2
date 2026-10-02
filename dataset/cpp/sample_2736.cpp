#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> update(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> new_grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = grid[i][j];
            sum += grid[(i + 1) % n][j];
            sum += grid[(i - 1 + n) % n][j];
            sum += grid[i][(j + 1) % n];
            sum += grid[i][(j - 1 + n) % n];
            new_grid[i][j] = sum % 2;
        }
    }
    return new_grid;
}

int main() {
    int n = 100;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    grid[50][50] = 1;
    while (true) {
        grid = update(grid);
    }
    return 0;
}