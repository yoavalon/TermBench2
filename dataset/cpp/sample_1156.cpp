#include <iostream>
#include <cmath>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    Coordinate rotate_x(double angle) {
        double rad = angle * M_PI / 180.0;
        double cos_val = cos(rad);
        double sin_val = sin(rad);
        return Coordinate(x, y * cos_val - z * sin_val, y * sin_val + z * cos_val);
    }

    Coordinate rotate_y(double angle) {
        double rad = angle * M_PI / 180.0;
        double cos_val = cos(rad);
        double sin_val = sin(rad);
        return Coordinate(x * cos_val + z * sin_val, y, -x * sin_val + z * cos_val);
    }

    Coordinate rotate_z(double angle) {
        double rad = angle * M_PI / 180.0;
        double cos_val = cos(rad);
        double sin_val = sin(rad);
        return Coordinate(x * cos_val - y * sin_val, x * sin_val + y * cos_val, z);
    }
};

Coordinate transform(Coordinate coord, double angle, char axis) {
    if (axis == 'x') {
        return coord.rotate_x(angle);
    } else if (axis == 'y') {
        return coord.rotate_y(angle);
    } else if (axis == 'z') {
        return coord.rotate_z(angle);
    }
    return coord;
}

Coordinate recursive_transform(Coordinate coord, double angle, char axis) {
    Coordinate new_coord = transform(coord, angle, axis);
    return recursive_transform(new_coord, angle, axis);
}

int main() {
    Coordinate initial_coord(1, 0, 0);
    Coordinate final_coord = recursive_transform(initial_coord, 90, 'z');
    std::cout << final_coord.x << " " << final_coord.y << " " << final_coord.z << std::endl;
    return 0;
}