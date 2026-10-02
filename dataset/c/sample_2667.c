#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

typedef struct {
    double matrix[4][4];
} Transformation;

Point apply(Transformation trans, Point point) {
    Point new_point;
    new_point.x = trans.matrix[0][0] * point.x + trans.matrix[0][1] * point.y + trans.matrix[0][2] * point.z + trans.matrix[0][3];
    new_point.y = trans.matrix[1][0] * point.x + trans.matrix[1][1] * point.y + trans.matrix[1][2] * point.z + trans.matrix[1][3];
    new_point.z = trans.matrix[2][0] * point.x + trans.matrix[2][1] * point.y + trans.matrix[2][2] * point.z + trans.matrix[2][3];
    return new_point;
}

typedef struct {
    Point start_point;
    Transformation transformation;
    int steps;
} Sequence;

Point* generate(Sequence seq, int *length) {
    Point *points = (Point *)malloc((seq.steps + 1) * sizeof(Point));
    points[0] = seq.start_point;
    Point current = seq.start_point;
    for (int i = 0; i < seq.steps; i++) {
        current = apply(seq.transformation, current);
        points[i + 1] = current;
    }
    *length = seq.steps + 1;
    return points;
}

int main() {
    Point start = {0, 0, 0};
    Transformation transform = {
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };
    Sequence seq = {start, transform, 10};
    int length;
    Point *points = generate(seq, &length);
    double distances[length - 1];
    for (int i = 0; i < length - 1; i++) {
        distances[i] = distance(points[i], points[i + 1]);
    }
    for (int i = 0; i < length - 1; i++) {
        printf("%f ", distances[i]);
    }
    printf("\n");
    free(points);
    return 0;
}