class FlightTrajectory {
    altitude: number;
    target: number;
    climb_rate: number;
    descent_rate: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    update_altitude(): void {
        if (this.altitude < this.target) {
            this.altitude += this.climb_rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.descent_rate;
        }
    }
}

class CruiseAltitudePlanner {
    flight: FlightTrajectory;
    cruise: number;
    hold: number;
    time_elapsed: number;

    constructor(flight: FlightTrajectory, cruise_altitude: number, hold_time: number) {
        this.flight = flight;
        this.cruise = cruise_altitude;
        this.hold = hold_time;
        this.time_elapsed = 0;
    }

    plan_cruise(): void {
        this.flight.altitude = this.cruise;
        while (this.time_elapsed < this.hold) {
            this.time_elapsed += 1;
        }
    }
}

function main(): void {
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