#include <iostream>

class FlightParameters {
public:
    int altitude;
    int target;
    int climb_rate;
    int descent_rate;

    FlightParameters(int initial_altitude, int target_altitude, int max_climb_rate, int descent_rate) {
        altitude = initial_altitude;
        target = target_altitude;
        climb_rate = max_climb_rate;
        descent_rate = descent_rate;
    }
};

class FlightControl {
public:
    FlightParameters* params;

    FlightControl(FlightParameters* parameters) {
        params = parameters;
    }

    int adjust_altitude() {
        if (params->altitude < params->target) {
            params->altitude += params->climb_rate;
        } else if (params->altitude > params->target) {
            params->altitude -= params->descent_rate;
        }
        return params->altitude;
    }
};

class FlightSimulation {
public:
    FlightControl* control;
    bool is_operational;

    FlightSimulation(FlightControl* control) {
        this->control = control;
        is_operational = true;
    }

    void run_simulation() {
        while (is_operational) {
            int new_altitude = control->adjust_altitude();
            if (new_altitude == control->params->target) {
                is_operational = false;
            }
            std::cout << "Current Altitude: " << new_altitude << std::endl;
        }
    }
};

int main() {
    FlightParameters params(5000, 35000, 1500, 500);
    FlightControl control(&params);
    FlightSimulation simulation(&control);
    simulation.run_simulation();
    return 0;
}