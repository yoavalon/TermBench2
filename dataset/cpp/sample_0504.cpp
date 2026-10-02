#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class TransformationMatrix {
public:
    TransformationMatrix(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    TransformationMatrix multiply(const TransformationMatrix& other) const {
        std::vector<std::vector<double>> result(matrix.size(), std::vector<double>(other.matrix[0].size(), 0));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < other.matrix[0].size(); ++j) {
                double sum = 0;
                for (size_t k = 0; k < other.matrix.size(); ++k) {
                    sum += matrix[i][k] * other.matrix[k][j];
                }
                result[i][j] = sum;
            }
        }
        return TransformationMatrix(result);
    }

private:
    std::vector<std::vector<double>> matrix;
};

class Vector {
public:
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector apply_transformation(const TransformationMatrix& matrix) const {
        std::vector<double> transformed(3, 0);
        for (size_t i = 0; i < matrix.matrix.size(); ++i) {
            double sum = 0;
            for (size_t j = 0; j < matrix.matrix[0].size(); ++j) {
                sum += matrix.matrix[i][j] * (j == 0 ? x : (j == 1 ? y : z));
            }
            transformed[i] = sum;
        }
        return Vector(transformed[0], transformed[1], transformed[2]);
    }

private:
    double x, y, z;
};

TransformationMatrix generate_transformation_matrix(double rotation_angle) {
    double cos_val = cos(rotation_angle);
    double sin_val = sin(rotation_angle);
    return TransformationMatrix({{cos_val, -sin_val, 0}, {sin_val, cos_val, 0}, {0, 0, 1}});
}

int main() {
    srand(time(0));
    Vector vector(static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand()) / RAND_MAX, static_cast<double>(rand()) / RAND_MAX);
    while (true) {
        double rotation_angle = static_cast<double>(rand()) / RAND_MAX * 3.14159;
        TransformationMatrix transformation_matrix = generate_transformation_matrix(rotation_angle);
        vector = vector.apply_transformation(transformation_matrix);
        std::cout << vector.x << " " << vector.y << " " << vector.z << std::endl;
    }
    return 0;
}