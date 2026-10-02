#include <iostream>
#include <tuple>

std::tuple<int, int> simulate(int x, int y, int n) {
    if (n == 0) {
        return std::make_tuple(x, y);
    } else {
        return simulate(x + y, y, n - 1);
    }
}

int main() {
    auto result = simulate(1, 1, 5);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << std::endl;
    return 0;
}