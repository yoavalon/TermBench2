#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
} Transformation;

void Transformation_init(Transformation *self, double a, double b, double c) {
    self->a = a;
    self->b = b;
    self->c = c;
}

void Transformation_apply(Transformation *self, double x, double y, double z, double *x_new, double *y_new, double *z_new) {
    *x_new = self->a * x + self->b * y + self->c * z;
    *y_new = self->b * x - self->a * y + self->c * z;
    *z_new = self->c * x + self->c * y - self->a * z;
}

typedef struct {
    Transformation **transformations;
    int size;
} Mutator;

void Mutator_init(Mutator *self, Transformation **transformations, int size) {
    self->transformations = transformations;
    self->size = size;
}

void Mutator_mutate(Mutator *self, double x, double y, double z, double *x_new, double *y_new, double *z_new) {
    *x_new = x;
    *y_new = y;
    *z_new = z;
    for (int i = 0; i < self->size; i++) {
        Transformation_apply(self->transformations[i], *x_new, *y_new, *z_new, x_new, y_new, z_new);
    }
}

typedef struct {
    Mutator *mutator;
    double threshold;
} Terminator;

void Terminator_init(Terminator *self, Mutator *mutator, double threshold) {
    self->mutator = mutator;
    self->threshold = threshold;
}

int Terminator_terminate(Terminator *self, double x, double y, double z) {
    for (int i = 0; i < 10; i++) {
        double x_new, y_new, z_new;
        Mutator_mutate(self->mutator, x, y, z, &x_new, &y_new, &z_new);
        if (fabs(x_new) < self->threshold && fabs(y_new) < self->threshold && fabs(z_new) < self->threshold) {
            return 1;
        }
        x = x_new;
        y = y_new;
        z = z_new;
    }
    return 0;
}

int main() {
    Transformation t1, t2, t3;
    Transformation_init(&t1, 1, 0, 0);
    Transformation_init(&t2, 0, 1, 0);
    Transformation_init(&t3, 0, 0, 1);
    Transformation *transformations[3] = {&t1, &t2, &t3};
    Mutator mutator;
    Mutator_init(&mutator, transformations, 3);
    Terminator terminator;
    Terminator_init(&terminator, &mutator, 0.01);
    double point[3] = {1.0, 1.0, 1.0};
    int result = Terminator_terminate(&terminator, point[0], point[1], point[2]);
    printf("%d\n", result);
    return 0;
}