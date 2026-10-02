#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double speed;
    double wind_speed;
    double wind_direction;
} TrajectoryPlanner;

typedef struct {
    double target_altitude;
    double max_altitude;
} CruiseManager;

void TrajectoryPlanner_init(TrajectoryPlanner *self, double initial_altitude, double speed, double wind_speed, double wind_direction) {
    self->altitude = initial_altitude;
    self->speed = speed;
    self->wind_speed = wind_speed;
    self->wind_direction = wind_direction;
}

double TrajectoryPlanner_calculate_distance(TrajectoryPlanner *self, double time) {
    double distance = self->speed * time;
    double wind_effect = self->wind_speed * cos(self->wind_direction * M_PI / 180 - M_PI / 2);
    return distance + wind_effect;
}

void TrajectoryPlanner_update_altitude(TrajectoryPlanner *self, double time, double rate_of_climb) {
    double climb_distance = rate_of_climb * time;
    self->altitude += climb_distance;
}

void CruiseManager_init(CruiseManager *self, double target_altitude, double max_altitude) {
    self->target_altitude = target_altitude;
    self->max_altitude = max_altitude;
}

int CruiseManager_should_adjust_altitude(CruiseManager *self, double current_altitude) {
    return current_altitude < self->target_altitude;
}

double CruiseManager_calculate_rate_of_climb(CruiseManager *self, double current_altitude) {
    return (self->target_altitude - current_altitude) / 10;
}

int main() {
    double initial_altitude = 1000;
    double speed = 250;
    double wind_speed = 20;
    double wind_direction = 45;
    TrajectoryPlanner trajectory;
    CruiseManager cruise_manager;
    double time_step = 60;

    TrajectoryPlanner_init(&trajectory, initial_altitude, speed, wind_speed, wind_direction);
    CruiseManager_init(&cruise_manager, 15000, 20000);

    while (1) {
        double distance = TrajectoryPlanner_calculate_distance(&trajectory, time_step);
        if (CruiseManager_should_adjust_altitude(&cruise_manager, trajectory.altitude)) {
            double rate_of_climb = CruiseManager_calculate_rate_of_climb(&cruise_manager, trajectory.altitude);
            TrajectoryPlanner_update_altitude(&trajectory, time_step, rate_of_climb);
        }
        printf("Distance: %.2fm, Altitude: %.2fm\n", distance, trajectory.altitude);
    }

    return 0;
}