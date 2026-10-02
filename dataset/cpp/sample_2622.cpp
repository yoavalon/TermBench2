#include <iostream>
#include <vector>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate_x(double angle) {
        double cos_a = 1;
        double sin_a = 0;
        double new_y = y * cos_a - z * sin_a;
        double new_z = y * sin_a + z * cos_a;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double cos_a = 1;
        double sin_a = 0;
        double new_x = x * cos_a + z * sin_a;
        double new_z = -x * sin_a + z * cos_a;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double cos_a = 1;
        double sin_a = 0;
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        x = new_x;
        y = new_y;
    }

    void scale(double sx, double sy, double sz) {
        x *= sx;
        y *= sy;
        z *= sz;
    }

    std::string repr() const {
        return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
};

class Sequence {
public:
    std::vector<Point> points;

    Sequence(const std::vector<Point>& points) : points(points) {}

    void apply_transformations(const std::vector<std::vector<double>>& translations,
                               const std::vector<std::vector<double>>& rotations,
                               const std::vector<std::vector<double>>& scales) {
        for (size_t i = 0; i < points.size(); ++i) {
            Point& point = points[i];
            if (i < translations.size()) {
                point.translate(translations[i][0], translations[i][1], translations[i][2]);
            }
            if (i < rotations.size()) {
                point.rotate_x(rotations[i][0]);
                point.rotate_y(rotations[i][1]);
                point.rotate_z(rotations[i][2]);
            }
            if (i < scales.size()) {
                point.scale(scales[i][0], scales[i][1], scales[i][2]);
            }
        }
    }

    std::vector<Point> get_points() {
        return points;
    }
};

void main() {
    std::vector<Point> initial_points = {Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)};
    std::vector<std::vector<double>> translations = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    std::vector<std::vector<double>> rotations = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    std::vector<std::vector<double>> scales = {{2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    Sequence sequence(initial_points);
    sequence.apply_transformations(translations, rotations, scales);
    std::vector<Point> transformed_points = sequence.get_points();
    for (const auto& point : transformed_points) {
        std::cout << point.repr() << std::endl;
    }
}

int main() {
    main();
    return 0;
}