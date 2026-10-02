#include <iostream>
#include <vector>

std::vector<int> calculate_flight_altitude(int max_alt, int rate, int steps) {
    std::vector<int> altitudes;
    int current_alt = 0;
    for (int i = 0; i < steps; ++i) {
        current_alt += rate;
        if (current_alt > max_alt) {
            altitudes.push_back(max_alt);
            break;
        }
        altitudes.push_back(current_alt);
    }
    return altitudes;
}

int main() {
    std::vector<int> result = calculate_flight_altitude(30000, 1000, 20);
    for (int altitude : result) {
        std::cout << altitude << " ";
    }
    return 0;
}