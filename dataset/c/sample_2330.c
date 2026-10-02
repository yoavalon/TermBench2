#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double v;
    double t;
    double g;
    double w;
} FlightTrajectory;

typedef struct {
    double b;
    double i;
    double m;
} CruiseAltitude;

FlightTrajectory createFlightTrajectory(double initial_altitude, double speed, double angle, double gravity, double wind_speed) {
    FlightTrajectory ft;
    ft.a = initial_altitude;
    ft.v = speed;
    ft.t = angle;
    ft.g = gravity;
    ft.w = wind_speed;
    return ft;
}

double calculate_time_to_cruise(FlightTrajectory ft) {
    return 2 * ft.a * sin(ft.t) / ft.g;
}

double adjust_for_wind(FlightTrajectory ft, double time) {
    return time / (1 + ft.w / ft.v);
}

CruiseAltitude createCruiseAltitude(double base_altitude, double altitude_increment, double max_altitude) {
    CruiseAltitude ca;
    ca.b = base_altitude;
    ca.i = altitude_increment;
    ca.m = max_altitude;
    return ca;
}

double determine_cruise_altitude(CruiseAltitude ca, double time) {
    double alt = ca.b + ca.i * time;
    if (alt > ca.m) {
        return ca.m;
    }
    return alt;
}

void main() {
    double initial_altitude = 1000.0;
    double speed = 250.0;
    double angle = sin(30 * M_PI / 180);
    double gravity = 9.81;
    double wind_speed = 10.0;
    double base_altitude = 10000.0;
    double altitude_increment = 500.0;
    double max_altitude = 30000.0;

    FlightTrajectory trajectory = createFlightTrajectory(initial_altitude, speed, angle, gravity, wind_speed);
    CruiseAltitude cruise_altitude = createCruiseAltitude(base_altitude, altitude_increment, max_altitude);

    while (1) {
        double time = calculate_time_to_cruise(trajectory);
        double adjusted_time = adjust_for_wind(trajectory, time);
        double current_altitude = determine_cruise_altitude(cruise_altitude, adjusted_time);
        printf("Current Altitude: %f\n", current_altitude);
    }
}