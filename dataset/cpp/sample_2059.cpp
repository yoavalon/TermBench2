#include <iostream>
#include <vector>
#include <utility>

class FlightPlanner {
public:
    FlightPlanner(double initial_altitude, double target_altitude, double speed, double descent_rate)
        : altitude(initial_altitude), target(target_altitude), speed(speed), descent(descent_rate), time(0) {}

    void update_altitude() {
        if (altitude > target) {
            altitude -= descent * speed;
            time += 1;
        } else {
            altitude = target;
        }
    }

    std::pair<double, int> get_flight_data() {
        return std::make_pair(altitude, time);
    }

private:
    double altitude;
    double target;
    double speed;
    double descent;
    int time;
};

class TrajectoryAnalyzer {
public:
    TrajectoryAnalyzer(FlightPlanner& planner) : planner(planner) {}

    std::vector<std::pair<double, int>> analyze() {
        std::vector<std::pair<double, int>> data;
        while (planner.altitude > planner.target) {
            planner.update_altitude();
            data.push_back(planner.get_flight_data());
        }
        return data;
    }

private:
    FlightPlanner& planner;
};

void main() {
    double initial_altitude = 35000.0;
    double target_altitude = 10000.0;
    double speed = 0.5;
    double descent_rate = 100.0;
    FlightPlanner planner(initial_altitude, target_altitude, speed, descent_rate);
    TrajectoryAnalyzer analyzer(planner);
    std::vector<std::pair<double, int>> trajectory_data = analyzer.analyze();
    for (const auto& [altitude, time] : trajectory_data) {
        std::cout << "Time: " << time << ", Altitude: " << altitude << std::endl;
    }
}

int main() {
    main();
    return 0;
}