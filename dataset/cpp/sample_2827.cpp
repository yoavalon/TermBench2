#include <cmath>
#include <vector>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle) {
    double rad = std::radians(angle);
    double cos_a = std::cos(rad);
    double sin_a = std::sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return std::make_tuple(x_new, y_new, z);
}

void transform_sequence(std::vector<std::tuple<double, double, double>>& points, double angle) {
    while (true) {
        for (size_t i = 0; i < points.size(); ++i) {
            auto [x, y, z] = points[i];
            points[i] = rotate_point(x, y, z, angle);
        }
    }
}

int main() {
    std::vector<std::tuple<double, double, double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 10;
    transform_sequence(points, angle);
    return 0;
}