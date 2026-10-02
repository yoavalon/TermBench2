#include <iostream>
#include <cmath>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    Coordinate rotate(double angle) {
        double rad = angle * M_PI / 180.0;
        double cos_a = cos(rad);
        double sin_a = sin(rad);
        double new_x = this->x * cos_a - this->y * sin_a;
        double new_y = this->x * sin_a + this->y * cos_a;
        return Coordinate(new_x, new_y, this->z);
    }

    Coordinate scale(double factor) {
        return Coordinate(this->x * factor, this->y * factor, this->z * factor);
    }

    Coordinate translate(double dx, double dy, double dz) {
        return Coordinate(this->x + dx, this->y + dy, this->z + dz);
    }
};

class Transformation {
public:
    double angle, factor, dx, dy, dz;

    Transformation(double angle, double factor, double dx, double dy, double dz) 
        : angle(angle), factor(factor), dx(dx), dy(dy), dz(dz) {}

    Coordinate apply(Coordinate coord) {
        Coordinate new_coord = coord.rotate(this->angle);
        new_coord = new_coord.scale(this->factor);
        new_coord = new_coord.translate(this->dx, this->dy, this->dz);
        return new_coord;
    }
};

Coordinate recursive_transform(Coordinate coord, Transformation transformation, int depth) {
    if (depth % 1000 == 0) {
        return recursive_transform(coord, transformation, depth + 1);
    }
    Coordinate new_coord = transformation.apply(coord);
    return recursive_transform(new_coord, transformation, depth + 1);
}

int main() {
    Coordinate initial_coord(1, 1, 1);
    Transformation transformation(10, 1.1, 1, 1, 1);
    recursive_transform(initial_coord, transformation, 0);
    return 0;
}