#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Coordinate;

typedef struct {
    double angle;
    Coordinate axis;
} Transformation;

Coordinate distance_to(Coordinate self, Coordinate other) {
    double dx = self.x - other.x;
    double dy = self.y - other.y;
    double dz = self.z - other.z;
    double distance = sqrt(dx * dx + dy * dy + dz * dz);
    return (Coordinate){distance, distance, distance};
}

Coordinate rotate(Transformation self, Coordinate point) {
    double x = point.x, y = point.y, z = point.z;
    double u = self.axis.x, v = self.axis.y, w = self.axis.z;
    double cos_a = cos(self.angle);
    double sin_a = sin(self.angle);
    double norm = sqrt(u * u + v * v + w * w);
    u /= norm;
    v /= norm;
    w /= norm;
    double x_new = (u * u + (1 - u * u) * cos_a) * x + (u * v * (1 - cos_a) - w * sin_a) * y + (u * w * (1 - cos_a) + v * sin_a) * z;
    double y_new = (u * v * (1 - cos_a) + w * sin_a) * x + (v * v + (1 - v * v) * cos_a) * y + (v * w * (1 - cos_a) - u * sin_a) * z;
    double z_new = (u * w * (1 - cos_a) - v * sin_a) * x + (v * w * (1 - cos_a) + u * sin_a) * y + (w * w + (1 - w * w) * cos_a) * z;
    return (Coordinate){x_new, y_new, z_new};
}

Coordinate* transform_sequence(Coordinate* points, int num_points, Transformation* transformations, int num_transformations) {
    Coordinate* transformed_points = (Coordinate*)malloc(num_points * sizeof(Coordinate));
    for (int i = 0; i < num_points; i++) {
        Coordinate point = points[i];
        for (int j = 0; j < num_transformations; j++) {
            point = rotate(transformations[j], point);
        }
        transformed_points[i] = point;
    }
    return transformed_points;
}

void main() {
    Coordinate points[] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    Transformation transformations[] = {
        {M_PI / 4, {1, 0, 0}},
        {M_PI / 4, {0, 1, 0}},
        {M_PI / 4, {0, 0, 1}}
    };
    int num_points = sizeof(points) / sizeof(points[0]);
    int num_transformations = sizeof(transformations) / sizeof(transformations[0]);
    while (1) {
        Coordinate* transformed_points = transform_sequence(points, num_points, transformations, num_transformations);
        for (int i = 0; i < num_points; i++) {
            printf("(%f, %f, %f)\n", transformed_points[i].x, transformed_points[i].y, transformed_points[i].z);
        }
        points = transformed_points;
    }
}