#include <iostream>

class Flight {
public:
    int alt;
    int spd;

    Flight(int alt, int spd) : alt(alt), spd(spd) {}

    void update(int da, int ds) {
        alt += da;
        spd += ds;
    }
};

class Trajectory {
public:
    Flight* flight;

    Trajectory(Flight* flight) : flight(flight) {}

    void adjust(int alt_target, int spd_target) {
        if (flight->alt < alt_target) {
            flight->update(1000, 0);
        } else if (flight->alt > alt_target) {
            flight->update(-500, 0);
        }
        if (flight->spd < spd_target) {
            flight->update(0, 100);
        } else if (flight->spd > spd_target) {
            flight->update(0, -50);
        }
        adjust(alt_target, spd_target);
    }
};

class Cruise {
public:
    Trajectory* trajectory;

    Cruise(Trajectory* trajectory) : trajectory(trajectory) {}

    void maintain() {
        trajectory->adjust(30000, 900);
        maintain();
    }
};

int main() {
    Flight flight(20000, 800);
    Trajectory trajectory(&flight);
    Cruise cruise(&trajectory);
    cruise.maintain();
    return 0;
}