#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform_coordinates(int x, int y, int z) {
    int a = x + 2 * y - z;
    int b = 3 * x - y + 2 * z;
    int c = -x + y + 3 * z;
    return std::make_tuple(a, b, c);
}

int main() {
    auto result = transform_coordinates(1, 2, 3);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}