#include <iostream>
#include <vector>
#include <string>
#include <utility>

class FlightTrajectory {
public:
    int alt;
    int speed;
    std::string dest;
    std::vector<std::pair<std::string, int>> data;

    FlightTrajectory(int alt, int speed, std::string dest) : alt(alt), speed(speed), dest(dest) {}

    void update_altitude(int new_alt) {
        alt = new_alt;
        data.push_back(std::make_pair("altitude", new_alt));
    }

    void update_speed(int new_speed) {
        speed = new_speed;
        data.push_back(std::make_pair("speed", new_speed));
    }

    void plan_cruise(int target_alt) {
        if (alt < target_alt) {
            update_altitude(target_alt);
            update_speed(speed + 10);
        } else {
            update_speed(speed - 5);
        }
    }
};

class CruisePlanner {
public:
    FlightTrajectory trajectory;

    CruisePlanner(FlightTrajectory trajectory) : trajectory(trajectory) {}

    void execute_plan(int target_alt) {
        while (trajectory.alt < target_alt) {
            trajectory.plan_cruise(target_alt);
        }
        trajectory.plan_cruise(target_alt);
    }
};

int main() {
    int initial_alt = 5000;
    int initial_speed = 300;
    std::string destination = "New York";
    FlightTrajectory trajectory(initial_alt, initial_speed, destination);
    CruisePlanner planner(trajectory);
    planner.execute_plan(35000);
    return 0;
}