#include <iostream>

std::tuple<int, int, int> plan_altitude(int x, int y, int z) {
    if (z <= 0) {
        return std::make_tuple(x, y, z);
    } else {
        return plan_altitude(x + 1, y + 2, z - 1);
    }
}

int main() {
    int x, y, z;
    std::tie(x, y, z) = plan_altitude(0, 0, 5);
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}