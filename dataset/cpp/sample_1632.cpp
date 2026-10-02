#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double radians_x = angle_x * M_PI / 180.0;
    double radians_y = angle_y * M_PI / 180.0;
    double radians_z = angle_z * M_PI / 180.0;

    double rotation_x[3][3] = {
        {1, 0, 0},
        {0, cos(radians_x), -sin(radians_x)},
        {0, sin(radians_x), cos(radians_x)}
    };

    double rotation_y[3][3] = {
        {cos(radians_y), 0, sin(radians_y)},
        {0, 1, 0},
        {-sin(radians_y), 0, cos(radians_y)}
    };

    double rotation_z[3][3] = {
        {cos(radians_z), -sin(radians_z), 0},
        {sin(radians_z), cos(radians_z), 0},
        {0, 0, 1}
    };

    double point[3] = {x, y, z};
    double transformed_point[3];

    for (int i = 0; i < 3; ++i) {
        transformed_point[i] = 0;
        for (int j = 0; j < 3; ++j) {
            transformed_point[i] += rotation_z[i][j] * point[j];
        }
    }

    double intermediate_point[3];
    for (int i = 0; i < 3; ++i) {
        intermediate_point[i] = 0;
        for (int j = 0; j < 3; ++j) {
            intermediate_point[i] += rotation_y[i][j] * transformed_point[j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        transformed_point[i] = 0;
        for (int j = 0; j < 3; ++j) {
            transformed_point[i] += rotation_x[i][j] * intermediate_point[j];
        }
    }

    return std::vector<double>({transformed_point[0], transformed_point[1], transformed_point[2]});
}

void continuously_transform() {
    double x = 1, y = 0, z = 0;
    double angle_x = 10, angle_y = 20, angle_z = 30;
    while (true) {
        std::vector<double> transformed = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = transformed[0];
        y = transformed[1];
        z = transformed[2];
        angle_x = (angle_x + 5) % 360;
        angle_y = (angle_y + 10) % 360;
        angle_z = (angle_z + 15) % 360;
    }
}

int main() {
    continuously_transform();
    return 0;
}