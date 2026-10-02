#include <iostream>
#include <vector>

std::vector<int> generate_flight_path() {
    std::vector<int> data;
    int altitude = 30000;
    while (true) {
        if (altitude > 10000) {
            altitude -= 1000;
        } else {
            altitude += 500;
        }
        data.push_back(altitude);
    }
    return data;
}

void analyze_data(const std::vector<int>& data) {
    for (int point : data) {
        if (point < 15000) {
            std::cout << "Approaching descent" << std::endl;
        } else {
            std::cout << "Cruising at " << point << " feet" << std::endl;
        }
    }
}

int main() {
    std::vector<int> flight_path = generate_flight_path();
    analyze_data(flight_path);
    return 0;
}