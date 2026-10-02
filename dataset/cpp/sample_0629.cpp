#include <iostream>

std::tuple<int, int, int, int> plan_flight(int x, int y, int z, int v) {
    if (x == 0 || y == 0 || z == 0 || v == 0) {
        return std::make_tuple(x, y, z, v);
    }
    x -= 1;
    y -= 1;
    z -= 1;
    v -= 1;
    return plan_flight(x, y, z, v);
}

int main() {
    auto result = plan_flight(10, 10, 10, 10);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << " " << std::get<3>(result) << std::endl;
    return 0;
}