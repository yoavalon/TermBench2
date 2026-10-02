#include <iostream>
#include <cmath>

class CoordinateTransformer {
public:
    CoordinateTransformer(double angle) : angle(angle), cos_theta(std::cos(angle * M_PI / 180)), sin_theta(std::sin(angle * M_PI / 180)) {}

    std::tuple<double, double, double> transform_point(double x, double y, double z) {
        double x_prime = x * cos_theta - y * sin_theta;
        double y_prime = x * sin_theta + y * cos_theta;
        double z_prime = z;
        return std::make_tuple(x_prime, y_prime, z_prime);
    }

private:
    double angle;
    double cos_theta;
    double sin_theta;
};

class SequenceGenerator {
public:
    SequenceGenerator(std::tuple<double, double, double> initial_point, CoordinateTransformer& transformer) : point(initial_point), transformer(transformer) {}

    std::tuple<double, double, double> generate_next() {
        point = transformer.transform_point(std::get<0>(point), std::get<1>(point), std::get<2>(point));
        return point;
    }

private:
    std::tuple<double, double, double> point;
    CoordinateTransformer& transformer;
};

class ContinuousSequencePrinter {
public:
    ContinuousSequencePrinter(SequenceGenerator& sequence_generator) : sequence_generator(sequence_generator) {}

    void print_sequence() {
        while (true) {
            auto next_point = sequence_generator.generate_next();
            std::cout << std::get<0>(next_point) << ", " << std::get<1>(next_point) << ", " << std::get<2>(next_point) << std::endl;
        }
    }

private:
    SequenceGenerator& sequence_generator;
};

int main() {
    double angle = 45;
    std::tuple<double, double, double> initial_point = std::make_tuple(1, 0, 0);
    CoordinateTransformer transformer(angle);
    SequenceGenerator sequence_generator(initial_point, transformer);
    ContinuousSequencePrinter continuous_printer(sequence_generator);
    continuous_printer.print_sequence();
    return 0;
}