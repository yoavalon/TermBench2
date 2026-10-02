#include <iostream>
#include <cmath>

class FlightParameters {
public:
    double speed;
    double altitude;
    double heading;
    double wind_speed;
    double wind_heading;

    FlightParameters(double speed, double altitude, double heading, double wind_speed, double wind_heading) {
        this->speed = speed;
        this->altitude = altitude;
        this->heading = heading;
        this->wind_speed = wind_speed;
        this->wind_heading = wind_heading;
    }

    std::pair<double, double> calculate_drift() {
        double angle_diff = wind_heading - heading;
        double drift_x = wind_speed * std::abs(angle_diff) / 360;
        double drift_y = wind_speed * std::abs(90 - angle_diff) / 360;
        return {drift_x, drift_y};
    }
};

class TrajectoryPlanner {
public:
    FlightParameters parameters;

    TrajectoryPlanner(FlightParameters parameters) {
        this->parameters = parameters;
    }

    double adjust_altitude(double target_altitude) {
        double current_alt = parameters.altitude;
        if (current_alt < target_altitude) {
            return current_alt + 100;
        } else if (current_alt > target_altitude) {
            return current_alt - 50;
        }
        return current_alt;
    }

    std::pair<double, double> plan_trajectory(double target_x, double target_y) {
        auto [drift_x, drift_y] = parameters.calculate_drift();
        double adjusted_x = target_x - drift_x;
        double adjusted_y = target_y - drift_y;
        return {adjusted_x, adjusted_y};
    }
};

class CruiseControl {
public:
    TrajectoryPlanner planner;

    CruiseControl(TrajectoryPlanner planner) {
        this->planner = planner;
    }

    void execute() {
        double target_x = 1000;
        double target_y = 2000;
        double target_altitude = 30000;
        while (true) {
            planner.parameters.altitude = planner.adjust_altitude(target_altitude);
            auto [x, y] = planner.plan_trajectory(target_x, target_y);
            std::cout << "Current Coordinates: (" << x << ", " << y << "), Altitude: " << planner.parameters.altitude << std::endl;
        }
    }
};

int main() {
    FlightParameters params(500, 25000, 45, 20, 90);
    TrajectoryPlanner planner(params);
    CruiseControl cruise_control(planner);
    cruise_control.execute();
    return 0;
}