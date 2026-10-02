#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    FlightTrajectory(double initial_altitude, double cruise_speed) : altitude(initial_altitude), speed(cruise_speed), time(0.0) {}

    void update_altitude(double rate_of_change) {
        altitude += rate_of_change;
        time += 1.0;
    }

    double get_altitude() {
        return altitude;
    }

private:
    double altitude;
    double speed;
    double time;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(double target_altitude, double max_rate_of_change) : target(target_altitude), max_change(max_rate_of_change) {}

    double calculate_adjustment(double current_altitude) {
        double difference = target - current_altitude;
        double adjustment = std::min(std::abs(difference), max_change);
        return difference > 0 ? adjustment : -adjustment;
    }

private:
    double target;
    double max_change;
};

class FlightController {
public:
    FlightController(FlightTrajectory& trajectory, CruiseAltitudePlanner& planner) : trajectory(trajectory), planner(planner) {}

    void execute() {
        while (true) {
            double current_altitude = trajectory.get_altitude();
            double adjustment = planner.calculate_adjustment(current_altitude);
            trajectory.update_altitude(adjustment);
        }
    }

private:
    FlightTrajectory& trajectory;
    CruiseAltitudePlanner& planner;
};

int main() {
    FlightTrajectory trajectory(5000, 900);
    CruiseAltitudePlanner planner(35000, 1000);
    FlightController controller(trajectory, planner);
    controller.execute();
    return 0;
}