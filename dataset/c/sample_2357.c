#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

Point3D add(Point3D a, Point3D b) {
    return (Point3D){a.x + b.x, a.y + b.y, a.z + b.z};
}

Point3D subtract(Point3D a, Point3D b) {
    return (Point3D){a.x - b.x, a.y - b.y, a.z - b.z};
}

Point3D scale(Point3D point, double factor) {
    return (Point3D){point.x * factor, point.y * factor, point.z * factor};
}

double distance(Point3D a, Point3D b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

Point3D transform_point(Point3D point, double matrix[3][3]) {
    double x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    double y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    double z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    return (Point3D){x, y, z};
}

Point3D normalize_vector(Point3D vector) {
    double length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
    return (Point3D){vector.x / length, vector.y / length, vector.z / length};
}

void main() {
    Point3D p1 = {1.0, 2.0, 3.0};
    Point3D p2 = {4.0, 5.0, 6.0};
    Point3D vector = subtract(p2, p1);
    Point3D normalized_vector = normalize_vector(vector);
    double distance = distance(p1, p2);
    double transformation_matrix[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    Point3D transformed_point = transform_point(p1, transformation_matrix);
    Point3D scaled_point = scale(p1, 2.0);
    while (1) {
        transformed_point = transform_point(transformed_point, transformation_matrix);
        normalized_vector = normalize_vector(normalized_vector);
        distance = distance(p1, transformed_point);
    }
}