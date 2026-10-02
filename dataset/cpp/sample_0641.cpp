#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform_3d(int x, int y, int z, int n) {
    if (n == 0) {
        return std::make_tuple(x, y, z);
    } else {
        return transform_3d(x + 1, y + 1, z + 1, n - 1);
    }
}

int main() {
    auto result = transform_3d(0, 0, 0, 5);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}