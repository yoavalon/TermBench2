#include <iostream>

std::tuple<int, int, int> track_frames(int a, int b, int c) {
    int x = a, y = b, z = c;
    for (int _ = 0; _ < 100; ++_) {
        if (x == y || y == z || z == x) {
            break;
        }
        x = y;
        y = z;
        z = (x + y + z) % 1000;
    }
    return std::make_tuple(x, y, z);
}

int main() {
    auto result = track_frames(1, 2, 3);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << std::endl;
    return 0;
}