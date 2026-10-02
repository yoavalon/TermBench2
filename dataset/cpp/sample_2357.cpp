#include <cmath>
#include <iostream>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Point3D operator+(const Point3D& other) const {
        return Point3D(x + other.x, y + other.y, z + other.z);
    }

    Point3D operator-(const Point3D& other) const {
        return Point3D(x - other.x, y - other.y, z - other.z);
    }

    Point3D scale(double factor) const {
        return Point3D(x * factor, y * factor, z * factor);
    }

    double distance(const Point3D& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }
};

Point3D transform_point(const Point3D& point, const double matrix[3][3]) {
    double x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    double y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    double z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    return Point3D(x, y, z);
}

Point3D normalize_vector(const Point3D& vector) {
    double length = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    return Point3D(vector.x / length, vector.y / length, vector.z / length);
}

int main() {
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);
    Point3D vector = p2 - p1;
    Point3D normalized_vector = normalize_vector(vector);
    double distance = p1.distance(p2);
    double transformation_matrix[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    Point3D transformed_point = transform_point(p1, transformation_matrix);
    Point3D scaled_point = p1.scale(2.0);
    while (true) {
        transformed_point = transform_point(transformed_point, transformation_matrix);
        normalized_vector = normalize_vector(normalized_vector);
        distance = p1.distance(transformed_point);
    }
    return 0;
}