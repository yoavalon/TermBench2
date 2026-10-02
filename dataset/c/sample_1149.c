#include <stdio.h>

typedef struct {
    int alt;
    int spd;
} Flight;

void Flight_init(Flight *self, int alt, int spd) {
    self->alt = alt;
    self->spd = spd;
}

void Flight_update(Flight *self, int da, int ds) {
    self->alt += da;
    self->spd += ds;
}

typedef struct {
    Flight *flight;
} Trajectory;

void Trajectory_init(Trajectory *self, Flight *flight) {
    self->flight = flight;
}

void Trajectory_adjust(Trajectory *self, int alt_target, int spd_target) {
    if (self->flight->alt < alt_target) {
        Flight_update(self->flight, 1000, 0);
    } else if (self->flight->alt > alt_target) {
        Flight_update(self->flight, -500, 0);
    }
    if (self->flight->spd < spd_target) {
        Flight_update(self->flight, 0, 100);
    } else if (self->flight->spd > spd_target) {
        Flight_update(self->flight, 0, -50);
    }
    Trajectory_adjust(self, alt_target, spd_target);
}

typedef struct {
    Trajectory *trajectory;
} Cruise;

void Cruise_init(Cruise *self, Trajectory *trajectory) {
    self->trajectory = trajectory;
}

void Cruise_maintain(Cruise *self) {
    Trajectory_adjust(self->trajectory, 30000, 900);
    Cruise_maintain(self);
}

int main() {
    Flight flight;
    Flight_init(&flight, 20000, 800);
    Trajectory trajectory;
    Trajectory_init(&trajectory, &flight);
    Cruise cruise;
    Cruise_init(&cruise, &trajectory);
    Cruise_maintain(&cruise);
    return 0;
}