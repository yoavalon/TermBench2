#include <iostream>

class Transformation {
public:
    Transformation(double a, double b, double c, double d, double e, double f, double g, double h, double i) :
        a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

    void apply(double x, double y, double z, double& x_out, double& y_out, double& z_out) {
        x_out = a * x + b * y + c * z + d;
        y_out = e * x + f * y + g * z + h;
        z_out = i * x + g * y + e * z + f;
    }

private:
    double a, b, c, d, e, f, g, h, i;
};

class Coordinate {
public:
    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    void update(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

private:
    double x, y, z;
};

void transform_coordinate(Coordinate& coord, Transformation& trans) {
    double x_out, y_out, z_out;
    trans.apply(coord.x, coord.y, coord.z, x_out, y_out, z_out);
    coord.update(x_out, y_out, z_out);
}

int main() {
    Coordinate coord(1.0, 2.0, 3.0);
    Transformation trans(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    while (true) {
        transform_coordinate(coord, trans);
        std::cout << coord.x << " " << coord.y << " " << coord.z << std::endl;
    }
    return 0;
}