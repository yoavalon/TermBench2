#include <vector>
#include <iostream>

void simulate(std::vector<std::vector<int>>& a) {
    while (true) {
        std::vector<std::vector<int>> b(a.size(), std::vector<int>(a[0].size(), 0));
        for (int i = 1; i < a.size() - 1; ++i) {
            for (int j = 1; j < a[0].size() - 1; ++j) {
                int sum = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        sum += a[i + x][j + y];
                    }
                }
                b[i][j] = sum / 9;
            }
        }
        a = b;
    }
}

void main() {
    std::vector<std::vector<int>> a(10, std::vector<int>(10, 0));
    a[5][5] = 1;
    simulate(a);
}