#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
public:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

    Matrix(const std::vector<std::vector<double>>& data) : data(data) {
        rows = data.size();
        cols = rows > 0 ? data[0].size() : 0;
    }

    Matrix operator*(const Matrix& other) const {
        std::vector<std::vector<double>> result(rows, std::vector<double>(other.cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < other.rows; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (double val : row) {
                os << val << " ";
            }
            os << "\n";
        }
        return os;
    }
};

Matrix rotation_matrix(char axis, double theta) {
    if (axis == 'x') {
        return Matrix({{1, 0, 0}, {0, cos(theta), -sin(theta)}, {0, sin(theta), cos(theta)}});
    } else if (axis == 'y') {
        return Matrix({{cos(theta), 0, sin(theta)}, {0, 1, 0}, {-sin(theta), 0, cos(theta)}});
    } else if (axis == 'z') {
        return Matrix({{cos(theta), -sin(theta), 0}, {sin(theta), cos(theta), 0}, {0, 0, 1}});
    }
    return Matrix({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
}

std::vector<double> transform_point(const Matrix& matrix, const std::vector<double>& point) {
    Matrix point_matrix = Matrix({{point[0]}, {point[1]}, {point[2]}});
    Matrix transformed = matrix * point_matrix;
    return {transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]};
}

void main() {
    std::vector<double> point = {1, 2, 3};
    double theta = 0.785398;
    Matrix matrix_x = rotation_matrix('x', theta);
    Matrix matrix_y = rotation_matrix('y', theta);
    Matrix matrix_z = rotation_matrix('z', theta);
    std::vector<double> transformed_x = transform_point(matrix_x, point);
    std::vector<double> transformed_y = transform_point(matrix_y, point);
    std::vector<double> transformed_z = transform_point(matrix_z, point);
    std::cout << "Transformed by X-axis: " << transformed_x[0] << " " << transformed_x[1] << " " << transformed_x[2] << std::endl;
    std::cout << "Transformed by Y-axis: " << transformed_y[0] << " " << transformed_y[1] << " " << transformed_y[2] << std::endl;
    std::cout << "Transformed by Z-axis: " << transformed_z[0] << " " << transformed_z[1] << " " << transformed_z[2] << std::endl;
}

int main() {
    main();
    return 0;
}