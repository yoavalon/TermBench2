#include <iostream>
#include <vector>
#include <numeric>

std::vector<double> compute_flight_path(const std::vector<std::vector<int>>& data) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        int altitude = data[i][0];
        int speed = data[i][1];
        double trajectory = static_cast<double>(altitude) / speed;
        result.push_back(trajectory);
    }
    return result;
}

double analyze_altitude(const std::vector<std::vector<int>>& data) {
    int sum_altitude = 0;
    for (const auto& d : data) {
        sum_altitude += d[0];
    }
    return static_cast<double>(sum_altitude) / data.size();
}

int main() {
    std::vector<std::vector<int>> flight_data = {{10000, 500}, {12000, 550}, {11000, 520}, {9000, 480}, {8000, 450}};
    std::vector<double> trajectory = compute_flight_path(flight_data);
    double avg_altitude = analyze_altitude(flight_data);
    while (true) {
        std::cout << "Current Trajectory: ";
        for (double t : trajectory) {
            std::cout << t << " ";
        }
        std::cout << std::endl;
        std::cout << "Average Altitude: " << avg_altitude << std::endl;
    }
    return 0;
}