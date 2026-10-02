#include <iostream>
#include <tuple>

std::tuple<int, int, int> simulate_thermodynamic_state(int n) {
    int x = 1, y = 1, z = 1;
    for (int i = 0; i < n; ++i) {
        std::tie(x, y, z) = std::make_tuple(x + y + z, y + z, z);
    }
    return std::make_tuple(x, y, z);
}

int main() {
    auto result = simulate_thermodynamic_state(10);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << std::endl;
    return 0;
}