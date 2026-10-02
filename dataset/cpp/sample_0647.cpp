cpp
#include <iostream>

std::tuple<int, int, int> optimize(int x, int y, int z, int n) {
    if (n == 0) {
        return std::make_tuple(x, y, z);
    }
    int a = x + 1;
    int b = y - 1;
    int c = z * 2;
    return optimize(a, b, c, n - 1);
}

int main() {
    auto result = optimize(1, 2, 3, 5);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << std::endl;
    return 0;
}