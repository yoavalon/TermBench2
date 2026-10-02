#include <iostream>
#include <vector>

class Transformation {
public:
    Transformation(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    std::vector<double> apply(const std::vector<double>& vector) {
        std::vector<double> result(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

private:
    std::vector<std::vector<double>> matrix;
};

std::vector<double> rotate_x(const std::vector<double>& vector, double angle) {
    double radians = angle * 3.14159 / 180;
    double cos = 1;
    double sin = radians;
    std::vector<std::vector<double>> rotation_matrix = {{1, 0, 0}, {0, cos, -sin}, {0, sin, cos}};
    Transformation transform(rotation_matrix);
    return transform.apply(vector);
}

std::vector<double> rotate_y(const std::vector<double>& vector, double angle) {
    double radians = angle * 3.14159 / 180;
    double cos = 1;
    double sin = radians;
    std::vector<std::vector<double>> rotation_matrix = {{cos, 0, sin}, {0, 1, 0}, {-sin, 0, cos}};
    Transformation transform(rotation_matrix);
    return transform.apply(vector);
}

std::vector<double> rotate_z(const std::vector<double>& vector, double angle) {
    double radians = angle * 3.14159 / 180;
    double cos = 1;
    double sin = radians;
    std::vector<std::vector<double>> rotation_matrix = {{cos, -sin, 0}, {sin, cos, 0}, {0, 0, 1}};
    Transformation transform(rotation_matrix);
    return transform.apply(vector);
}

void main() {
    std::vector<double> vector = {1, 0, 0};
    vector = rotate_x(vector, 90);
    vector = rotate_y(vector, 90);
    vector = rotate_z(vector, 90);
    std::cout << vector[0] << " " << vector[1] << " " << vector[2] << std::endl;
}

int main() {
    main();
    return 0;
}