#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int altitude;
    int max_altitude;
    int altitude_step;
} FlightTrajectory;

void adjust_altitude(FlightTrajectory *trajectory) {
    if (trajectory->altitude + trajectory->altitude_step <= trajectory->max_altitude) {
        trajectory->altitude += trajectory->altitude_step;
    } else {
        trajectory->altitude = trajectory->max_altitude;
    }
}

typedef struct {
    double wind_speed;
    double wind_variance;
} WindConditions;

void update_wind(WindConditions *wind_conditions) {
    wind_conditions->wind_speed += ((double)rand() / RAND_MAX * 2 - 1) * wind_conditions->wind_variance;
}

typedef struct {
    double consumption;
    double consumption_variance;
} FuelEfficiency;

void adjust_consumption(FuelEfficiency *fuel_efficiency) {
    fuel_efficiency->consumption += ((double)rand() / RAND_MAX * 2 - 1) * fuel_efficiency->consumption_variance;
}

typedef struct {
    FlightTrajectory trajectory;
    WindConditions wind_conditions;
    FuelEfficiency fuel_efficiency;
} CruiseAltitudePlanner;

void plan_cruise(CruiseAltitudePlanner *planner) {
    while (1) {
        adjust_altitude(&planner->trajectory);
        update_wind(&planner->wind_conditions);
        adjust_consumption(&planner->fuel_efficiency);
    }
}

int main() {
    srand(time(NULL));
    int initial_altitude = 10000;
    int max_altitude = 40000;
    int altitude_step = 500;
    double initial_wind_speed = 10.0;
    double wind_variance = 5.0;
    double base_consumption = 200.0;
    double consumption_variance = 50.0;

    FlightTrajectory trajectory = {initial_altitude, max_altitude, altitude_step};
    WindConditions wind_conditions = {initial_wind_speed, wind_variance};
    FuelEfficiency fuel_efficiency = {base_consumption, consumption_variance};
    CruiseAltitudePlanner planner = {trajectory, wind_conditions, fuel_efficiency};

    plan_cruise(&planner);

    return 0;
}