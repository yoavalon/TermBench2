#include <iostream>
#include <vector>
#include <cmath>

class TransformationMatrix {
public:
    TransformationMatrix(double a, double b, double c, double d, double e, double f, double g, double h, double i) :
        a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

    std::vector<double> apply(double x, double y, double z) {
        double new_x = a * x + b * y + c * z;
        double new_y = d * x + e * y + f * z;
        double new_z = g * x + h * y + i * z;
        return {new_x, new_y, new_z};
    }

private:
    double a, b, c, d, e, f, g, h, i;
};

class CoordinateTransformer {
public:
    CoordinateTransformer(TransformationMatrix matrix) : matrix(matrix) {}

    std::vector<double> transform_point(const std::vector<double>& point) {
        double x = point[0], y = point[1], z = point[2];
        return matrix.apply(x, y, z);
    }

    std::vector<std::vector<double>> transform_points(const std::vector<std::vector<double>>& points) {
        std::vector<std::vector<double>> transformed_points;
        for (const auto& p : points) {
            transformed_points.push_back(transform_point(p));
        }
        return transformed_points;
    }

private:
    TransformationMatrix matrix;
};

class GeometryAnalysis {
public:
    GeometryAnalysis(CoordinateTransformer transformer) : transformer(transformer) {}

    std::vector<double> analyze(const std::vector<std::vector<double>>& points) {
        std::vector<std::vector<double>> transformed_points = transformer.transform_points(points);
        std::vector<double> results;
        for (const auto& point : transformed_points) {
            results.push_back(calculate_distance(point));
        }
        return results;
    }

    double calculate_distance(const std::vector<double>& point) {
        double x = point[0], y = point[1], z = point[2];
        return std::sqrt(x * x + y * y + z * z);
    }

private:
    CoordinateTransformer transformer;
};

void main() {
    TransformationMatrix matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    CoordinateTransformer transformer(matrix);
    GeometryAnalysis analysis(transformer);
    std::vector<std::vector<double>> points = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<double> results = analysis.analyze(points);
    for (double result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}