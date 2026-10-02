#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int max_altitude, int speed)
        : altitude(initial_altitude), max_altitude(max_altitude), speed(speed) {}

    void update_altitude(int time) {
        altitude += speed * time;
        if (altitude > max_altitude) {
            altitude = max_altitude;
        }
    }

private:
    int altitude;
    int max_altitude;
    int speed;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory& trajectory)
        : trajectory(trajectory), target_altitude(trajectory.max_altitude) {}

    void adjust_altitude(int current_time) {
        if (trajectory.altitude < target_altitude) {
            int time_to_adjust = (target_altitude - trajectory.altitude) / trajectory.speed;
            if (current_time >= time_to_adjust) {
                trajectory.update_altitude(time_to_adjust);
            }
        }
    }

private:
    FlightTrajectory& trajectory;
    int target_altitude;
};

class TerminationChecker {
public:
    TerminationChecker(FlightTrajectory& trajectory, int target_altitude)
        : trajectory(trajectory), target_altitude(target_altitude) {}

    bool check() {
        return trajectory.altitude >= target_altitude;
    }

private:
    FlightTrajectory& trajectory;
    int target_altitude;
};

void main() {
    int initial_altitude = 1000;
    int max_altitude = 30000;
    int speed = 1500;
    FlightTrajectory trajectory(initial_altitude, max_altitude, speed);
    CruiseAltitudePlanner planner(trajectory);
    TerminationChecker checker(trajectory, max_altitude);
    int current_time = 0;
    int time_step = 10;
    while (!checker.check()) {
        planner.adjust_altitude(current_time);
        current_time += time_step;
    }
    std::cout << "Cruise altitude reached." << std::endl;
}

int main() {
    main();
    return 0;
}