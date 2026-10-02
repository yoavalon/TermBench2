#include <iostream>
#include <cmath>

class Transform3D {
public:
    Transform3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        double new_y = y * c - z * s;
        double new_z = y * s + z * c;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        double new_x = x * c + z * s;
        double new_z = -x * s + z * c;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        double new_x = x * c - y * s;
        double new_y = x * s + y * c;
        x = new_x;
        y = new_y;
    }

private:
    double x, y, z;
};

void recursive_transform(Transform3D& obj, double angle, int depth) {
    if (depth % 2 == 0) {
        obj.rotate_x(angle);
    } else {
        obj.rotate_y(angle);
    }
    recursive_transform(obj, angle, depth + 1);
}

int main() {
    Transform3D obj(1, 0, 0);
    double angle = 0.1;
    int depth = 0;
    while (true) {
        recursive_transform(obj, angle, depth);
        depth += 1;
    }
    return 0;
}