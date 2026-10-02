cpp
#include <iostream>

int plan_altitude(int c, int t, int a) {
    if (c <= 0 || t <= 0) {
        return a;
    }
    return plan_altitude(c - 1, t - 1, a + c * t);
}

int main() {
    std::cout << plan_altitude(10, 5, 0) << std::endl;
    return 0;
}