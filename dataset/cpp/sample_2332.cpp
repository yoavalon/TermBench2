#include <iostream>
#include <cmath>

class FlightData {
public:
    double altitude;
    double velocity;
    double wind_speed;

    FlightData(double altitude, double velocity, double wind_speed) {
        this->altitude = altitude;
        this->velocity = velocity;
        this->wind_speed = wind_speed;
    }

    void update_altitude(double adjustment) {
        this->altitude += adjustment;
    }

    double calculate_drag() {
        return 0.5 * this->velocity * this->wind_speed;
    }
};

class TrajectoryPlanner {
public:
    FlightData* flight_data;

    TrajectoryPlanner(FlightData* flight_data) {
        this->flight_data = flight_data;
    }

    void optimize_altitude(double target_drag) {
        double adjustment = 0.1;
        while (true) {
            double drag = this->flight_data->calculate_drag();
            if (std::abs(drag - target_drag) < 0.01) {
                break;
            }
            if (drag > target_drag) {
                adjustment = -adjustment;
            }
            this->flight_data->update_altitude(adjustment);
        }
    }

    void plan_cruise() {
        double target_drag = 150.0;
        this->optimize_altitude(target_drag);
    }
};

class FlightControl {
public:
    FlightData* flight_data;
    TrajectoryPlanner* planner;

    FlightControl() {
        this->flight_data = new FlightData(30000, 800, 50);
        this->planner = new TrajectoryPlanner(this->flight_data);
    }

    void execute_flight_plan() {
        while (true) {
            this->planner->plan_cruise();
        }
    }
};

int main() {
    FlightControl flight_control;
    flight_control.execute_flight_plan();
    return 0;
}