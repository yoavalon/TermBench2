#include <stdio.h>
#include <math.h>

typedef struct {
    double a, b, c;
    double d, e, f;
    double g, h, i;
} TransformationMatrix;

typedef struct {
    TransformationMatrix matrix;
} CoordinateTransformer;

typedef struct {
    CoordinateTransformer transformer;
} GeometryAnalysis;

void TransformationMatrix_init(TransformationMatrix *self, double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    self->a = a; self->b = b; self->c = c;
    self->d = d; self->e = e; self->f = f;
    self->g = g; self->h = h; self->i = i;
}

void TransformationMatrix_apply(const TransformationMatrix *self, double x, double y, double z, double *new_x, double *new_y, double *new_z) {
    *new_x = self->a * x + self->b * y + self->c * z;
    *new_y = self->d * x + self->e * y + self->f * z;
    *new_z = self->g * x + self->h * y + self->i * z;
}

void CoordinateTransformer_init(CoordinateTransformer *self, const TransformationMatrix *matrix) {
    self->matrix = *matrix;
}

void CoordinateTransformer_transform_point(const CoordinateTransformer *self, double x, double y, double z, double *new_x, double *new_y, double *new_z) {
    TransformationMatrix_apply(&self->matrix, x, y, z, new_x, new_y, new_z);
}

void CoordinateTransformer_transform_points(const CoordinateTransformer *self, const double points[][3], double results[][3], int num_points) {
    for (int i = 0; i < num_points; i++) {
        CoordinateTransformer_transform_point(self, points[i][0], points[i][1], points[i][2], &results[i][0], &results[i][1], &results[i][2]);
    }
}

void GeometryAnalysis_init(GeometryAnalysis *self, const CoordinateTransformer *transformer) {
    self->transformer = *transformer;
}

double GeometryAnalysis_calculate_distance(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

void GeometryAnalysis_analyze(const GeometryAnalysis *self, const double points[][3], double results[], int num_points) {
    double transformed_points[num_points][3];
    CoordinateTransformer_transform_points(&self->transformer, points, transformed_points, num_points);
    for (int i = 0; i < num_points; i++) {
        results[i] = GeometryAnalysis_calculate_distance(transformed_points[i][0], transformed_points[i][1], transformed_points[i][2]);
    }
}

int main() {
    TransformationMatrix matrix;
    TransformationMatrix_init(&matrix, 1, 0, 0, 0, 1, 0, 0, 0, 1);
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, &matrix);
    GeometryAnalysis analysis;
    GeometryAnalysis_init(&analysis, &transformer);
    double points[][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double results[3];
    GeometryAnalysis_analyze(&analysis, points, results, 3);
    for (int i = 0; i < 3; i++) {
        printf("%f\n", results[i]);
    }
    return 0;
}