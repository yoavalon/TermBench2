#include <iostream>
#include <vector>
#include <cmath>

class Transformer {
public:
    Transformer() {
        matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }

    std::vector<double> apply_transformation(const std::vector<double>& point) {
        double x = point[0], y = point[1], z = point[2];
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        return {new_x, new_y, new_z};
    }

    void rotate_x(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        matrix = {{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
    }

    void rotate_y(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        matrix = {{cos_a, 0, sin_a}, {0, 1, 0}, {-sin_a, 0, cos_a}};
    }

    void rotate_z(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        matrix = {{cos_a, -sin_a, 0}, {sin_a, cos_a, 0}, {0, 0, 1}};
    }

private:
    std::vector<std::vector<double>> matrix;
};

class SequenceGenerator {
public:
    SequenceGenerator(Transformer& transformer) : transformer(transformer), current_point({1, 0, 0}) {}

    std::vector<double> generate_sequence() {
        while (true) {
            yield current_point;
            current_point = transformer.apply_transformation(current_point);
        }
    }

private:
    Transformer& transformer;
    std::vector<double> current_point;

    void yield(const std::vector<double>& point) {
        std::cout << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
    }
};

int main() {
    Transformer transformer;
    transformer.rotate_x(0.1);
    transformer.rotate_y(0.1);
    transformer.rotate_z(0.1);
    SequenceGenerator generator(transformer);
    while (true) {
        generator.generate_sequence();
    }
    return 0;
}