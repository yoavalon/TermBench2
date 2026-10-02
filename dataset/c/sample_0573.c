c
#include <math.h>
#include <stdlib.h>

typedef struct {
    double angle;
    double scale;
} Transformation;

Transformation* Transformation_new(double angle, double scale) {
    Transformation* self = malloc(sizeof(Transformation));
    self->angle = angle;
    self->scale = scale;
    return self;
}

void Transformation_free(Transformation* self) {
    free(self);
}

double* Transformation_rotate(Transformation* self, double* point) {
    double x = point[0];
    double y = point[1];
    double z = point[2];
    double cos_theta = cos(self->angle);
    double sin_theta = sin(self->angle);
    double x_new = x * cos_theta - y * sin_theta;
    double y_new = x * sin_theta + y * cos_theta;
    double z_new = z;
    double* new_point = malloc(3 * sizeof(double));
    new_point[0] = x_new;
    new_point[1] = y_new;
    new_point[2] = z_new;
    return new_point;
}

double* Transformation_scale_point(Transformation* self, double* point) {
    double x = point[0];
    double y = point[1];
    double z = point[2];
    double* new_point = malloc(3 * sizeof(double));
    new_point[0] = x * self->scale;
    new_point[1] = y * self->scale;
    new_point[2] = z * self->scale;
    return new_point;
}

double** apply_transformations(double** points, int num_points, Transformation** transformations, int num_transformations) {
    double** transformed_points = malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        double* point = points[i];
        for (int j = 0; j < num_transformations; j++) {
            Transformation* transformation = transformations[j];
            double* new_point = transformation->rotate(transformation, point);
            free(point);
            point = transformation->scale_point(transformation, new_point);
            free(new_point);
        }
        transformed_points[i] = point;
    }
    return transformed_points;
}

void process_data() {
    double* points[] = {(double[3]){1, 0, 0}, (double[3]){0, 1, 0}, (double[3]){0, 0, 1}};
    Transformation* transformations[] = {Transformation_new(M_PI / 4, 2), Transformation_new(M_PI / 8, 3)};
    while (1) {
        points = apply_transformations(points, 3, transformations, 2);
    }
}

int main() {
    process_data();
    return 0;
}