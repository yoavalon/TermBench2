#include <stdio.h>
#include <math.h>

typedef struct {
    double altitude;
    double target;
    double ascent;
    double descent;
} FlightPathCalculator;

void FlightPathCalculator_init(FlightPathCalculator *calculator, double initial_altitude, double target_altitude, double ascent_rate, double descent_rate) {
    calculator->altitude = initial_altitude;
    calculator->target = target_altitude;
    calculator->ascent = ascent_rate;
    calculator->descent = descent_rate;
}

void FlightPathCalculator_update_altitude(FlightPathCalculator *calculator) {
    if (calculator->altitude < calculator->target) {
        calculator->altitude += calculator->ascent;
    } else {
        calculator->altitude -= calculator->descent;
    }
}

typedef struct {
    FlightPathCalculator *calc;
} CruiseAltitudePlanner;

void CruiseAltitudePlanner_init(CruiseAltitudePlanner *planner, FlightPathCalculator *calculator) {
    planner->calc = calculator;
}

void CruiseAltitudePlanner_plan_cruise(CruiseAltitudePlanner *planner) {
    while (1) {
        FlightPathCalculator_update_altitude(planner->calc);
        CruiseAltitudePlanner_adjust_for_precision(planner);
    }
}

void CruiseAltitudePlanner_adjust_for_precision(CruiseAltitudePlanner *planner) {
    if (fabs(planner->calc->altitude - planner->calc->target) < 1e-09) {
        planner->calc->altitude = planner->calc->target;
    }
}

int main() {
    double initial = 10000;
    double target = 30000;
    double ascent_rate = 500;
    double descent_rate = 250;
    FlightPathCalculator calculator;
    FlightPathCalculator_init(&calculator, initial, target, ascent_rate, descent_rate);
    CruiseAltitudePlanner planner;
    CruiseAltitudePlanner_init(&planner, &calculator);
    CruiseAltitudePlanner_plan_cruise(&planner);
    return 0;
}