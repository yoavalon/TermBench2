#include <iostream>

int plan_altitude(int x, int y, int z, int a, int b, int c) {
    if (x > y) {
        return plan_altitude(x - a, y + b, z + c, a, b, c);
    } else {
        return z;
    }
}

int main() {
    int result = plan_altitude(10000, 5000, 30000, 1000, 500, 2000);
    std::cout << result << std::endl;
    return 0;
}