#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z, double *transformed_x, double *transformed_y, double *transformed_z) {
    double radians_x = angle_x * M_PI / 180;
    double radians_y = angle_y * M_PI / 180;
    double radians_z = angle_z * M_PI / 180;

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

    double temp[3];
    for (int i = 0; i < 3; i++) {
        temp[i] = 0;
        for (int j = 0; j < 3; j++) {
            temp[i] += rotation_z[i][j] * point[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        point[i] = temp[i];
    }

    for (int i = 0; i < 3; i++) {
        temp[i] = 0;
        for (int j = 0; j < 3; j++) {
            temp[i] += rotation_y[i][j] * point[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        point[i] = temp[i];
    }

    for (int i = 0; i < 3; i++) {
        temp[i] = 0;
        for (int j = 0; j < 3; j++) {
            temp[i] += rotation_x[i][j] * point[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        point[i] = temp[i];
    }

    *transformed_x = point[0];
    *transformed_y = point[1];
    *transformed_z = point[2];
}

void continuously_transform() {
    double x = 1, y = 0, z = 0;
    double angle_x = 10, angle_y = 20, angle_z = 30;
    while (1) {
        double transformed_x, transformed_y, transformed_z;
        transform_coordinates(x, y, z, angle_x, angle_y, angle_z, &transformed_x, &transformed_y, &transformed_z);
        x = transformed_x;
        y = transformed_y;
        z = transformed_z;
        angle_x = (angle_x + 5) % 360;
        angle_y = (angle_y + 10) % 360;
        angle_z = (angle_z + 15) % 360;
    }
}

int main() {
    continuously_transform();
    return 0;
}