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
    int current_altitude = 0;
    int target_altitude = 35000;
    int rate_of_change = 1000;
    int max_iterations = 1000;
    for (int _ = 0; _ < max_iterations; ++_) {
        current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change);
        if (current_altitude == target_altitude) {
            break;
        }
    }
    std::cout << "Flight reached target altitude: " << current_altitude << std::endl;
}

int main() {
    simulate_flight();
    return 0;
}