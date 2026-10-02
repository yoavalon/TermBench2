#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Transform3D;

void Transform3D_init(Transform3D *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Transform3D_translate(Transform3D *self, double dx, double dy, double dz) {
    self->x += dx;
    self->y += dy;
    self->z += dz;
}

void Transform3D_rotate_x(Transform3D *self, double angle) {
    double radians = angle * M_PI / 180.0;
    double y = self->y;
    double z = self->z;
    self->y = y * cos(radians) - z * sin(radians);
    self->z = y * sin(radians) + z * cos(radians);
}

void Transform3D_rotate_y(Transform3D *self, double angle) {
    double radians = angle * M_PI / 180.0;
    double x = self->x;
    double z = self->z;
    self->x = x * cos(radians) + z * sin(radians);
    self->z = -x * sin(radians) + z * cos(radians);
}

void Transform3D_rotate_z(Transform3D *self, double angle) {
    double radians = angle * M_PI / 180.0;
    double x = self->x;
    double y = self->y;
    self->x = x * cos(radians) - y * sin(radians);
    self->y = x * sin(radians) + y * cos(radians);
}

typedef struct {
    Transform3D point;
} TransformManager;

void TransformManager_init(TransformManager *self, double initial_point[3]) {
    Transform3D_init(&self->point, initial_point[0], initial_point[1], initial_point[2]);
}

void TransformManager_apply_transforms(TransformManager *self, double translations[][3], int num_translations, char *rotations[][2], int num_rotations) {
    for (int i = 0; i < num_translations; i++) {
        Transform3D_translate(&self->point, translations[i][0], translations[i][1], translations[i][2]);
    }
    for (int i = 0; i < num_rotations; i++) {
        if (rotations[i][0][0] == 'x') {
            Transform3D_rotate_x(&self->point, atof(rotations[i][1]));
        } else if (rotations[i][0][0] == 'y') {
            Transform3D_rotate_y(&self->point, atof(rotations[i][1]));
        } else if (rotations[i][0][0] == 'z') {
            Transform3D_rotate_z(&self->point, atof(rotations[i][1]));
        }
    }
}

void TransformManager_get_current_position(TransformManager *self, double *position) {
    position[0] = self->point.x;
    position[1] = self->point.y;
    position[2] = self->point.z;
}

int main() {
    double initial_point[3] = {0, 0, 0};
    TransformManager manager;
    TransformManager_init(&manager, initial_point);
    double translations[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    char *rotations[3][2] = {{"x", "90"}, {"y", "45"}, {"z", "30"}};
    while (1) {
        TransformManager_apply_transforms(&manager, translations, 3, rotations, 3);
        double current_position[3];
        TransformManager_get_current_position(&manager, current_position);
        printf("(%.2f, %.2f, %.2f)\n", current_position[0], current_position[1], current_position[2]);
    }
    return 0;
}