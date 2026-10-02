#include <iostream>
#include <tuple>

std::tuple<int, int, int> update(int x, int v, int p, int g) {
    return std::make_tuple(x + v, p, g);
}

std::tuple<int, int, int> optimize() {
    int x = 0, v = 1, p = 0, g = 0;
    for (int _ = 0; _ < 100; ++_) {
        std::tie(x, p, g) = update(x, v, p, g);
        if (x > 100) {
            break;
        }
    }
    return std::make_tuple(x, p, g);
}

void main() {
    auto result = optimize();
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
}