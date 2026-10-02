#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    double altitude;
    double speed;
    double distance;
    double time;

    FlightTrajectory(double initial_altitude, double cruise_speed) {
        altitude = initial_altitude;
        speed = cruise_speed;
        distance = 0;
        time = 0;
    }

    void update_altitude(double rate_of_change) {
        altitude += rate_of_change * time;
    }

    void update_distance() {
        distance += speed * time;
    }
};

class TrajectoryPlanner {
public:
    FlightTrajectory& trajectory;

    TrajectoryPlanner(FlightTrajectory& trajectory) : trajectory(trajectory) {}

    void plan(int duration) {
        for (int _ = 0; _ < duration; ++_) {
            trajectory.time += 1;
            trajectory.update_altitude(0.01);
            trajectory.update_distance();
        }
    }
};

class FlightSimulator {
public:
    TrajectoryPlanner& planner;

    FlightSimulator(TrajectoryPlanner& planner) : planner(planner) {}

    void run() {
        while (true) {
            planner.plan(100);
            std::cout << "Altitude: " << trajectory.altitude << "m, Distance: " << trajectory.distance << "m" << std::endl;
        }
    }
};

int main() {
    FlightTrajectory flight(3000, 800);
    TrajectoryPlanner planner(flight);
    FlightSimulator simulator(planner);
    simulator.run();
    return 0;
}