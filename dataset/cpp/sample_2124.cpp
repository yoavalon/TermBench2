#include <vector>
#include <iostream>

void cellular_automata(int n) {
    std::vector<std::vector<double>> a(n, std::vector<double>(n, 0));
    while (true) {
        std::vector<std::vector<double>> b(n, std::vector<double>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                b[i][j] = (a[i][j] + a[(i - 1 + n) % n][j] + a[i][(j - 1 + n) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5;
            }
        }
        a = b;
    }
}

int main() {
    cellular_automata(10);
    return 0;
}