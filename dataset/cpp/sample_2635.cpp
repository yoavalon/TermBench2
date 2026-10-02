#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double rotationMatrix[3][3];
double transformationMatrix[4][4];

void transform_matrix(const vector<double>& rotation, const vector<double>& translation) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transformationMatrix[i][j] = rotation[i * 3 + j];
        }
        transformationMatrix[i][3] = translation[i];
    }
    transformationMatrix[3][0] = 0;
    transformationMatrix[3][1] = 0;
    transformationMatrix[3][2] = 0;
    transformationMatrix[3][3] = 1;
}

vector<double> apply_transformation(const vector<vector<double>>& points, const double matrix[4][4]) {
    vector<vector<double>> homogeneous_points;
    vector<double> transformed_points;

    for (const auto& point : points) {
        vector<double> homogenized_point = {point[0], point[1], point[2], 1};
        homogeneous_points.push_back(homogenized_point);
    }

    for (const auto& homogenized_point : homogeneous_points) {
        double x = 0, y = 0, z = 0, w = 0;
        for (int i = 0; i < 4; ++i) {
            x += homogenized_point[i] * matrix[0][i];
            y += homogenized_point[i] * matrix[1][i];
            z += homogenized_point[i] * matrix[2][i];
            w += homogenized_point[i] * matrix[3][i];
        }
        transformed_points.push_back(x / w);
        transformed_points.push_back(y / w);
        transformed_points.push_back(z / w);
    }

    return transformed_points;
}

vector<vector<double>> generate_sequence(int n, const vector<double>& initial_point, double angle, const vector<double>& axis) {
    vector<vector<double>> sequence = {initial_point};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rotationMatrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int _ = 0; _ < n; ++_) {
        double cos = cos(angle);
        double sin = sin(angle);
        double norm = sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
        double ux = axis[0] / norm;
        double uy = axis[1] / norm;
        double uz = axis[2] / norm;

        double newRotationMatrix[3][3] = {
            {cos + ux * ux * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin},
            {uy * ux * (1 - cos) + uz * sin, cos + uy * uy * (1 - cos), uy * uz * (1 - cos) - ux * sin},
            {uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz * uz * (1 - cos)}
        };

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                double sum = 0;
                for (int k = 0; k < 3; ++k) {
                    sum += newRotationMatrix[i][k] * rotationMatrix[k][j];
                }
                rotationMatrix[i][j] = sum;
            }
        }

        vector<double> transformed_point = apply_transformation({initial_point}, rotationMatrix);
        sequence.push_back(transformed_point);
    }

    return sequence;
}

void rotate_around_axis(double matrix[3][3], double angle, const vector<double>& axis) {
    double cos = cos(angle);
    double sin = sin(angle);
    double norm = sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
    double ux = axis[0] / norm;
    double uy = axis[1] / norm;
    double uz = axis[2] / norm;

    double newRotationMatrix[3][3] = {
        {cos + ux * ux * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin},
        {uy * ux * (1 - cos) + uz * sin, cos + uy * uy * (1 - cos), uy * uz * (1 - cos) - ux * sin},
        {uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz * uz * (1 - cos)}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            double sum = 0;
            for (int k = 0; k < 3; ++k) {
                sum += newRotationMatrix[i][k] * matrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
}

int main() {
    vector<double> initial_point = {1, 0, 0};
    double angle = M_PI / 4;
    vector<double> axis = {0, 0, 1};
    int n = 10;
    vector<vector<double>> sequence = generate_sequence(n, initial_point, angle, axis);

    for (const auto& point : sequence) {
        cout << "[" << point[0] << ", " << point[1] << ", " << point[2] << "]" << endl;
    }

    return 0;
}