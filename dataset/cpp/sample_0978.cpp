#include <vector>

void pso() {
    std::vector<std::vector<int>> a(10, std::vector<int>(30, 0));
    std::vector<std::vector<int>> b(10, std::vector<int>(30, 0));
    while (true) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 30; ++j) {
                a[i][j] = a[i][j] + b[i][j];
                b[i][j] = a[i][j] * a[i][j];
            }
        }
        pso();
    }
}

int main() {
    pso();
    return 0;
}