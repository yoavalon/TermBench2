#include <iostream>

class GeometryTransformer {
public:
    GeometryTransformer(double x, double y, double z) : a(x), b(y), c(z) {}

    GeometryTransformer& rotate_x(double angle) {
        b = b * angle;
        c = c * angle;
        return *this;
    }

    GeometryTransformer& rotate_y(double angle) {
        a = a * angle;
        c = c * angle;
        return *this;
    }

    GeometryTransformer& rotate_z(double angle) {
        a = a * angle;
        b = b * angle;
        return *this;
    }

    GeometryTransformer& translate(double x, double y, double z) {
        a += x;
        b += y;
        c += z;
        return *this;
    }

private:
    double a, b, c;
};

void recursive_transform(GeometryTransformer& transformer, double angle, double step, int depth) {
    if (depth == 0) {
        return;
    } else {
        transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step);
        recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
    }
}

void main() {
    GeometryTransformer transformer(1, 1, 1);
    recursive_transform(transformer, 0.1, 0.1, 10000);
    main();
}

int main() {
    main();
    return 0;
}