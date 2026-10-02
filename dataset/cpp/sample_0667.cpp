#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform_point(int x, int y, int z, int depth) {
    if (depth == 0) {
        return std::make_tuple(x, y, z);
    } else {
        return transform_point(x + 1, y - 1, z * 2, depth - 1);
    }
}

int main() {
    auto result = transform_point(0, 0, 0, 5);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}