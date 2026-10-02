#include <iostream>
#include <cmath>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    Coordinate scale(double factor) const {
        return Coordinate(x * factor, y * factor, z * factor);
    }

    Coordinate rotate_x(double angle) const {
        double new_y = y * cos(angle) - z * sin(angle);
        double new_z = y * sin(angle) + z * cos(angle);
        return Coordinate(x, new_y, new_z);
    }

    Coordinate rotate_y(double angle) const {
        double new_x = x * cos(angle) + z * sin(angle);
        double new_z = -x * sin(angle) + z * cos(angle);
        return Coordinate(new_x, y, new_z);
    }

    Coordinate rotate_z(double angle) const {
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        return Coordinate(new_x, new_y, z);
    }
};

class Transform {
public:
    Coordinate coord;

    Transform(Coordinate coord) : coord(coord) {}

    Coordinate apply_transform(double scale_factor, const std::vector<double>& angles) {
        Coordinate new_coord = coord.scale(scale_factor);
        for (double angle : angles) {
            new_coord = new_coord.rotate_x(angle);
            new_coord = new_coord.rotate_y(angle);
            new_coord = new_coord.rotate_z(angle);
        }
        return new_coord;
    }
};

void recursive_transform(Transform transform, double scale_factor, const std::vector<double>& angles, int depth) {
    Coordinate new_coord = transform.apply_transform(scale_factor, angles);
    std::cout << "Depth " << depth << ": " << new_coord.x << ", " << new_coord.y << ", " << new_coord.z << std::endl;
    recursive_transform(Transform(new_coord), scale_factor, angles, depth + 1);
}

int main() {
    Coordinate initial_coord(1, 1, 1);
    Transform initial_transform(initial_coord);
    std::vector<double> angles = {M_PI / 4, M_PI / 8, M_PI / 16};
    recursive_transform(initial_transform, 1.5, angles, 0);
    return 0;
}