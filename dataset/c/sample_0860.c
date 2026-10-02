#include <stdio.h>

typedef struct {
    double matrix[4][4];
} Transformation;

typedef struct {
    double x;
    double y;
    double z;
} Point;

void Transformation_init(Transformation *self, double matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            self->matrix[i][j] = matrix[i][j];
        }
    }
}

Point Transformation_apply(Transformation *self, Point point) {
    double new_x = self->matrix[0][0] * point.x + self->matrix[0][1] * point.y + self->matrix[0][2] * point.z + self->matrix[0][3];
    double new_y = self->matrix[1][0] * point.x + self->matrix[1][1] * point.y + self->matrix[1][2] * point.z + self->matrix[1][3];
    double new_z = self->matrix[2][0] * point.x + self->matrix[2][1] * point.y + self->matrix[2][2] * point.z + self->matrix[2][3];
    return (Point){new_x, new_y, new_z};
}

void Point_init(Point *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

Point Point_transform(Point point, Transformation *matrix) {
    return Transformation_apply(matrix, point);
}

Point recursive_transform(Point point, Transformation *matrix, int depth) {
    if (depth == 0) {
        return point;
    } else {
        Point new_point = Point_transform(point, matrix);
        return recursive_transform(new_point, matrix, depth - 1);
    }
}

int main() {
    double matrix[4][4] = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    Point initial_point;
    Point_init(&initial_point, 0, 0, 0);
    int depth = 5;
    Point result = recursive_transform(initial_point, (Transformation *)matrix, depth);
    printf("Transformed point: (%f, %f, %f)\n", result.x, result.y, result.z);
    return 0;
}