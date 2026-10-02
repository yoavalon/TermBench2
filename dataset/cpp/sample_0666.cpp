#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform(int x, int y, int z, int n) {
    if (n == 0) {
        return std::make_tuple(x, y, z);
    }
    return transform(y - z, x + z, x - y, n - 1);
}

int main() {
    int x = 1, y = 2, z = 3, n = 3;
    auto result = transform(x, y, z, n);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}