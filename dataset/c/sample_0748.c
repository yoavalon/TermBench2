#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;

Point transform_point(int x, int y, int z, int n) {
    if (n == 0) {
        return (Point){x, y, z};
    } else {
        x += 1;
        y += 2;
        z += 3;
        return transform_point(x, y, z, n - 1);
    }
}

Point* apply_transformations(Point* points, int count, int n) {
    if (count == 0) {
        return NULL;
    } else {
        Point transformed_point = transform_point(points[0].x, points[0].y, points[0].z, n);
        Point* result = (Point*)malloc(count * sizeof(Point));
        result[0] = transformed_point;
        for (int i = 1; i < count; i++) {
            result[i] = points[i];
        }
        return result;
    }
}

void print_points(Point* points, int count) {
    printf("[");
    for (int i = 0; i < count; i++) {
        printf("(%d, %d, %d)", points[i].x, points[i].y, points[i].z);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Point points[] = {{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    int n = 3;
    int count = sizeof(points) / sizeof(points[0]);
    Point* result = apply_transformations(points, count, n);
    print_points(result, count);
    free(result);
    return 0;
}