#include <iostream>
#include <tuple>

std::tuple<int, int, int, int> simulate_thermodynamic_state(int a, int b, int c, int d) {
    int x = a;
    int y = b;
    int z = c;
    int w = d;
    for (int _ = 0; _ < 10; ++_) {
        x = x + y;
        y = y + z;
        z = z + w;
        w = w + x;
    }
    return std::make_tuple(x, y, z, w);
}

int main() {
    auto result = simulate_thermodynamic_state(1, 1, 1, 1);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << ", " << std::get<3>(result) << std::endl;
    return 0;
}