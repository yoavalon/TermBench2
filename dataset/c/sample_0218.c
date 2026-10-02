#include <stdio.h>

typedef struct {
    int altitude;
    int target;
    int climb_rate;
    int descent_rate;
} FlightParameters;

typedef struct {
    FlightParameters *params;
} FlightControl;

typedef struct {
    FlightControl *control;
    int is_operational;
} FlightSimulation;

FlightParameters* FlightParameters_new(int initial_altitude, int target_altitude, int max_climb_rate, int descent_rate) {
    FlightParameters *self = (FlightParameters*)malloc(sizeof(FlightParameters));
    self->altitude = initial_altitude;
    self->target = target_altitude;
    self->climb_rate = max_climb_rate;
    self->descent_rate = descent_rate;
    return self;
}

FlightControl* FlightControl_new(FlightParameters *parameters) {
    FlightControl *self = (FlightControl*)malloc(sizeof(FlightControl));
    self->params = parameters;
    return self;
}

int FlightControl_adjust_altitude(FlightControl *self) {
    if (self->params->altitude < self->params->target) {
        self->params->altitude += self->params->climb_rate;
    } else if (self->params->altitude > self->params->target) {
        self->params->altitude -= self->params->descent_rate;
    }
    return self->params->altitude;
}

FlightSimulation* FlightSimulation_new(FlightControl *control) {
    FlightSimulation *self = (FlightSimulation*)malloc(sizeof(FlightSimulation));
    self->control = control;
    self->is_operational = 1;
    return self;
}

void FlightSimulation_run_simulation(FlightSimulation *self) {
    while (self->is_operational) {
        int new_altitude = FlightControl_adjust_altitude(self->control);
        if (new_altitude == self->control->params->target) {
            self->is_operational = 0;
        }
        printf("Current Altitude: %d\n", new_altitude);
    }
}

void main() {
    FlightParameters *params = FlightParameters_new(5000, 35000, 1500, 500);
    FlightControl *control = FlightControl_new(params);
    FlightSimulation *simulation = FlightSimulation_new(control);
    FlightSimulation_run_simulation(simulation);
}