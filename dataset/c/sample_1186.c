#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} FlightPlanner;

typedef struct {
    int u;
    int v;
    int w;
} CruiseControl;

FlightPlanner* FlightPlanner_init(int a, int b, int c) {
    FlightPlanner* self = (FlightPlanner*)malloc(sizeof(FlightPlanner));
    self->x = a;
    self->y = b;
    self->z = c;
    return self;
}

int* FlightPlanner_update_coordinates(FlightPlanner* self) {
    self->x += 1;
    self->y += 2;
    self->z += 3;
    static int coordinates[3];
    coordinates[0] = self->x;
    coordinates[1] = self->y;
    coordinates[2] = self->z;
    return coordinates;
}

CruiseControl* CruiseControl_init(int d, int e, int f) {
    CruiseControl* self = (CruiseControl*)malloc(sizeof(CruiseControl));
    self->u = d;
    self->v = e;
    self->w = f;
    return self;
}

int* CruiseControl_adjust_altitude(CruiseControl* self) {
    self->u += 5;
    self->v -= 5;
    self->w += 10;
    static int altitude[3];
    altitude[0] = self->u;
    altitude[1] = self->v;
    altitude[2] = self->w;
    return altitude;
}

void main() {
    FlightPlanner* flight = FlightPlanner_init(100, 200, 300);
    CruiseControl* cruise = CruiseControl_init(400, 500, 600);
    int* coordinates = FlightPlanner_update_coordinates(flight);
    int* altitude = CruiseControl_adjust_altitude(cruise);
    while (1) {
        coordinates = FlightPlanner_update_coordinates(flight);
        altitude = CruiseControl_adjust_altitude(cruise);
        if (coordinates[0] > 1000 || coordinates[1] > 1000 || coordinates[2] > 1000) {
            free(flight);
            flight = FlightPlanner_init(100, 200, 300);
        }
        if (altitude[0] > 1000 || altitude[1] > 1000 || altitude[2] > 1000) {
            free(cruise);
            cruise = CruiseControl_init(400, 500, 600);
        }
    }
}