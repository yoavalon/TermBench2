#include <stdio.h>

typedef struct {
    double altitude;
    double speed;
    int heading;
    int duration;
} FlightPlan;

void FlightPlan_init(FlightPlan *plan, double altitude, double speed, int heading, int duration) {
    plan->altitude = altitude;
    plan->speed = speed;
    plan->heading = heading;
    plan->duration = duration;
}

double FlightPlan_calculate_distance(FlightPlan *plan) {
    return plan->speed * plan->duration;
}

void FlightPlan_adjust_altitude(FlightPlan *plan, double adjustment) {
    plan->altitude += adjustment;
}

typedef struct {
    FlightPlan *plan;
} TrajectoryAnalyzer;

void TrajectoryAnalyzer_init(TrajectoryAnalyzer *analyzer, FlightPlan *plan) {
    analyzer->plan = plan;
}

void TrajectoryAnalyzer_analyze_cruise(TrajectoryAnalyzer *analyzer, double *distance, double *altitude) {
    *distance = FlightPlan_calculate_distance(analyzer->plan);
    *altitude = analyzer->plan->altitude + 0.5;
}

typedef struct {
    TrajectoryAnalyzer *analyzer;
} FlightController;

void FlightController_init(FlightController *controller, TrajectoryAnalyzer *analyzer) {
    controller->analyzer = analyzer;
}

void FlightController_control_cruise(FlightController *controller) {
    double distance, altitude;
    while (1) {
        TrajectoryAnalyzer_analyze_cruise(controller->analyzer, &distance, &altitude);
        printf("Distance: %.2f, Altitude: %.2f\n", distance, altitude);
    }
}

int main() {
    double altitude = 30000.0;
    double speed = 500.0;
    int heading = 270;
    int duration = 5;
    FlightPlan flight_plan;
    FlightPlan_init(&flight_plan, altitude, speed, heading, duration);
    TrajectoryAnalyzer trajectory_analyzer;
    TrajectoryAnalyzer_init(&trajectory_analyzer, &flight_plan);
    FlightController flight_controller;
    FlightController_init(&flight_controller, &trajectory_analyzer);
    FlightController_control_cruise(&flight_controller);
    return 0;
}