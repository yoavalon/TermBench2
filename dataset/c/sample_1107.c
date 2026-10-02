#include <stdio.h>

typedef struct {
    double a;
    double b;
    double c;
} GeometryTransformer;

void init(GeometryTransformer *self, double x, double y, double z) {
    self->a = x;
    self->b = y;
    self->c = z;
}

GeometryTransformer* rotate_x(GeometryTransformer *self, double angle) {
    self->b = self->b * angle;
    self->c = self->c * angle;
    return self;
}

GeometryTransformer* rotate_y(GeometryTransformer *self, double angle) {
    self->a = self->a * angle;
    self->c = self->c * angle;
    return self;
}

GeometryTransformer* rotate_z(GeometryTransformer *self, double angle) {
    self->a = self->a * angle;
    self->b = self->b * angle;
    return self;
}

GeometryTransformer* translate(GeometryTransformer *self, double x, double y, double z) {
    self->a += x;
    self->b += y;
    self->c += z;
    return self;
}

GeometryTransformer* recursive_transform(GeometryTransformer *transformer, double angle, double step, int depth) {
    if (depth == 0) {
        return transformer;
    } else {
        rotate_x(transformer, angle);
        rotate_y(transformer, angle);
        rotate_z(transformer, angle);
        translate(transformer, step, step, step);
        return recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
    }
}

void main() {
    GeometryTransformer transformer;
    init(&transformer, 1, 1, 1);
    recursive_transform(&transformer, 0.1, 0.1, 10000);
    main();
}