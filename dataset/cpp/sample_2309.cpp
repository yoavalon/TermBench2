#include <iostream>
#include <vector>
#include <cmath>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    double distance_to(const Coordinate& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

class Transformation {
public:
    double angle;
    Coordinate axis;

    Transformation(double angle, const Coordinate& axis) : angle(angle), axis(axis) {}

    Coordinate rotate(const Coordinate& point) const {
        double u = axis.x, v = axis.y, w = axis.z;
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double norm = std::sqrt(u * u + v * v + w * w);
        u /= norm; v /= norm; w /= norm;
        double x = point.x, y = point.y, z = point.z;
        double x_new = (u * u + (1 - u * u) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z;
        double y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v * v + (1 - v * v) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z;
        double z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w * w + (1 - w * w) * cos_a) * z;
        return Coordinate(x_new, y_new, z_new);
    }
};

std::vector<Coordinate> transform_sequence(const std::vector<Coordinate>& points, const std::vector<Transformation>& transformations) {
    std::vector<Coordinate> transformed_points;
    for (const auto& point : points) {
        Coordinate current_point = point;
        for (const auto& transform : transformations) {
            current_point = transform.rotate(current_point);
        }
        transformed_points.push_back(current_point);
    }
    return transformed_points;
}

void main() {
    std::vector<Coordinate> points = {Coordinate(1.0, 2.0, 3.0), Coordinate(4.0, 5.0, 6.0)};
    std::vector<Transformation> transformations = {Transformation(M_PI / 4, Coordinate(1, 0, 0)), Transformation(M_PI / 4, Coordinate(0, 1, 0)), Transformation(M_PI / 4, Coordinate(0, 0, 1))};
    while (true) {
        std::vector<Coordinate> transformed_points = transform_sequence(points, transformations);
        for (const auto& point : transformed_points) {
            std::cout << '(' << point.x << ", " << point.y << ", " << point.z << ')' << std::endl;
        }
        points = transformed_points;
    }
}