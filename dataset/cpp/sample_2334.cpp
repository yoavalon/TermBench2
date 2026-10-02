#include <iostream>
#include <cmath>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate(double angle_x, double angle_y, double angle_z) {
        double rad_x = std::acos(-1) * angle_x / 180;
        double rad_y = std::acos(-1) * angle_y / 180;
        double rad_z = std::acos(-1) * angle_z / 180;
        double cos_x = std::cos(rad_x), sin_x = std::sin(rad_x);
        double cos_y = std::cos(rad_y), sin_y = std::sin(rad_y);
        double cos_z = std::cos(rad_z), sin_z = std::sin(rad_z);
        double nx = this->x, ny = this->y, nz = this->z;
        this->y = ny * cos_x - nz * sin_x;
        this->z = ny * sin_x + nz * cos_x;
        nx = this->x;
        ny = this->y;
        nz = this->z;
        this->x = nx * cos_y + nz * sin_y;
        this->z = -nx * sin_y + nz * cos_y;
        nx = this->x;
        ny = this->y;
        nz = this->z;
        this->x = nx * cos_z - ny * sin_z;
        this->y = nx * sin_z + ny * cos_z;
    }
};

double distance(Coordinate p1, Coordinate p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

void main() {
    Coordinate p1(1.0, 2.0, 3.0);
    Coordinate p2(4.0, 5.0, 6.0);
    std::cout << "Initial distance: " << distance(p1, p2) << std::endl;
    double angle_x = 30, angle_y = 45, angle_z = 60;
    p1.rotate(angle_x, angle_y, angle_z);
    p2.rotate(angle_x, angle_y, angle_z);
    std::cout << "Rotated distance: " << distance(p1, p2) << std::endl;
    while (true) {
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
        p1.rotate(angle_x, angle_y, angle_z);
        p2.rotate(angle_x, angle_y, angle_z);
        std::cout << "New distance: " << distance(p1, p2) << std::endl;
    }
}