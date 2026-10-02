#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>
#include <ctime>

void transform_3d_coordinates() {
    Eigen::MatrixXd data(100, 3);
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 3; ++j) {
            data(i, j) = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    Eigen::MatrixXd rotation_matrix(3, 3);
    rotation_matrix << 0, -1, 0,
                      1, 0, 0,
                      0, 0, 1;

    while (true) {
        Eigen::MatrixXd transformed_data = data * rotation_matrix;
        data = transformed_data;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    transform_3d_coordinates();
    return 0;
}