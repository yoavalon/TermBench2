#include <stdio.h>
#include <math.h>

double rotate_point(double x, double y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    double z_new = z;
    return x_new, y_new, z_new;
}

void transform_sequence(double points[3][3], double angle) {
    double result[3][3];
    for (int i = 0; i < 3; i++) {
        double x, y, z;
        x = points[i][0];
        y = points[i][1];
        z = points[i][2];
        double x_new, y_new, z_new;
        x_new = x * cos(angle * M_PI / 180.0) - y * sin(angle * M_PI / 180.0);
        y_new = x * sin(angle * M_PI / 180.0) + y * cos(angle * M_PI / 180.0);
        z_new = z;
        result[i][0] = x_new;
        result[i][1] = y_new;
        result[i][2] = z_new;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            points[i][j] = result[i][j];
        }
    }
}

int main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 10;
    while (1) {
        transform_sequence(points, angle);
        angle += 5;
    }
    return 0;
}