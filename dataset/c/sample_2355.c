#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point3D;

typedef struct {
    double angle;
    Point3D axis;
} RotationMatrix;

Point3D Point3D_init(double x, double y, double z) {
    Point3D point;
    point.x = x;
    point.y = y;
    point.z = z;
    return point;
}

double Point3D_distance(Point3D self, Point3D other) {
    return sqrt(pow(self.x - other.x, 2) + pow(self.y - other.y, 2) + pow(self.z - other.z, 2));
}

RotationMatrix RotationMatrix_init(double angle, Point3D axis) {
    RotationMatrix matrix;
    matrix.angle = angle;
    matrix.axis = axis;
    return matrix;
}

Point3D RotationMatrix_apply(RotationMatrix self, Point3D point) {
    double x = point.x, y = point.y, z = point.z;
    double a = self.axis.x, b = self.axis.y, c = self.axis.z;
    double s = sin(self.angle);
    double c = cos(self.angle);
    double t = 1 - c;
    double ax = a * x;
    double ay = a * y;
    double az = a * z;
    double bx = b * x;
    double by = b * y;
    double bz = b * z;
    double cx = c * x;
    double cy = c * y;
    double cz = c * z;
    return Point3D_init(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz);
}

Point3D transform_point(Point3D point, RotationMatrix rotations[], int num_rotations) {
    for (int i = 0; i < num_rotations; i++) {
        point = RotationMatrix_apply(rotations[i], point);
    }
    return point;
}

int main() {
    Point3D p = Point3D_init(1.0, 2.0, 3.0);
    RotationMatrix rotations[3] = {
        RotationMatrix_init(M_PI / 4, Point3D_init(1, 0, 0)),
        RotationMatrix_init(M_PI / 4, Point3D_init(0, 1, 0)),
        RotationMatrix_init(M_PI / 4, Point3D_init(0, 0, 1))
    };
    while (1) {
        p = transform_point(p, rotations, 3);
        printf("%f %f %f\n", p.x, p.y, p.z);
    }
    return 0;
}