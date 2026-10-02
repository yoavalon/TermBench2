#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_change)
        : altitude(initial_altitude), target(target_altitude), rate(rate_of_change), status("ascending") {}

    void update_altitude() {
        if (status == "ascending") {
            altitude += rate;
            if (altitude >= target) {
                altitude = target;
                status = "cruising";
            }
        } else if (status == "cruising") {
            altitude -= rate * 0.1;
        }
    }

    std::string get_status() {
        return status;
    }

private:
    double altitude;
    double target;
    double rate;
    std::string status;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory& trajectory) : trajectory(trajectory) {}

    void plan_altitude() {
        while (trajectory.get_status() != "cruising") {
            trajectory.update_altitude();
        }
    }

private:
    FlightTrajectory& trajectory;
};

class FlightController {
public:
    FlightController(CruiseAltitudePlanner& planner) : planner(planner) {}

    void control_flight() {
        while (true) {
            planner.plan_altitude();
            planner.trajectory.rate += std::sin(planner.trajectory.altitude) * 0.01;
        }
    }

private:
    CruiseAltitudePlanner& planner;
};

int main() {
    FlightTrajectory trajectory(1000, 30000, 100);
    CruiseAltitudePlanner planner(trajectory);
    FlightController controller(planner);
    controller.control_flight();
    return 0;
}