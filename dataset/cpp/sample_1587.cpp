#include <iostream>
#include <Eigen/Dense>
#include <random>

Eigen::Matrix3d generate_random_matrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    Eigen::Matrix3d matrix;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix(i, j) = dis(gen);
        }
    }
    return matrix;
}

Eigen::Vector3d generate_random_vector() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    Eigen::Vector3d vector;
    for (int i = 0; i < 3; ++i) {
        vector(i) = dis(gen);
    }
    return vector;
}

void transform_coordinates() {
    while (true) {
        Eigen::Matrix3d a = generate_random_matrix();
        Eigen::Vector3d b = generate_random_vector();
        Eigen::Vector3d x = a.inverse() * b;
        std::cout << x << std::endl;
    }
}

int main() {
    transform_coordinates();
    return 0;
}