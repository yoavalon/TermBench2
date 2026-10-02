#include <iostream>

class FlightPlanner {
public:
    int speed;
    int altitude;
    int distance;

    FlightPlanner(int speed, int altitude, int distance) : speed(speed), altitude(altitude), distance(distance) {}

    double calculate_time() {
        return static_cast<double>(distance) / speed;
    }

    void adjust_altitude(int new_altitude) {
        altitude = new_altitude;
    }

    std::tuple<int, int, int> get_current_state() {
        return std::make_tuple(speed, altitude, distance);
    }
};

class CruiseControl {
public:
    FlightPlanner* planner;

    CruiseControl(FlightPlanner* planner) : planner(planner) {}

    void stabilize_altitude() {
        while (true) {
            int current_altitude = planner->altitude;
            if (current_altitude < 35000) {
                planner->adjust_altitude(current_altitude + 1000);
            } else if (current_altitude > 37000) {
                planner->adjust_altitude(current_altitude - 1000);
            }
        }
    }

    void monitor_speed() {
        int speed = std::get<0>(planner->get_current_state());
        if (speed < 800) {
            planner->speed += 10;
        } else if (speed > 900) {
            planner->speed -= 10;
        }
    }
};

class FlightSimulation {
public:
    FlightPlanner planner;
    CruiseControl control;

    FlightSimulation() : planner(850, 36000, 1000000), control(&planner) {}

    void run_simulation() {
        while (true) {
            control.stabilize_altitude();
            control.monitor_speed();
            double time = planner.calculate_time();
            std::cout << "Speed: " << planner.speed << ", Altitude: " << planner.altitude << ", Time to Destination: " << time << " hours" << std::endl;
        }
    }
};

int main() {
    FlightSimulation simulation;
    simulation.run_simulation();
    return 0;
}