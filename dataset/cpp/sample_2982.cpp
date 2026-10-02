#include <iostream>
#include <string>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate) 
        : altitude(initial_altitude), rate_of_climb(rate_of_climb), cruise_altitude(cruise_altitude), descent_rate(descent_rate), status("climbing") {}

    void update_altitude() {
        if (status == "climbing") {
            if (altitude + rate_of_climb < cruise_altitude) {
                altitude += rate_of_climb;
            } else {
                altitude = cruise_altitude;
                status = "cruising";
            }
        } else if (status == "cruising") {
            // Do nothing
        } else if (status == "descending") {
            if (altitude - descent_rate > 0) {
                altitude -= descent_rate;
            } else {
                altitude = 0;
                status = "landed";
            }
        }
    }

    bool is_landed() {
        return status == "landed";
    }

private:
    int altitude;
    int rate_of_climb;
    int cruise_altitude;
    int descent_rate;
    std::string status;
};

class FlightPlanner {
public:
    FlightPlanner(FlightTrajectory& trajectory) : trajectory(trajectory) {}

    void plan_flight() {
        while (!trajectory.is_landed()) {
            trajectory.update_altitude();
            log_status();
        }
    }

    void log_status() {
        std::cout << "Altitude: " << trajectory.altitude << ", Status: " << trajectory.status << std::endl;
    }

private:
    FlightTrajectory& trajectory;
};

int main() {
    int initial_altitude = 0;
    int rate_of_climb = 1000;
    int cruise_altitude = 30000;
    int descent_rate = 500;
    FlightTrajectory trajectory(initial_altitude, rate_of_climb, cruise_altitude, descent_rate);
    FlightPlanner planner(trajectory);
    planner.plan_flight();
    return 0;
}