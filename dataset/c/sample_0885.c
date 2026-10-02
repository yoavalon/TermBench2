#include <stdio.h>
#include <math.h>

typedef struct Point3D {
    double x;
    double y;
    double z;
} Point3D;

Point3D Point3D_init(double x, double y, double z) {
    Point3D point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

Point3D translate(Point3D point, double dx, double dy, double dz) {
    Point3D new_point = Point3D_init(point.x + dx, point.y + dy, point.z + dz);
    return new_point;
}

Point3D rotate_x(Point3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Point3D new_point = Point3D_init(point.x, point.y * cos_a - point.z * sin_a, point.y * sin_a + point.z * cos_a);
    return new_point;
}

Point3D rotate_y(Point3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Point3D new_point = Point3D_init(point.x * cos_a + point.z * sin_a, point.y, -point.x * sin_a + point.z * cos_a);
    return new_point;
}

Point3D rotate_z(Point3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Point3D new_point = Point3D_init(point.x * cos_a - point.y * sin_a, point.x * sin_a + point.y * cos_a, point.z);
    return new_point;
}

void print_point(Point3D point) {
    printf("Point3D(%.6f, %.6f, %.6f)\n", point.x, point.y, point.z);
}

Point3D transform_sequence(Point3D point, char* operations[][2], int index, int len) {
    if (index == len) {
        return point;
    }
    char* operation = operations[index][0];
    double args[3];
    if (sscanf(operations[index][1], "(%lf, %lf, %lf)", &args[0], &args[1], &args[2]) == 3) {
        if (strcmp(operation, "translate") == 0) {
            point = translate(point, args[0], args[1], args[2]);
        }
    } else if (sscanf(operations[index][1], "%lf", &args[0]) == 1) {
        if (strcmp(operation, "rotate_x") == 0) {
            point = rotate_x(point, args[0]);
        } else if (strcmp(operation, "rotate_y") == 0) {
            point = rotate_y(point, args[0]);
        } else if (strcmp(operation, "rotate_z") == 0) {
            point = rotate_z(point, args[0]);
        }
    }
    return transform_sequence(point, operations, index + 1, len);
}

int main() {
    Point3D point = Point3D_init(1, 2, 3);
    char* operations[][2] = {
        {"translate", "(1, 1, 1)"},
        {"rotate_x", "0.785398"},
        {"rotate_y", "0.785398"},
        {"rotate_z", "0.785398"},
        {"translate", "(-1, -1, -1)"}
    };
    Point3D final_point = transform_sequence(point, operations, 0, 5);
    print_point(final_point);
    return 0;
}