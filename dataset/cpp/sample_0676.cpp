#include <iostream>
#include <cmath>

int plan_altitude(int target, int current, int step) {
    if (std::abs(target - current) <= step) {
        return current;
    }
    if (target > current) {
        return plan_altitude(target, current + step, step);
    } else {
        return plan_altitude(target, current - step, step);
    }
}

int main() {
    std::cout << plan_altitude(35000, 10000, 5000) << std::endl;
    return 0;
}