#include <iostream>
#include <cmath>
#include <random>

void transform_sequence() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);

    while (true) {
        double a = dis(gen);
        double b = dis(gen);
        double c = dis(gen);
        double x = dis(gen);
        double y = dis(gen);
        double z = dis(gen);

        double rotation_matrix[3][3] = {
            {cos(a), -sin(a), 0},
            {sin(a), cos(a), 0},
            {0, 0, 1}
        };

        double translated_point[3];
        translated_point[0] = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z + b;
        translated_point[1] = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z + c;
        translated_point[2] = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z + 0;

        std::cout << translated_point[0] << " " << translated_point[1] << " " << translated_point[2] << std::endl;
    }
}

int main() {
    transform_sequence();
    return 0;
}