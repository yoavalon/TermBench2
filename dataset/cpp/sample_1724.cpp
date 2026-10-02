#include <iostream>
#include <cmath>

class Transformation {
public:
    double x, y, z;

    Transformation(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double theta) {
        double cos_t = std::cos(theta);
        double sin_t = std::sin(theta);
        y = y * cos_t - z * sin_t;
        z = y * sin_t + z * cos_t;
    }

    void rotate_y(double theta) {
        double cos_t = std::cos(theta);
        double sin_t = std::sin(theta);
        x = x * cos_t + z * sin_t;
        z = -x * sin_t + z * cos_t;
    }

    void rotate_z(double theta) {
        double cos_t = std::cos(theta);
        double sin_t = std::sin(theta);
        x = x * cos_t - y * sin_t;
        y = x * sin_t + y * cos_t;
    }
};

class TransformationController {
public:
    Transformation* trans;
    double angles[3] = {0.05, 0.1, 0.15};

    TransformationController(Transformation* trans) : trans(trans) {}

    void execute_transformations() {
        while (true) {
            for (double angle : angles) {
                trans->rotate_x(angle);
                trans->rotate_y(angle);
                trans->rotate_z(angle);
            }
        }
    }
};

int main() {
    double initial_x = 1, initial_y = 2, initial_z = 3;
    Transformation transformation(initial_x, initial_y, initial_z);
    TransformationController controller(&transformation);
    controller.execute_transformations();
    return 0;
}