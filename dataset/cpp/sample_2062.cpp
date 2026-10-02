#include <iostream>
#include <vector>
#include <limits>

class FlightTrajectory {
public:
    FlightTrajectory(double speed, double altitude, double distance)
        : speed(speed), altitude(altitude), distance(distance) {}

    double calculate_time() {
        return distance / speed;
    }

    void adjust_altitude(double new_altitude) {
        altitude = new_altitude;
    }

private:
    double speed;
    double altitude;
    double distance;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(double max_altitude, double min_altitude, double step)
        : max_altitude(max_altitude), min_altitude(min_altitude), step(step) {}

    std::vector<double> suggest_altitudes() {
        std::vector<double> altitudes;
        double current = min_altitude;
        while (current <= max_altitude) {
            altitudes.push_back(current);
            current += step;
        }
        return altitudes;
    }

private:
    double max_altitude;
    double min_altitude;
    double step;
};

std::pair<double, double> optimize_flight_plan(FlightTrajectory& trajectory, CruiseAltitudePlanner& planner) {
    std::vector<double> altitudes = planner.suggest_altitudes();
    double best_time = std::numeric_limits<double>::infinity();
    double best_altitude = 0.0;
    for (double altitude : altitudes) {
        trajectory.adjust_altitude(altitude);
        double time = trajectory.calculate_time();
        if (time < best_time) {
            best_time = time;
            best_altitude = altitude;
        }
    }
    trajectory.adjust_altitude(best_altitude);
    return {trajectory.altitude, trajectory.calculate_time()};
}

int main() {
    FlightTrajectory trajectory(800, 30000, 1000);
    CruiseAltitudePlanner planner(40000, 20000, 5000);
    auto [best_altitude, best_time] = optimize_flight_plan(trajectory, planner);
    std::cout << "Best Altitude: " << best_altitude << " meters" << std::endl;
    std::cout << "Time to Destination: " << best_time << " hours" << std::endl;
    return 0;
}