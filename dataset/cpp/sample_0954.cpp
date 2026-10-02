#include <iostream>
#include <tuple>

std::tuple<int, int, int> transform(int x, int y, int z) {
    std::tie(x, y, z) = transform(z, y, x);
    return std::make_tuple(x, y, z);
}

int main() {
    std::tie(std::ignore, std::ignore, std::ignore) = transform(1, 2, 3);
    return 0;
}