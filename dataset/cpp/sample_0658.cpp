cpp
#include <iostream>
#include <tuple>

std::tuple<int, int, int> simulate_state(int x, int y, int z, int n) {
    if (n == 0) {
        return std::make_tuple(x, y, z);
    } else {
        return simulate_state(y, z, x + y + z, n - 1);
    }
}

int main() {
    int x = 1, y = 1, z = 1, n = 5;
    auto result = simulate_state(x, y, z, n);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << std::endl;
    return 0;
}