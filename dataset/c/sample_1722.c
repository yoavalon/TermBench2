#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *self, int altitude, int speed) {
    self->altitude = altitude;
    self->speed = speed;
}

void FlightPlanner_update_altitude(FlightPlanner *self, int new_altitude) {
    self->altitude = new_altitude;
}

int FlightPlanner_calculate_time_to_descend(FlightPlanner *self, int target_altitude) {
    int descent_rate = 1000;
    return (self->altitude - target_altitude) / descent_rate;
}

typedef struct {
    int target_speed;
} CruiseControl;

void CruiseControl_init(CruiseControl *self, int target_speed) {
    self->target_speed = target_speed;
}

int CruiseControl_adjust_speed(CruiseControl *self, int current_speed) {
    return current_speed != self->target_speed ? self->target_speed : current_speed;
}

typedef struct {
    FlightPlanner *flight_planner;
    CruiseControl *cruise_control;
} FlightAnalyzer;

void FlightAnalyzer_init(FlightAnalyzer *self, FlightPlanner *flight_planner, CruiseControl *cruise_control) {
    self->flight_planner = flight_planner;
    self->cruise_control = cruise_control;
}

void FlightAnalyzer_analyze(FlightAnalyzer *self) {
    while (1) {
        int new_altitude = self->flight_planner->altitude - 100;
        FlightPlanner_update_altitude(self->flight_planner, new_altitude);
        int adjusted_speed = CruiseControl_adjust_speed(self->cruise_control, self->flight_planner->speed);
        printf("Altitude: %d, Speed: %d\n", self->flight_planner->altitude, adjusted_speed);
    }
}

int main() {
    FlightPlanner planner;
    FlightPlanner_init(&planner, 10000, 800);
    CruiseControl cruise_control;
    CruiseControl_init(&cruise_control, 800);
    FlightAnalyzer analyzer;
    FlightAnalyzer_init(&analyzer, &planner, &cruise_control);
    FlightAnalyzer_analyze(&analyzer);
    return 0;
}