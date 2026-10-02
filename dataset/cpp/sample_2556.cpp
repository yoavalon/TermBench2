#include <iostream>
#include <vector>
#include <tuple>

std::tuple<int, int, int> transform_point(int x, int y, int z, int a, int b, int c) {
    return std::make_tuple(x + a, y + b, z + c);
}

std::vector<std::tuple<int, int, int>> apply_sequence(const std::vector<std::tuple<int, int, int>>& points, const std::vector<std::tuple<int, int, int>>& seq) {
    std::vector<std::tuple<int, int, int>> result;
    for (const auto& point : points) {
        std::tuple<int, int, int> current_point = point;
        for (const auto& transform : seq) {
            int x, y, z;
            int a, b, c;
            std::tie(x, y, z) = current_point;
            std::tie(a, b, c) = transform;
            current_point = transform_point(x, y, z, a, b, c);
        }
        result.push_back(current_point);
    }
    return result;
}

void main() {
    std::vector<std::tuple<int, int, int>> points = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::tuple<int, int, int>> sequence = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::tuple<int, int, int>> transformed_points = apply_sequence(points, sequence);
    for (const auto& point : transformed_points) {
        int x, y, z;
        std::tie(x, y, z) = point;
        std::cout << "(" << x << ", " << y << ", " << z << ") ";
    }
}