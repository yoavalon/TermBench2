#include <iostream>
#include <vector>

class Transformation {
public:
    Transformation(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    std::vector<double> apply(const std::vector<double>& point) {
        double x = point[0], y = point[1], z = point[2];
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        return {new_x, new_y, new_z};
    }

private:
    std::vector<std::vector<double>> matrix;
};

class Point {
public:
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    Point transform(const std::vector<std::vector<double>>& matrix) {
        Transformation transformation(matrix);
        std::vector<double> transformed = transformation.apply({x, y, z});
        return Point(transformed[0], transformed[1], transformed[2]);
    }

    double x, y, z;
};

Point recursive_transform(const Point& point, const std::vector<std::vector<double>>& matrix, int depth) {
    if (depth == 0) {
        return point;
    } else {
        Point new_point = point.transform(matrix);
        return recursive_transform(new_point, matrix, depth - 1);
    }
}

void main() {
    std::vector<std::vector<double>> matrix = {{1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    Point initial_point(0, 0, 0);
    int depth = 5;
    Point result = recursive_transform(initial_point, matrix, depth);
    std::cout << "Transformed point: (" << result.x << ", " << result.y << ", " << result.z << ")" << std::endl;
}

int main() {
    main();
    return 0;
}