#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> process_matrix(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    std::vector<std::vector<int>> c(n, std::vector<int>(p, 0));
    std::vector<std::vector<int>> d(n, std::vector<int>(p, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            d[i][j] = c[i][j] + c[j][i];
        }
    }

    return d;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> b = {{2, 0}, {1, 2}};
    std::vector<std::vector<int>> result = process_matrix(a, b);

    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}