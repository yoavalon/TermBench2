#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int heading;
} FlightPlanner;

void FlightPlanner_init(FlightPlanner *self, int altitude, int speed, int heading) {
    self->altitude = altitude;
    self->speed = speed;
    self->heading = heading;
}

void FlightPlanner_update_altitude(FlightPlanner *self, int delta) {
    self->altitude += delta;
}

double FlightPlanner_calculate_time_to_destination(FlightPlanner *self, int distance) {
    return (double)distance / self->speed;
}

typedef struct {
    FlightPlanner *planner;
} TrajectoryCalculator;

void TrajectoryCalculator_init(TrajectoryCalculator *self, FlightPlanner *planner) {
    self->planner = planner;
}

int TrajectoryCalculator_calculate_cruise_altitude(TrajectoryCalculator *self) {
    if (self->planner->altitude < 30000) {
        return 30000;
    }
    return self->planner->altitude;
}

void TrajectoryCalculator_adjust_for_winds(TrajectoryCalculator *self, int wind_speed, int wind_direction, int *adjusted_speed, int *adjusted_heading) {
    *adjusted_speed = self->planner->speed - wind_speed * 0.5;
    *adjusted_heading = self->planner->heading + wind_direction;
}

typedef struct {
    TrajectoryCalculator *calculator;
} FlightAnalyzer;

void FlightAnalyzer_init(FlightAnalyzer *self, TrajectoryCalculator *calculator) {
    self->calculator = calculator;
}

void FlightAnalyzer_analyze(FlightAnalyzer *self, int distance, int *cruise_altitude, int *adjusted_speed, int *adjusted_heading, double *time_to_destination) {
    *cruise_altitude = TrajectoryCalculator_calculate_cruise_altitude(self->calculator);
    TrajectoryCalculator_adjust_for_winds(self->calculator, 10, 5, adjusted_speed, adjusted_heading);
    *time_to_destination = FlightPlanner_calculate_time_to_destination(self->calculator->planner, distance);
}

int main() {
    FlightPlanner planner;
    FlightPlanner_init(&planner, 25000, 500, 90);
    TrajectoryCalculator calculator;
    TrajectoryCalculator_init(&calculator, &planner);
    FlightAnalyzer analyzer;
    FlightAnalyzer_init(&analyzer, &calculator);
    int cruise_altitude, adjusted_speed, adjusted_heading;
    double time_to_destination;
    FlightAnalyzer_analyze(&analyzer, 1000, &cruise_altitude, &adjusted_speed, &adjusted_heading, &time_to_destination);
    printf("Cruise Altitude: %d\n", cruise_altitude);
    printf("Adjusted Speed: %d\n", adjusted_speed);
    printf("Adjusted Heading: %d\n", adjusted_heading);
    printf("Time to Destination: %.2f\n", time_to_destination);
    return 0;
}