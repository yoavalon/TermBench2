#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& a, const std::vector<int>& x) {
    std::vector<int> result(2, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i] += a[i][j] * x[j];
        }
    }
    return {result};
}

std::vector<int> add(const std::vector<int>& a, const std::vector<int>& b) {
    return {a[0] + b[0], a[1] + b[1]};
}

std::vector<int> compute_sequence(int n) {
    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> b = {{2, 0}, {1, 2}};
    std::vector<int> x = {1, 1};
    for (int _ = 0; _ < n; ++_) {
        x = add(multiply(a, x)[0], multiply(b, x)[0]);
    }
    return x;
}

int main() {
    std::vector<int> result = compute_sequence(5);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}