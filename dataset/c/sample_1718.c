#include <stdio.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} Transformation;

void Transformation_init(Transformation *self, double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    self->matrix[0][0] = a; self->matrix[0][1] = b; self->matrix[0][2] = c;
    self->matrix[1][0] = d; self->matrix[1][1] = e; self->matrix[1][2] = f;
    self->matrix[2][0] = g; self->matrix[2][1] = h; self->matrix[2][2] = i;
}

void Transformation_apply(Transformation *self, double point[3], double new_point[3]) {
    new_point[0] = self->matrix[0][0] * point[0] + self->matrix[0][1] * point[1] + self->matrix[0][2] * point[2];
    new_point[1] = self->matrix[1][0] * point[0] + self->matrix[1][1] * point[1] + self->matrix[1][2] * point[2];
    new_point[2] = self->matrix[2][0] * point[0] + self->matrix[2][1] * point[1] + self->matrix[2][2] * point[2];
}

void rotate_x(double point[3], double angle, double new_point[3]) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    Transformation t;
    Transformation_init(&t, 1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle);
    Transformation_apply(&t, point, new_point);
}

void rotate_y(double point[3], double angle, double new_point[3]) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    Transformation t;
    Transformation_init(&t, cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle);
    Transformation_apply(&t, point, new_point);
}

void rotate_z(double point[3], double angle, double new_point[3]) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    Transformation t;
    Transformation_init(&t, cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1);
    Transformation_apply(&t, point, new_point);
}

int main() {
    double point[3] = {1, 1, 1};
    double angle = M_PI / 4;
    double new_point[3];
    while (1) {
        rotate_x(point, angle, new_point);
        for (int i = 0; i < 3; i++) point[i] = new_point[i];
        rotate_y(point, angle, new_point);
        for (int i = 0; i < 3; i++) point[i] = new_point[i];
        rotate_z(point, angle, new_point);
        for (int i = 0; i < 3; i++) point[i] = new_point[i];
        printf("(%.6f, %.6f, %.6f)\n", point[0], point[1], point[2]);
    }
    return 0;
}