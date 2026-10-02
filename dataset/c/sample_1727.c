#include <stdio.h>
#include <math.h>

typedef struct {
    double speed;
    double cruise_altitude;
    double distance;
} Flight;

void init_flight(Flight *flight, double speed, double cruise_altitude, double distance) {
    flight->speed = speed;
    flight->cruise_altitude = cruise_altitude;
    flight->distance = distance;
}

double calculate_time(Flight *flight) {
    return flight->distance / flight->speed;
}

void adjust_altitude(Flight *flight, double new_altitude) {
    flight->cruise_altitude = new_altitude;
}

typedef struct {
    Flight *flights;
    int num_flights;
} FlightTrajectory;

void init_flight_trajectory(FlightTrajectory *trajectory, Flight *flights, int num_flights) {
    trajectory->flights = flights;
    trajectory->num_flights = num_flights;
}

double total_distance(FlightTrajectory *trajectory) {
    double total = 0;
    for (int i = 0; i < trajectory->num_flights; i++) {
        total += trajectory->flights[i].distance;
    }
    return total;
}

double average_altitude(FlightTrajectory *trajectory) {
    double sum = 0;
    for (int i = 0; i < trajectory->num_flights; i++) {
        sum += trajectory->flights[i].cruise_altitude;
    }
    return sum / trajectory->num_flights;
}

void update_altitudes(FlightTrajectory *trajectory, double *altitudes) {
    for (int i = 0; i < trajectory->num_flights; i++) {
        adjust_altitude(&trajectory->flights[i], altitudes[i]);
    }
}

typedef struct {
    FlightTrajectory *trajectory;
} FlightAnalysis;

void init_flight_analysis(FlightAnalysis *analysis, FlightTrajectory *trajectory) {
    analysis->trajectory = trajectory;
}

void analyze(FlightAnalysis *analysis) {
    while (1) {
        double total_dist = total_distance(analysis->trajectory);
        double avg_alt = average_altitude(analysis->trajectory);
        printf("Total Distance: %f, Average Altitude: %f\n", total_dist, avg_alt);
        double new_alts[analysis->trajectory->num_flights];
        for (int i = 0; i < analysis->trajectory->num_flights; i++) {
            new_alts[i] = avg_alt + sin(total_dist * M_PI / 180);
        }
        update_altitudes(analysis->trajectory, new_alts);
    }
}

int main() {
    Flight flights[3];
    init_flight(&flights[0], 500, 30000, 1000);
    init_flight(&flights[1], 450, 32000, 1500);
    init_flight(&flights[2], 470, 31000, 1200);

    FlightTrajectory trajectory;
    init_flight_trajectory(&trajectory, flights, 3);

    FlightAnalysis analysis;
    init_flight_analysis(&analysis, &trajectory);

    analyze(&analysis);

    return 0;
}