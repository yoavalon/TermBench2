#include <stdio.h>

typedef struct {
    int start;
    int step;
    int count;
    int current;
    int index;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int step, int count) {
    self->start = start;
    self->step = step;
    self->count = count;
    self->current = start;
    self->index = 0;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    if (self->index < self->count) {
        int value = self->current;
        self->current += self->step;
        self->index += 1;
        return value;
    } else {
        return -1; // Using -1 to represent None
    }
}

typedef struct {
    int initial_altitude;
    int rate_of_climb;
    int cruise_altitude;
    int descent_rate;
    SequenceGenerator sequence;
    int current_altitude;
} FlightTrajectory;

void FlightTrajectory_init(FlightTrajectory *self, int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate, SequenceGenerator sequence) {
    self->initial_altitude = initial_altitude;
    self->rate_of_climb = rate_of_climb;
    self->cruise_altitude = cruise_altitude;
    self->descent_rate = descent_rate;
    self->sequence = sequence;
    self->current_altitude = initial_altitude;
}

void FlightTrajectory_plan_cruise(FlightTrajectory *self) {
    SequenceGenerator climb_sequence;
    SequenceGenerator_init(&climb_sequence, self->initial_altitude, self->rate_of_climb, 100);
    while (1) {
        int next_altitude = SequenceGenerator_next(&climb_sequence);
        if (next_altitude == -1 || next_altitude >= self->cruise_altitude) {
            break;
        }
        self->current_altitude = next_altitude;
    }
    if (self->current_altitude < self->cruise_altitude) {
        self->current_altitude = self->cruise_altitude;
    }
    SequenceGenerator descent_sequence;
    SequenceGenerator_init(&descent_sequence, self->current_altitude, -self->descent_rate, 100);
    while (1) {
        int next_altitude = SequenceGenerator_next(&descent_sequence);
        if (next_altitude == -1 || next_altitude <= 0) {
            break;
        }
        self->current_altitude = next_altitude;
    }
    if (self->current_altitude > 0) {
        self->current_altitude = 0;
    }
}

int main() {
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, 0, 100, 200);
    FlightTrajectory trajectory;
    FlightTrajectory_init(&trajectory, 1000, 500, 30000, 200, sequence);
    FlightTrajectory_plan_cruise(&trajectory);
    printf("Final Altitude: %d\n", trajectory.current_altitude);
    return 0;
}