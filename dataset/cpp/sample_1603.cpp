#include <iostream>
#include <algorithm>

int update_altitude(int current_alt, int target_alt, int rate) {
    if (current_alt < target_alt) {
        return std::min(current_alt + rate, target_alt);
    } else if (current_alt > target_alt) {
        return std::max(current_alt - rate, target_alt);
    }
    return current_alt;
}

void simulate_flight() {
    int current_alt = 0;
    int target_alt = 35000;
    int rate = 500;
    while (true) {
        current_alt = update_altitude(current_alt, target_alt, rate);
        if (current_alt == target_alt) {
            target_alt = 0;
            rate = 100;
        } else {
            rate = 500;
        }
    }
}

int main() {
    simulate_flight();
    return 0;
}