#include <iostream>
#include <vector>

std::vector<double> transform_3d_coords(const std::vector<double>& coords, const std::vector<std::vector<double>>& mat) {

    double mul(const std::vector<double>& v1, const std::vector<double>& v2) {
        double sum = 0;
        for (size_t i = 0; i < v1.size(); ++i) {
            sum += v1[i] * v2[i];
        }
        return sum;
    }

    std::vector<double> row_mul(const std::vector<double>& row, const std::vector<double>& vec) {
        std::vector<double> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = mul(row, vec);
        }
        return result;
    }

    std::vector<std::vector<double>> result;
    for (const auto& m : mat) {
        result.push_back(row_mul(m, coords));
    }
    return result;
}

int main() {
    std::vector<double> coords = {1, 2, 3};
    std::vector<std::vector<double>> mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<double>> result = transform_3d_coords(coords, mat);

    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}