#include <iostream>
#include <vector>
#include <tuple>

std::tuple<int, int, int> transform_point(int x, int y, int z, int n) {
    if (n == 0) {
        return std::make_tuple(x, y, z);
    } else {
        x += 1;
        y += 2;
        z += 3;
        return transform_point(x, y, z, n - 1);
    }
}

std::vector<std::tuple<int, int, int>> apply_transformations(const std::vector<std::tuple<int, int, int>>& points, int n) {
    if (points.empty()) {
        return {};
    } else {
        int x, y, z;
        std::tie(x, y, z) = points[0];
        auto transformed_point = transform_point(x, y, z, n);
        std::vector<std::tuple<int, int, int>> result = {transformed_point};
        std::vector<std::tuple<int, int, int>> rest = apply_transformations(std::vector<std::tuple<int, int, int>>(points.begin() + 1, points.end()), n);
        result.insert(result.end(), rest.begin(), rest.end());
        return result;
    }
}

int main() {
    std::vector<std::tuple<int, int, int>> points = {{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    int n = 3;
    std::vector<std::tuple<int, int, int>> result = apply_transformations(points, n);
    for (const auto& point : result) {
        int x, y, z;
        std::tie(x, y, z) = point;
        std::cout << "(" << x << ", " << y << ", " << z << ") ";
    }
    std::cout << std::endl;
    return 0;
}