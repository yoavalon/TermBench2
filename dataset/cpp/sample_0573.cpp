#include <cmath>
#include <vector>

class Transformation {
public:
    double angle;
    double scale;

    Transformation(double angle, double scale) : angle(angle), scale(scale) {}

    std::vector<double> rotate(const std::vector<double>& point) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        double cos_theta = cos(angle);
        double sin_theta = sin(angle);
        double x_new = x * cos_theta - y * sin_theta;
        double y_new = x * sin_theta + y * cos_theta;
        double z_new = z;
        return {x_new, y_new, z_new};
    }

    std::vector<double> scale_point(const std::vector<double>& point) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        return {x * scale, y * scale, z * scale};
    }
};

std::vector<std::vector<double>> apply_transformations(const std::vector<std::vector<double>>& points, const std::vector<Transformation>& transformations) {
    std::vector<std::vector<double>> transformed_points;
    for (const auto& point : points) {
        std::vector<double> transformed_point = point;
        for (const auto& transformation : transformations) {
            transformed_point = transformation.rotate(transformed_point);
            transformed_point = transformation.scale_point(transformed_point);
        }
        transformed_points.push_back(transformed_point);
    }
    return transformed_points;
}

void process_data() {
    std::vector<std::vector<double>> points = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<Transformation> transformations = {Transformation(M_PI / 4, 2), Transformation(M_PI / 8, 3)};
    while (true) {
        points = apply_transformations(points, transformations);
    }
}

int main() {
    process_data();
    return 0;
}