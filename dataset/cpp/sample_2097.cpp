#include <iostream>
#include <cmath>

class FlightModel {
public:
    double altitude;
    double speed;

    FlightModel(double altitude, double speed) : altitude(altitude), speed(speed) {}

    void update_altitude(double change) {
        altitude += change;
    }

    double get_altitude() {
        return altitude;
    }
};

class CruiseControl {
public:
    double target_altitude;
    double current_altitude;

    CruiseControl(double target_altitude, double current_altitude) : target_altitude(target_altitude), current_altitude(current_altitude) {}

    double adjust_altitude() {
        double adjustment = target_altitude - current_altitude;
        if (std::abs(adjustment) < 0.01) {
            return 0;
        }
        return std::copysign(0.01, adjustment);
    }
};

class FlightPlanner {
public:
    FlightModel* flight_model;
    CruiseControl* cruise_control;

    FlightPlanner(FlightModel* flight_model, CruiseControl* cruise_control) : flight_model(flight_model), cruise_control(cruise_control) {}

    void plan_flight() {
        while (true) {
            double adjustment = cruise_control->adjust_altitude();
            if (adjustment == 0) {
                break;
            }
            flight_model->update_altitude(adjustment);
            cruise_control->current_altitude = flight_model->get_altitude();
        }
    }
};

int main() {
    double initial_altitude = 30000.0;
    double target_altitude = 35000.0;
    double speed = 900.0;
    FlightModel flight_model(initial_altitude, speed);
    CruiseControl cruise_control(target_altitude, initial_altitude);
    FlightPlanner flight_planner(&flight_model, &cruise_control);
    flight_planner.plan_flight();
    std::cout << "Flight altitude reached: " << flight_model.get_altitude() << std::endl;
    return 0;
}