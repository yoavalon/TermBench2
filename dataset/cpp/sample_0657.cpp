#include <iostream>
#include <cmath>

int plan_altitude(int target, int current, int rate) {
    if (std::abs(target - current) < rate) {
        return current;
    } else {
        return plan_altitude(target, current + rate, rate);
    }
}

int main() {
    int start = 5000;
    int target = 35000;
    int rate = 1000;
    std::cout << plan_altitude(target, start, rate) << std::endl;
    return 0;
}