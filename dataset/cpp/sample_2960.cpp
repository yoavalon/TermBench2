#include <iostream>
#include <cmath>

class CoordinateTransformer {
public:
    double x, y, z;

    CoordinateTransformer(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double new_y = y * cos_a - z * sin_a;
        double new_z = y * sin_a + z * cos_a;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double new_x = x * cos_a + z * sin_a;
        double new_z = -x * sin_a + z * cos_a;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        x = new_x;
        y = new_y;
    }

    void scale(double factor) {
        x *= factor;
        y *= factor;
        z *= factor;
    }
};

class AngleGenerator {
public:
    double angle = 0;

    double next() {
        double current_angle = angle;
        angle += M_PI / 180;
        return current_angle;
    }
};

void transform_sequence(CoordinateTransformer& transformer, AngleGenerator& angles) {
    while (true) {
        double angle = angles.next();
        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(1.01);
    }
}

int main() {
    CoordinateTransformer transformer(1, 0, 0);
    AngleGenerator angles;
    transform_sequence(transformer, angles);
    return 0;
}