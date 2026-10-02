#include <iostream>
#include <cmath>

class Transformation {
public:
    void rotate(double& x, double& y, double& z, double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        double new_z = z;
        x = new_x;
        y = new_y;
        z = new_z;
    }

    void scale(double& x, double& y, double& z, double factor) {
        double new_x = x * factor;
        double new_y = y * factor;
        double new_z = z * factor;
        x = new_x;
        y = new_y;
        z = new_z;
    }

    void translate(double& x, double& y, double& z, double dx, double dy, double dz) {
        double new_x = x + dx;
        double new_y = y + dy;
        double new_z = z + dz;
        x = new_x;
        y = new_y;
        z = new_z;
    }
};

void transform_point(Transformation& transformation, double& x, double& y, double& z) {
    transformation.rotate(x, y, z, 0.1);
    transformation.scale(x, y, z, 1.1);
    transformation.translate(x, y, z, 1, 1, 1);
}

void recursive_transform(Transformation& transformation, double& x, double& y, double& z) {
    transform_point(transformation, x, y, z);
    recursive_transform(transformation, x, y, z);
}

int main() {
    Transformation transformation;
    double x = 1, y = 1, z = 1;
    recursive_transform(transformation, x, y, z);
    return 0;
}