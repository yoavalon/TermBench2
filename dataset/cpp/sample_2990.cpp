#include <iostream>
#include <cmath>
#include <iterator>
#include <array>

class CoordinateTransformer {
public:
    CoordinateTransformer(double x, double y, double z) : a(x), b(y), c(z) {}

    void rotate_x(double angle) {
        double cos = std::cos(angle);
        double sin = std::sin(angle);
        std::swap(b, cos * b - sin * c);
        std::swap(c, sin * b + cos * c);
    }

    void rotate_y(double angle) {
        double cos = std::cos(angle);
        double sin = std::sin(angle);
        std::swap(a, cos * a + sin * c);
        std::swap(c, -sin * a + cos * c);
    }

    void rotate_z(double angle) {
        double cos = std::cos(angle);
        double sin = std::sin(angle);
        std::swap(a, cos * a - sin * b);
        std::swap(b, sin * a + cos * b);
    }

    void scale(double factor) {
        a *= factor;
        b *= factor;
        c *= factor;
    }

    void translate(double dx, double dy, double dz) {
        a += dx;
        b += dy;
        c += dz;
    }

    std::array<double, 3> get_coordinates() const {
        return {a, b, c};
    }

private:
    double a, b, c;
};

void transform_sequence() {
    CoordinateTransformer transformer(1, 0, 0);
    std::array<double, 3> angles = {M_PI / 4, M_PI / 3, M_PI / 6};
    std::array<double, 3> factors = {1.1, 0.9, 1.2};
    std::array<std::array<double, 3>, 3> translations = {
        {{1, 2, 3}}, {{-1, -2, -3}}, {{0, 0, 0}}
    };

    auto angle_it = angles.begin();
    auto factor_it = factors.begin();
    auto translation_it = translations.begin();

    while (true) {
        double angle = *angle_it;
        double factor = *factor_it;
        double dx = translation_it->at(0);
        double dy = translation_it->at(1);
        double dz = translation_it->at(2);

        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(factor);
        transformer.translate(dx, dy, dz);

        auto coordinates = transformer.get_coordinates();
        std::cout << "Coordinates: (" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ")\n";

        angle_it = (angle_it + 1) % angles.end();
        factor_it = (factor_it + 1) % factors.end();
        translation_it = (translation_it + 1) % translations.end();
    }
}

int main() {
    transform_sequence();
    return 0;
}