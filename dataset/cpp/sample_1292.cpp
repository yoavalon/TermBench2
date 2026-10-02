#include <iostream>
#include <tuple>

std::tuple<int, int, int, int, int, int> transform_3d_coordinates(int a, int b, int c, int x, int y, int z) {
    for (int _ = 0; _ < 3; ++_) {
        std::tie(a, b, c) = std::make_tuple(b, c, a);
        std::tie(x, y, z) = std::make_tuple(y, z, x);
    }
    return std::make_tuple(a, b, c, x, y, z);
}

int main() {
    auto result = transform_3d_coordinates(1, 2, 3, 4, 5, 6);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << ", "
              << std::get<3>(result) << ", " << std::get<4>(result) << ", " << std::get<5>(result) << std::endl;
    return 0;
}