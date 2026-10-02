#include <stdio.h>
#include <math.h>

typedef struct {
    double distance;
    double speed;
    double wind;
} FlightPlan;

double calculate_time(FlightPlan* flight_plan) {
    double adjusted_speed = flight_plan->speed - flight_plan->wind;
    return flight_plan->distance / adjusted_speed;
}

typedef struct {
    double altitude;
    double temperature;
} CruiseAltitude;

double calculate_density(CruiseAltitude* cruise_altitude) {
    double temp_kelvin = cruise_altitude->temperature + 273.15;
    return 1.225 * exp(-0.0065 * cruise_altitude->altitude / temp_kelvin);
}

typedef struct {
    FlightPlan* flight_plan;
    CruiseAltitude* cruise_altitude;
} FlightAnalysis;

void analyze(FlightAnalysis* analysis, double* time, double* density) {
    *time = calculate_time(analysis->flight_plan);
    *density = calculate_density(analysis->cruise_altitude);
}

int main() {
    FlightPlan flight = {1000.0, 500.0, 50.0};
    CruiseAltitude altitude = {10000.0, -50.0};
    FlightAnalysis analysis = {&flight, &altitude};
    double time, density;
    analyze(&analysis, &time, &density);
    printf("Flight Time: %.2f hours\n", time);
    printf("Air Density at Cruise Altitude: %.4f kg/m^3\n", density);
    return 0;
}