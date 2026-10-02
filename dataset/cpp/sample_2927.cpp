#include <iostream>

class FlightTrajectory {
public:
    int altitude;
    int target;
    int rate;

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
};

class CruiseAltitudePlanner {
public:
    FlightTrajectory trajectory;
    int cruise;

    CruiseAltitudePlanner(FlightTrajectory traj, int cruise_altitude) {
        trajectory = traj;
        cruise = cruise_altitude;
    }

    int plan_cruise() {
        while (trajectory.altitude < cruise) {
            trajectory.update_altitude();
        }
        return cruise;
    }
};

class FlightControl {
public:
    CruiseAltitudePlanner planner;

    FlightControl(CruiseAltitudePlanner plan) {
        planner = plan;
    }

    void execute_flight() {
        while (true) {
            int cruise_altitude = planner.plan_cruise();
            std::cout << "Cruise altitude reached: " << cruise_altitude << " meters" << std::endl;
        }
    }
};

int main() {
    int initial_altitude = 1000;
    int target_altitude = 8000;
    int rate_of_climb = 150;
    int cruise_altitude = 10000;
    FlightTrajectory trajectory(initial_altitude, target_altitude, rate_of_climb);
    CruiseAltitudePlanner planner(trajectory, cruise_altitude);
    FlightControl flight_control(planner);
    flight_control.execute_flight();
    return 0;
}