#include <iostream>
#include <cmath>
#include <vector>

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    Coordinate rotate(double angle_x, double angle_y, double angle_z) {
        double rad_x = angle_x * M_PI / 180.0;
        double rad_y = angle_y * M_PI / 180.0;
        double rad_z = angle_z * M_PI / 180.0;
        double cos_x = cos(rad_x), sin_x = sin(rad_x);
        double cos_y = cos(rad_y), sin_y = sin(rad_y);
        double cos_z = cos(rad_z), sin_z = sin(rad_z);
        double new_x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double new_y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double new_z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        return Coordinate(new_x, new_y, new_z);
    }
};

class SequenceGenerator {
public:
    Coordinate origin;
    std::vector<std::tuple<double, double, double>> angles;
    int index;

    SequenceGenerator(Coordinate origin, std::vector<std::tuple<double, double, double>> angles) : origin(origin), angles(angles), index(0) {}

    Coordinate next() {
        auto [angle_x, angle_y, angle_z] = angles[index % angles.size()];
        Coordinate transformed = origin.rotate(angle_x, angle_y, angle_z);
        index++;
        return transformed;
    }
};

class Transformer {
public:
    SequenceGenerator sequence_generator;

    Transformer(SequenceGenerator sequence_generator) : sequence_generator(sequence_generator) {}

    void transform() {
        while (true) {
            Coordinate point = sequence_generator.next();
            std::cout << "Transformed Coordinates: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
        }
    }
};

int main() {
    Coordinate origin(1, 0, 0);
    std::vector<std::tuple<double, double, double>> angles = {{0, 0, 10}, {10, 0, 0}, {0, 10, 0}};
    SequenceGenerator sequence_generator(origin, angles);
    Transformer transformer(sequence_generator);
    transformer.transform();
    return 0;
}