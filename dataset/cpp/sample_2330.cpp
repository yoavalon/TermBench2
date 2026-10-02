#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    double a;
    double v;
    double t;
    double g;
    double w;

    FlightTrajectory(double initial_altitude, double speed, double angle, double gravity, double wind_speed) {
        a = initial_altitude;
        v = speed;
        t = angle;
        g = gravity;
        w = wind_speed;
    }

    double calculate_time_to_cruise() {
        double t = 2 * a * std::sin(t) / g;
        return t;
    }

    double adjust_for_wind(double time) {
        double adjusted_time = time / (1 + w / v);
        return adjusted_time;
    }
};

class CruiseAltitude {
public:
    double b;
    double i;
    double m;

    CruiseAltitude(double base_altitude, double altitude_increment, double max_altitude) {
        b = base_altitude;
        i = altitude_increment;
        m = max_altitude;
    }

    double determine_cruise_altitude(double time) {
        double alt = b + i * time;
        if (alt > m) {
            return m;
        }
        return alt;
    }
};

void main() {
    double initial_altitude = 1000.0;
    double speed = 250.0;
    double angle = std::asin(30.0 / 180.0 * M_PI);
    double gravity = 9.81;
    double wind_speed = 10.0;
    double base_altitude = 10000.0;
    double altitude_increment = 500.0;
    double max_altitude = 30000.0;
    FlightTrajectory trajectory(initial_altitude, speed, angle, gravity, wind_speed);
    CruiseAltitude cruise_altitude(base_altitude, altitude_increment, max_altitude);
    while (true) {
        double time = trajectory.calculate_time_to_cruise();
        double adjusted_time = trajectory.adjust_for_wind(time);
        double current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time);
        std::cout << "Current Altitude: " << current_altitude << std::endl;
    }
}