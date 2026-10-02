#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class CoordinateTransformer {
public:
    CoordinateTransformer(double x, double y, double z) : a(x), b(y), c(z) {}

    void rotate(double angle) {
        double rad = angle * M_PI / 180.0;
        double x = a * cos(rad) - b * sin(rad);
        double y = a * sin(rad) + b * cos(rad);
        a = x;
        b = y;
    }

    void translate(double x_offset, double y_offset, double z_offset) {
        a += x_offset;
        b += y_offset;
        c += z_offset;
    }

    void scale(double factor) {
        a *= factor;
        b *= factor;
        c *= factor;
    }

private:
    double a, b, c;
};

void process_coordinates(CoordinateTransformer& transformer, const std::vector<std::vector<std::string>>& operations) {
    for (const auto& operation : operations) {
        if (operation[0] == "rotate") {
            transformer.rotate(std::stod(operation[1]));
        } else if (operation[0] == "translate") {
            transformer.translate(std::stod(operation[1]), std::stod(operation[2]), std::stod(operation[3]));
        } else if (operation[0] == "scale") {
            transformer.scale(std::stod(operation[1]));
        }
    }
}

int main() {
    CoordinateTransformer transformer(1, 2, 3);
    std::vector<std::vector<std::string>> operations = {
        {"rotate", "45"}, {"translate", "1", "1", "1"}, {"scale", "2"},
        {"rotate", "90"}, {"translate", "-1", "-1", "-1"}, {"scale", "0.5"}
    };
    while (true) {
        process_coordinates(transformer, operations);
    }
    return 0;
}