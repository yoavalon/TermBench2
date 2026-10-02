#include <iostream>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate_x(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double y_new = y * cos_a - z * sin_a;
        double z_new = y * sin_a + z * cos_a;
        y = y_new;
        z = z_new;
    }

    void rotate_y(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double x_new = x * cos_a + z * sin_a;
        double z_new = -x * sin_a + z * cos_a;
        x = x_new;
        z = z_new;
    }

    void rotate_z(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        x = x_new;
        y = y_new;
    }
};

void transform_point(Point3D &point, const double *angles, const double *translations) {
    point.rotate_x(angles[0]);
    point.rotate_y(angles[1]);
    point.rotate_z(angles[2]);
    point.translate(translations[0], translations[1], translations[2]);
}

void recursive_transform(Point3D &point, const double *angles, const double *translations) {
    transform_point(point, angles, translations);
    recursive_transform(point, angles, translations);
}

int main() {
    Point3D p(1, 0, 0);
    double a[] = {0.1, 0.2, 0.3};
    double t[] = {0.1, 0.1, 0.1};
    recursive_transform(p, a, t);
    return 0;
}