#include <iostream>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double a, double b, double c) {
        x += a;
        y += b;
        z += c;
    }

    void rotate_x(double angle) {
        double cos_angle = cos(angle);
        double sin_angle = sin(angle);
        double new_y = y * cos_angle - z * sin_angle;
        double new_z = y * sin_angle + z * cos_angle;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double cos_angle = cos(angle);
        double sin_angle = sin(angle);
        double new_x = x * cos_angle + z * sin_angle;
        double new_z = -x * sin_angle + z * cos_angle;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double cos_angle = cos(angle);
        double sin_angle = sin(angle);
        double new_x = x * cos_angle - y * sin_angle;
        double new_y = x * sin_angle + y * cos_angle;
        x = new_x;
        y = new_y;
    }
};

class Transformations {
public:
    Point* point;

    Transformations(Point* point) : point(point) {}

    void apply_transformations(double a, double b, double c, double angle_x, double angle_y, double angle_z) {
        point->translate(a, b, c);
        point->rotate_x(angle_x);
        point->rotate_y(angle_y);
        point->rotate_z(angle_z);
    }
};

void recursive_transform(Transformations* transform_obj, double angle_increment) {
    angle_increment = angle_increment * M_PI / 180.0;
    transform_obj->apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment);
    recursive_transform(transform_obj, angle_increment);
}

int main() {
    Point point(0, 0, 0);
    Transformations transformations(&point);
    recursive_transform(&transformations, 1);
    return 0;
}