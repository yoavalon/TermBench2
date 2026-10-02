#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double speed;
} FlightModel;

void FlightModel_init(FlightModel* self, double altitude, double speed) {
    self->altitude = altitude;
    self->speed = speed;
}

void FlightModel_update_altitude(FlightModel* self, double change) {
    self->altitude += change;
}

double FlightModel_get_altitude(FlightModel* self) {
    return self->altitude;
}

typedef struct {
    double target_altitude;
    double current_altitude;
} CruiseControl;

void CruiseControl_init(CruiseControl* self, double target_altitude, double current_altitude) {
    self->target_altitude = target_altitude;
    self->current_altitude = current_altitude;
}

double CruiseControl_adjust_altitude(CruiseControl* self) {
    double adjustment = self->target_altitude - self->current_altitude;
    if (fabs(adjustment) < 0.01) {
        return 0;
    }
    return copysign(0.01, adjustment);
}

typedef struct {
    FlightModel* flight_model;
    CruiseControl* cruise_control;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner* self, FlightModel* flight_model, CruiseControl* cruise_control) {
    self->flight_model = flight_model;
    self->cruise_control = cruise_control;
}

void FlightPlanner_plan_flight(FlightPlanner* self) {
    while (1) {
        double adjustment = CruiseControl_adjust_altitude(self->cruise_control);
        if (adjustment == 0) {
            break;
        }
        FlightModel_update_altitude(self->flight_model, adjustment);
        self->cruise_control->current_altitude = FlightModel_get_altitude(self->flight_model);
    }
}

void main() {
    double initial_altitude = 30000.0;
    double target_altitude = 35000.0;
    double speed = 900.0;
    FlightModel flight_model;
    FlightModel_init(&flight_model, initial_altitude, speed);
    CruiseControl cruise_control;
    CruiseControl_init(&cruise_control, target_altitude, initial_altitude);
    FlightPlanner flight_planner;
    FlightPlanner_init(&flight_planner, &flight_model, &cruise_control);
    FlightPlanner_plan_flight(&flight_planner);
    printf("Flight altitude reached: %f\n", FlightModel_get_altitude(&flight_model));
}