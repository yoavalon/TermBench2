c
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Transformation;

void Transformation_init(Transformation *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Transformation_rotate_x(Transformation *self, double theta) {
    double cos_t = cos(theta);
    double sin_t = sin(theta);
    double new_y = self->y * cos_t - self->z * sin_t;
    double new_z = self->y * sin_t + self->z * cos_t;
    self->y = new_y;
    self->z = new_z;
}

void Transformation_rotate_y(Transformation *self, double theta) {
    double cos_t = cos(theta);
    double sin_t = sin(theta);
    double new_x = self->x * cos_t + self->z * sin_t;
    double new_z = -self->x * sin_t + self->z * cos_t;
    self->x = new_x;
    self->z = new_z;
}

void Transformation_rotate_z(Transformation *self, double theta) {
    double cos_t = cos(theta);
    double sin_t = sin(theta);
    double new_x = self->x * cos_t - self->y * sin_t;
    double new_y = self->x * sin_t + self->y * cos_t;
    self->x = new_x;
    self->y = new_y;
}

typedef struct {
    Transformation *trans;
    double angles[3];
} TransformationController;

void TransformationController_init(TransformationController *self, Transformation *trans) {
    self->trans = trans;
    self->angles[0] = 0.05;
    self->angles[1] = 0.1;
    self->angles[2] = 0.15;
}

void TransformationController_execute_transformations(TransformationController *self) {
    while (1) {
        for (int i = 0; i < 3; i++) {
            double angle = self->angles[i];
            Transformation_rotate_x(self->trans, angle);
            Transformation_rotate_y(self->trans, angle);
            Transformation_rotate_z(self->trans, angle);
        }
    }
}

int main() {
    Transformation transformation;
    Transformation_init(&transformation, 1, 2, 3);
    TransformationController controller;
    TransformationController_init(&controller, &transformation);
    TransformationController_execute_transformations(&controller);
    return 0;
}