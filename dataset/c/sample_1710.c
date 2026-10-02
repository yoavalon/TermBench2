#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, z;
} Point;

typedef struct {
    Point* points;
    int point_count;
    Point* transformations;
    int transformation_count;
} CoordinateTransformer;

CoordinateTransformer* CoordinateTransformer_new() {
    CoordinateTransformer* transformer = (CoordinateTransformer*)malloc(sizeof(CoordinateTransformer));
    transformer->points = NULL;
    transformer->point_count = 0;
    transformer->transformations = NULL;
    transformer->transformation_count = 0;
    return transformer;
}

void CoordinateTransformer_add_point(CoordinateTransformer* transformer, double x, double y, double z) {
    transformer->points = (Point*)realloc(transformer->points, (transformer->point_count + 1) * sizeof(Point));
    transformer->points[transformer->point_count].x = x;
    transformer->points[transformer->point_count].y = y;
    transformer->points[transformer->point_count].z = z;
    transformer->point_count++;
}

void CoordinateTransformer_apply_rotation(CoordinateTransformer* transformer, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    double rotation_matrix[3][3] = {
        {cos_y * cos_z, cos_y * sin_z, -sin_y},
        {sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y},
        {cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y}
    };
    Point* new_points = (Point*)malloc(transformer->point_count * sizeof(Point));
    for (int i = 0; i < transformer->point_count; i++) {
        new_points[i].x = rotation_matrix[0][0] * transformer->points[i].x + rotation_matrix[0][1] * transformer->points[i].y + rotation_matrix[0][2] * transformer->points[i].z;
        new_points[i].y = rotation_matrix[1][0] * transformer->points[i].x + rotation_matrix[1][1] * transformer->points[i].y + rotation_matrix[1][2] * transformer->points[i].z;
        new_points[i].z = rotation_matrix[2][0] * transformer->points[i].x + rotation_matrix[2][1] * transformer->points[i].y + rotation_matrix[2][2] * transformer->points[i].z;
    }
    free(transformer->points);
    transformer->points = new_points;
}

void CoordinateTransformer_apply_translation(CoordinateTransformer* transformer, double dx, double dy, double dz) {
    Point* new_points = (Point*)malloc(transformer->point_count * sizeof(Point));
    for (int i = 0; i < transformer->point_count; i++) {
        new_points[i].x = transformer->points[i].x + dx;
        new_points[i].y = transformer->points[i].y + dy;
        new_points[i].z = transformer->points[i].z + dz;
    }
    free(transformer->points);
    transformer->points = new_points;
}

Point* generate_points(int* count) {
    Point* points = (Point*)malloc(100 * sizeof(Point));
    for (int i = 0; i < 100; i++) {
        points[i].x = ((double)rand() / RAND_MAX) * 20 - 10;
        points[i].y = ((double)rand() / RAND_MAX) * 20 - 10;
        points[i].z = ((double)rand() / RAND_MAX) * 20 - 10;
    }
    *count = 100;
    return points;
}

void main() {
    CoordinateTransformer* transformer = CoordinateTransformer_new();
    int point_count;
    Point* points = generate_points(&point_count);
    for (int i = 0; i < point_count; i++) {
        CoordinateTransformer_add_point(transformer, points[i].x, points[i].y, points[i].z);
    }
    CoordinateTransformer_apply_rotation(transformer, 0.5, 0.3, 0.2);
    CoordinateTransformer_apply_translation(transformer, 5, 5, 5);
    while (1) {
        CoordinateTransformer_apply_rotation(transformer, 0.01, 0.02, 0.03);
        CoordinateTransformer_apply_translation(transformer, 0.1, 0.1, 0.1);
    }
}