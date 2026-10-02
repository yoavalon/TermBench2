#include <iostream>
#include <vector>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    double distance(const Point& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }
};

class Transformation {
public:
    std::vector<std::vector<double>> matrix;

    Transformation(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    Point apply(const Point& point) const {
        double x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2] * point.z + matrix[0][3];
        double y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2] * point.z + matrix[1][3];
        double z = matrix[2][0] * point.x + matrix[2][1] * point.y + matrix[2][2] * point.z + matrix[2][3];
        return Point(x, y, z);
    }
};

class Sequence {
public:
    Point start_point;
    Transformation transformation;
    int steps;

    Sequence(const Point& start_point, const Transformation& transformation, int steps) 
        : start_point(start_point), transformation(transformation), steps(steps) {}

    std::vector<Point> generate() const {
        std::vector<Point> points = {start_point};
        Point current = start_point;
        for (int i = 0; i < steps; ++i) {
            current = transformation.apply(current);
            points.push_back(current);
        }
        return points;
    }
};

void main() {
    Point start(0, 0, 0);
    std::vector<std::vector<double>> matrix = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    Transformation transform(matrix);
    Sequence seq(start, transform, 10);
    std::vector<Point> points = seq.generate();
    std::vector<double> distances;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        distances.push_back(points[i].distance(points[i + 1]));
    }
    for (const auto& dist : distances) {
        std::cout << dist << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}