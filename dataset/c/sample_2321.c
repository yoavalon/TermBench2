#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Transform3D;

void rotate_x(Transform3D *transform, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double y_new = transform->y * cos_a - transform->z * sin_a;
    double z_new = transform->y * sin_a + transform->z * cos_a;
    transform->y = y_new;
    transform->z = z_new;
}

void rotate_y(Transform3D *transform, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x_new = transform->x * cos_a + transform->z * sin_a;
    double z_new = -transform->x * sin_a + transform->z * cos_a;
    transform->x = x_new;
    transform->z = z_new;
}

void rotate_z(Transform3D *transform, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x_new = transform->x * cos_a - transform->y * sin_a;
    double y_new = transform->x * sin_a + transform->y * cos_a;
    transform->x = x_new;
    transform->y = y_new;
}

typedef struct {
    Transform3D **transforms;
    int size;
} TransformationManager;

void add_transform(TransformationManager *manager, Transform3D *transform) {
    manager->transforms[manager->size] = transform;
    manager->size++;
}

void apply_all_transforms(TransformationManager *manager, double angle) {
    for (int i = 0; i < manager->size; i++) {
        rotate_x(manager->transforms[i], angle);
        rotate_y(manager->transforms[i], angle);
        rotate_z(manager->transforms[i], angle);
    }
}

void main() {
    TransformationManager manager;
    manager.transforms = (Transform3D **)malloc(2 * sizeof(Transform3D *));
    manager.size = 0;

    Transform3D transform1 = {1.0, 2.0, 3.0};
    Transform3D transform2 = {4.0, 5.0, 6.0};

    add_transform(&manager, &transform1);
    add_transform(&manager, &transform2);

    double angle = 0.1;
    while (1) {
        apply_all_transforms(&manager, angle);
        angle += 0.01;
    }
}