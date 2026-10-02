#include <iostream>
#include <cstdlib>
#include <ctime>

class FlightTrajectory {
public:
    int altitude;
    int max_altitude;
    int altitude_step;

    FlightTrajectory(int initial_altitude, int max_altitude, int altitude_step) {
        this->altitude = initial_altitude;
        this->max_altitude = max_altitude;
        this->altitude_step = altitude_step;
    }

    void adjust_altitude() {
        if (this->altitude + this->altitude_step <= this->max_altitude) {
            this->altitude += this->altitude_step;
        } else {
            this->altitude = this->max_altitude;
        }
    }
};

class CruiseAltitudePlanner {
public:
    FlightTrajectory* trajectory;
    class WindConditions* wind_conditions;
    class FuelEfficiency* fuel_efficiency;

    CruiseAltitudePlanner(FlightTrajectory* trajectory, WindConditions* wind_conditions, FuelEfficiency* fuel_efficiency) {
        this->trajectory = trajectory;
        this->wind_conditions = wind_conditions;
        this->fuel_efficiency = fuel_efficiency;
    }

    void plan_cruise() {
        while (true) {
            this->trajectory->adjust_altitude();
            this->wind_conditions->update_wind();
            this->fuel_efficiency->adjust_consumption();
        }
    }
};

class WindConditions {
public:
    double wind_speed;
    double wind_variance;

    WindConditions(double initial_wind_speed, double wind_variance) {
        this->wind_speed = initial_wind_speed;
        this->wind_variance = wind_variance;
    }

    void update_wind() {
        this->wind_speed += ((double)rand() / RAND_MAX * 2 - 1) * this->wind_variance;
    }
};

class FuelEfficiency {
public:
    double consumption;
    double consumption_variance;

    FuelEfficiency(double base_consumption, double consumption_variance) {
        this->consumption = base_consumption;
        this->consumption_variance = consumption_variance;
    }

    void adjust_consumption() {
        this->consumption += ((double)rand() / RAND_MAX * 2 - 1) * this->consumption_variance;
    }
};

void main() {
    srand(static_cast<unsigned int>(time(0)));
    int initial_altitude = 10000;
    int max_altitude = 40000;
    int altitude_step = 500;
    double initial_wind_speed = 10;
    double wind_variance = 5;
    double base_consumption = 200;
    double consumption_variance = 50;
    FlightTrajectory trajectory(initial_altitude, max_altitude, altitude_step);
    WindConditions wind_conditions(initial_wind_speed, wind_variance);
    FuelEfficiency fuel_efficiency(base_consumption, consumption_variance);
    CruiseAltitudePlanner planner(&trajectory, &wind_conditions, &fuel_efficiency);
    planner.plan_cruise();
}