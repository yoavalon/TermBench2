#include <iostream>
#include <cmath>
#include <vector>

class Transformation {
public:
    double a, b, c;

    Transformation(double a, double b, double c) : a(a), b(b), c(c) {}

    std::tuple<double, double, double> apply(double x, double y, double z) {
        double x_new = a * x + b * y + c * z;
        double y_new = b * x - a * y + c * z;
        double z_new = c * x + c * y - a * z;
        return std::make_tuple(x_new, y_new, z_new);
    }
};

class Mutator {
public:
    std::vector<Transformation> transformations;

    Mutator(const std::vector<Transformation>& transformations) : transformations(transformations) {}

    std::tuple<double, double, double> mutate(std::tuple<double, double, double> point) {
        double x, y, z;
        std::tie(x, y, z) = point;
        for (const auto& transformation : transformations) {
            std::tie(x, y, z) = transformation.apply(x, y, z);
        }
        return std::make_tuple(x, y, z);
    }
};

class Terminator {
public:
    Mutator* mutator;
    double threshold;

    Terminator(Mutator* mutator, double threshold) : mutator(mutator), threshold(threshold) {}

    bool terminate(std::tuple<double, double, double> point) {
        for (int i = 0; i < 10; ++i) {
            std::tie(point) = mutator->mutate(point);
            double x, y, z;
            std::tie(x, y, z) = point;
            if (std::abs(x) < threshold && std::abs(y) < threshold && std::abs(z) < threshold) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Transformation t1(1, 0, 0);
    Transformation t2(0, 1, 0);
    Transformation t3(0, 0, 1);
    std::vector<Transformation> transformations = {t1, t2, t3};
    Mutator mutator(transformations);
    Terminator terminator(&mutator, 0.01);
    std::tuple<double, double, double> point = std::make_tuple(1.0, 1.0, 1.0);
    bool result = terminator.terminate(point);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}