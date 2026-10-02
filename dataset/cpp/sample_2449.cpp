#include <iostream>
#include <Eigen/Dense>

Eigen::MatrixXd transform_3d_coordinates(const Eigen::MatrixXd& data, const Eigen::MatrixXd& matrix) {
    Eigen::MatrixXd transformed_data = data * matrix;
    return transformed_data;
}

int main() {
    Eigen::MatrixXd data(3, 3);
    data << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;

    Eigen::MatrixXd matrix(3, 3);
    matrix << 0, 1, 0,
              0, 0, 1,
              1, 0, 0;

    Eigen::MatrixXd result = transform_3d_coordinates(data, matrix);
    std::cout << result << std::endl;
    return 0;
}