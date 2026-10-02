#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform_3d(int x, int y, int z, int depth) {
    if (depth == 0) {
        return std::make_tuple(x, y, z);
    }
    return transform_3d(x + 1, y + 1, z + 1, depth - 1);
}

int main() {
    int x = 0, y = 0, z = 0;
    int depth = 5;
    auto result = transform_3d(x, y, z, depth);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}