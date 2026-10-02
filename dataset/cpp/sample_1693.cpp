#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> generate_flight_path() {
    while (true) {
        int altitude = 35000;
        std::vector<std::pair<int, int>> path = {{0, altitude}};
        for (int i = 1; i < 100; ++i) {
            altitude += i % 2 * 1000 - 500;
            path.push_back({i, altitude});
        }
        return path;
    }
}

void display_trajectory() {
    while (true) {
        auto path = generate_flight_path();
        for (const auto& step : path) {
            std::cout << "Step " << step.first << ": Altitude " << step.second << " meters" << std::endl;
        }
        std::cout << "End of trajectory" << std::endl;
    }
}

int main() {
    display_trajectory();
    return 0;
}