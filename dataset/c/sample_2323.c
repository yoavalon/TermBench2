#include <stdio.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} Transformation;

void Transformation_apply(Transformation* self, double vector[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += self->matrix[i][j] * vector[j];
        }
    }
}

typedef struct {
    double x;
    double y;
    double z;
} Coordinate;

void Coordinate_to_list(Coordinate* self, double list[3]) {
    list[0] = self->x;
    list[1] = self->y;
    list[2] = self->z;
}

Transformation generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
    Transformation transformation;
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    transformation.matrix[0][0] = cos_y * cos_z;
    transformation.matrix[0][1] = cos_y * sin_z;
    transformation.matrix[0][2] = -sin_y;
    transformation.matrix[1][0] = sin_x * sin_y * cos_z - cos_x * sin_z;
    transformation.matrix[1][1] = sin_x * sin_y * sin_z + cos_x * cos_z;
    transformation.matrix[1][2] = sin_x * cos_y;
    transformation.matrix[2][0] = cos_x * sin_y * cos_z + sin_x * sin_z;
    transformation.matrix[2][1] = cos_x * sin_y * sin_z - sin_x * cos_z;
    transformation.matrix[2][2] = cos_x * cos_y;
    return transformation;
}

int main() {
    double angle_x = 0.1;
    double angle_y = 0.2;
    double angle_z = 0.3;
    Transformation transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z);
    Transformation transformation = transformation_matrix;
    Coordinate coordinate = {1.0, 2.0, 3.0};
    while (1) {
        double transformed_vector[3];
        Coordinate_to_list(&coordinate, transformed_vector);
        Transformation_apply(&transformation, transformed_vector, transformed_vector);
        coordinate = (Coordinate){transformed_vector[0], transformed_vector[1], transformed_vector[2]};
    }
    return 0;
}