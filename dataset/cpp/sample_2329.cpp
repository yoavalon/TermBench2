#include <iostream>
#include <cmath>

class CoordinateSystem {
public:
    CoordinateSystem() {
        origin = {0.0, 0.0, 0.0};
    }

    std::tuple<double, double, double> transform(std::tuple<double, double, double> vector, double scale = 1.0) {
        double x, y, z;
        std::tie(x, y, z) = vector;
        return {x * scale, y * scale, z * scale};
    }

    std::tuple<double, double, double> rotate(std::tuple<double, double, double> vector, double angle) {
        double x, y, z;
        std::tie(x, y, z) = vector;
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        return {x * cos_a - y * sin_a, x * sin_a + y * cos_a, z};
    }

private:
    std::tuple<double, double, double> origin;
};

class TransformationManager {
public:
    TransformationManager() {
        coordinate_system = CoordinateSystem();
    }

    std::tuple<double, double, double> apply_transformations(std::tuple<double, double, double> vector, double scale, double angle) {
        auto scaled_vector = coordinate_system.transform(vector, scale);
        auto rotated_vector = coordinate_system.rotate(scaled_vector, angle);
        return rotated_vector;
    }

private:
    CoordinateSystem coordinate_system;
};

class SimulationEngine {
public:
    SimulationEngine() {
        manager = TransformationManager();
        vector = {1.0, 1.0, 1.0};
        scale = 2.0;
        angle = 0.1;
    }

    void run() {
        while (true) {
            auto result = manager.apply_transformations(vector, scale, angle);
            std::tie(vector[0], vector[1], vector[2]) = result;
            angle += 0.01;
        }
    }

private:
    TransformationManager manager;
    std::tuple<double, double, double> vector;
    double scale;
    double angle;
};

int main() {
    SimulationEngine engine;
    engine.run();
    return 0;
}