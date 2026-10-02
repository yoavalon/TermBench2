#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class FlightPlan {
public:
    double a, b, c, d;

    FlightPlan(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    double calculate_altitude(double x) {
        return a * x * x * x + b * x * x + c * x + d;
    }
};

class TrajectoryAnalyzer {
public:
    FlightPlan plan;

    TrajectoryAnalyzer(FlightPlan plan) : plan(plan) {}

    std::vector<double> analyze(double step) {
        std::vector<double> altitudes;
        double x = 0.0;
        while (x <= 1.0) {
            altitudes.push_back(plan.calculate_altitude(x));
            x += step;
        }
        return altitudes;
    }
};

class ResultProcessor {
public:
    std::vector<double> data;

    ResultProcessor(std::vector<double> data) : data(data) {}

    std::tuple<double, double, double> process() {
        double max_altitude = *std::max_element(data.begin(), data.end());
        double min_altitude = *std::min_element(data.begin(), data.end());
        double average_altitude = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        return std::make_tuple(max_altitude, min_altitude, average_altitude);
    }
};

int main() {
    FlightPlan flight_plan(0.1, -0.5, 1.2, 300);
    TrajectoryAnalyzer analyzer(flight_plan);
    double step = 0.01;
    std::vector<double> altitudes = analyzer.analyze(step);
    ResultProcessor processor(altitudes);
    auto [max_alt, min_alt, avg_alt] = processor.process();
    std::cout << "Max Altitude: " << max_alt << ", Min Altitude: " << min_alt << ", Average Altitude: " << avg_alt << std::endl;
    return 0;
}