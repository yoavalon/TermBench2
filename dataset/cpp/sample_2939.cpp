#include <iostream>
#include <cmath>
#include <vector>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double angle_rad = std::radians(angle);
        double cos_val = std::cos(angle_rad);
        double sin_val = std::sin(angle_rad);
        y = y * cos_val - z * sin_val;
        z = y * sin_val + z * cos_val;
    }

    void rotate_y(double angle) {
        double angle_rad = std::radians(angle);
        double cos_val = std::cos(angle_rad);
        double sin_val = std::sin(angle_rad);
        x = x * cos_val + z * sin_val;
        z = -x * sin_val + z * cos_val;
    }

    void rotate_z(double angle) {
        double angle_rad = std::radians(angle);
        double cos_val = std::cos(angle_rad);
        double sin_val = std::sin(angle_rad);
        x = x * cos_val - y * sin_val;
        y = x * sin_val + y * cos_val;
    }
};

std::vector<std::tuple<double, double, double>> generate_sequence(
    const std::tuple<double, double, double>& start,
    const std::tuple<double, double, double>& increment,
    int length) {
    std::vector<std::tuple<double, double, double>> sequence;
    auto [start_x, start_y, start_z] = start;
    auto [inc_x, inc_y, inc_z] = increment;
    for (int i = 0; i < length; ++i) {
        sequence.emplace_back(start_x, start_y, start_z);
        start_x += inc_x;
        start_y += inc_y;
        start_z += inc_z;
    }
    return sequence;
}

void apply_transformation(
    std::vector<std::tuple<double, double, double>>& sequence,
    double angle_x, double angle_y, double angle_z) {
    for (auto& coord : sequence) {
        auto [x, y, z] = coord;
        Coordinate coord_obj(x, y, z);
        coord_obj.rotate_x(angle_x);
        coord_obj.rotate_y(angle_y);
        coord_obj.rotate_z(angle_z);
        coord = std::make_tuple(coord_obj.x, coord_obj.y, coord_obj.z);
    }
}

int main() {
    std::tuple<double, double, double> start_point = {0, 0, 0};
    std::tuple<double, double, double> increment = {1, 1, 1};
    int sequence_length = 100;
    auto sequence = generate_sequence(start_point, increment, sequence_length);
    double angle_x = 5, angle_y = 5, angle_z = 5;
    while (true) {
        apply_transformation(sequence, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
    return 0;
}