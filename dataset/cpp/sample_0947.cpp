#include <iostream>
#include <vector>
#include <tuple>

void f(int a, int b, int c) {
    std::vector<std::tuple<int, int, int>> d = {{a, b, c}};
    while (true) {
        std::vector<std::tuple<int, int, int>> e;
        for (const auto& [x, y, z] : d) {
            e.emplace_back(x + y, y + z, z + x);
        }
        d = e;
    }
}

int main() {
    f(1, 1, 1);
    return 0;
}