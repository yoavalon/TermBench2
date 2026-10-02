#include <iostream>

class FlightPlanner {
public:
    FlightPlanner(int initial_altitude, int rate_of_climb) {
        altitude = initial_altitude;
        climb_rate = rate_of_climb;
    }

    void update_altitude(int time_step) {
        altitude += climb_rate * time_step;
    }

    int get_altitude() {
        return altitude;
    }

private:
    int altitude;
    int climb_rate;
};

class CruiseControl {
public:
    CruiseControl(int target_altitude) {
        target = target_altitude;
    }

    int adjust_altitude(int current_altitude) {
        if (current_altitude < target) {
            return 100;
        } else if (current_altitude > target) {
            return -50;
        } else {
            return 0;
        }
    }

private:
    int target;
};

class FlightSimulator {
public:
    FlightSimulator(int initial_altitude, int target_altitude) {
        planner = new FlightPlanner(initial_altitude, 50);
        controller = new CruiseControl(target_altitude);
        time_step = 1;
    }

    void simulate_flight() {
        while (true) {
            int current_altitude = planner->get_altitude();
            int adjustment = controller->adjust_altitude(current_altitude);
            planner->climb_rate = adjustment;
            planner->update_altitude(time_step);
        }
    }

private:
    FlightPlanner* planner;
    CruiseControl* controller;
    int time_step;
};

int main() {
    FlightSimulator simulator(1000, 35000);
    simulator.simulate_flight();
    return 0;
}