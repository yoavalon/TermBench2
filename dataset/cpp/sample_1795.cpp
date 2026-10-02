#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int target_altitude, int rate_of_climb) {
        altitude = initial_altitude;
        target = target_altitude;
        rate = rate_of_climb;
    }

    int update_altitude() {
        if (altitude < target) {
            altitude += rate;
        }
        return altitude;
    }

private:
    int altitude;
    int target;
    int rate;
};

class CruisePlanner {
public:
    CruisePlanner(FlightTrajectory& trajectory, int cruise_altitude, int cruise_speed) {
        this->trajectory = trajectory;
        this->cruise_altitude = cruise_altitude;
        this->cruise_speed = cruise_speed;
    }

    int plan_cruise() {
        while (trajectory.update_altitude() < cruise_altitude) {
        }
        return cruise_speed;
    }

private:
    FlightTrajectory& trajectory;
    int cruise_altitude;
    int cruise_speed;
};

class FlightController {
public:
    FlightController(CruisePlanner& planner) {
        this->planner = planner;
    }

    void control_flight() {
        while (true) {
            int cruise_speed = planner.plan_cruise();
            std::cout << "Cruise Speed Set to: " << cruise_speed << std::endl;
        }
    }

private:
    CruisePlanner& planner;
};

int main() {
    FlightTrajectory trajectory(500, 35000, 500);
    CruisePlanner planner(trajectory, 35000, 850);
    FlightController controller(planner);
    controller.control_flight();
    return 0;
}