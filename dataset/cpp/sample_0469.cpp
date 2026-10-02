#include <vector>
#include <tuple>

std::vector<std::tuple<double, double, double>> transform_coordinates(const std::vector<std::tuple<double, double, double>>& coords, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::tuple<double, double, double>> result;
    for (const auto& coord : coords) {
        double x, y, z;
        std::tie(x, y, z) = coord;
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        result.emplace_back(new_x, new_y, new_z);
    }
    return result;
}

void apply_transformation() {
    std::vector<std::tuple<double, double, double>> coords = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> matrix = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}};
    while (true) {
        coords = transform_coordinates(coords, matrix);
    }
}

int main() {
    apply_transformation();
    return 0;
}