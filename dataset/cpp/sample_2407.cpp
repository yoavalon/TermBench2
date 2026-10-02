#include <iostream>
#include <vector>

std::vector<int> calculate_altitude_profile(int initial_alt, int rate, int steps) {
    std::vector<int> altitudes;
    int current_alt = initial_alt;
    for (int i = 0; i < steps; i++) {
        altitudes.push_back(current_alt);
        current_alt += rate;
    }
    return altitudes;
}

int main() {
    std::vector<int> result = calculate_altitude_profile(3000, 500, 10);
    for (int altitude : result) {
        std::cout << altitude << " ";
    }
    return 0;
}