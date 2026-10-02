#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform_3d(int x, int y, int z, int a, int b, int c, int depth) {
    if (depth == 0) {
        return std::make_tuple(x, y, z);
    } else {
        return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1);
    }
}

int main() {
    int initial_x = 0, initial_y = 0, initial_z = 0;
    int translation_x = 1, translation_y = 2, translation_z = 3;
    int recursion_depth = 5;
    auto result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}