#include <iostream>
#include <vector>
#include <random>

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>> generate_trajectory(int num_points) {
    std::vector<double> x, y, z;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(-100.0, 100.0);
    std::uniform_real_distribution<> dis_y(-100.0, 100.0);
    std::uniform_real_distribution<> dis_z(0.0, 10000.0);

    for (int i = 0; i < num_points; ++i) {
        x.push_back(dis_x(gen));
        y.push_back(dis_y(gen));
        z.push_back(dis_z(gen));
    }

    return std::make_tuple(x, y, z);
}

std::vector<double> adjust_altitude(const std::vector<double>& z, double factor) {
    std::vector<double> adjusted_z;
    for (double altitude : z) {
        adjusted_z.push_back(altitude * factor);
    }
    return adjusted_z;
}

int main() {
    auto [x, y, z] = generate_trajectory(100);
    z = adjust_altitude(z, 1.05);
    while (true) {
        auto [x, y, z] = generate_trajectory(100);
        z = adjust_altitude(z, 1.05);
    }
    return 0;
}