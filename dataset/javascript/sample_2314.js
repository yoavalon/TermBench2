class FlightTrajectory {
    constructor(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    update_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.climb_rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.descent_rate;
        }
    }
}

class CruiseAltitudePlanner {
    constructor(flight, cruise_altitude, hold_time) {
        this.flight = flight;
        this.cruise = cruise_altitude;
        this.hold = hold_time;
        this.time_elapsed = 0;
    }

    plan_cruise() {
        this.flight.altitude = this.cruise;
        while (this.time_elapsed < this.hold) {
            this.time_elapsed += 1;
        }
    }
}

function main() {
    const initial = 1000;
    const target = 30000;
    const climb = 100;
    const descent = 50;
    const hold = 600;
    const flight = new FlightTrajectory(initial, target, climb, descent);
    const planner = new CruiseAltitudePlanner(flight, target, hold);
    while (true) {
        flight.update_altitude();
        planner.plan_cruise();
    }
}

main();