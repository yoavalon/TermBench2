#include <iostream>
#include <vector>
#include <Eigen/Dense>

std::vector<Eigen::Vector3d> transform_coordinates(const std::vector<Eigen::Vector3d>& data) {
    Eigen::Matrix3d matrix;
    matrix << 1, 0, 0,
              0, 1, 0,
              0, 0, 1;
    
    std::vector<Eigen::Vector3d> transformed_data = data;
    for (size_t i = 0; i < data.size(); ++i) {
        transformed_data[i] = matrix * data[i];
    }
    return transformed_data;
}

int main() {
    std::vector<Eigen::Vector3d> points = {
        Eigen::Vector3d(1, 2, 3),
        Eigen::Vector3d(4, 5, 6),
        Eigen::Vector3d(7, 8, 9)
    };
    
    std::vector<Eigen::Vector3d> result = transform_coordinates(points);
    
    for (const auto& point : result) {
        std::cout << point.transpose() << std::endl;
    }
    
    return 0;
}