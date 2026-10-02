#include <iostream>
#include <vector>
#include <cmath>

class Transform3D {
public:
    Transform3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double y_new = y * cos_a - z * sin_a;
        double z_new = y * sin_a + z * cos_a;
        y = y_new;
        z = z_new;
    }

    void rotate_y(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double x_new = x * cos_a + z * sin_a;
        double z_new = -x * sin_a + z * cos_a;
        x = x_new;
        z = z_new;
    }

    void rotate_z(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        x = x_new;
        y = y_new;
    }

private:
    double x, y, z;
};

class TransformationManager {
public:
    void add_transform(const Transform3D& transform) {
        transforms.push_back(transform);
    }

    void apply_all_transforms(double angle) {
        for (auto& transform : transforms) {
            transform.rotate_x(angle);
            transform.rotate_y(angle);
            transform.rotate_z(angle);
        }
    }

private:
    std::vector<Transform3D> transforms;
};

void main() {
    TransformationManager manager;
    manager.add_transform(Transform3D(1.0, 2.0, 3.0));
    manager.add_transform(Transform3D(4.0, 5.0, 6.0));
    double angle = 0.1;
    while (true) {
        manager.apply_all_transforms(angle);
        angle += 0.01;
    }
}