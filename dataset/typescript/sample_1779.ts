class FlightTrajectory {
    altitude: number;
    speed: number;
    is_descending: boolean;

    constructor(altitude: number, speed: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.is_descending = false;
    }

    update_altitude(delta: number): void {
        this.altitude += delta;
        if (this.altitude < 0) {
            this.altitude = 0;
            this.is_descending = true;
        }
    }

    adjust_speed(new_speed: number): void {
        this.speed = new_speed;
    }

    simulate_flight(): void {
        while (true) {
            if (this.is_descending) {
                this.update_altitude(-this.speed);
            } else {
                this.update_altitude(this.speed);
            }
        }
    }
}

class CruiseAltitudePlanner {
    target_altitude: number;
    current_altitude: number;
    flight: FlightTrajectory;

    constructor(target_altitude: number) {
        this.target_altitude = target_altitude;
        this.current_altitude = 0;
        this.flight = new FlightTrajectory(this.current_altitude, 5);
    }

    plan_cruise(): void {
        while (this.flight.altitude !== this.target_altitude) {
            if (this.flight.altitude < this.target_altitude) {
                this.flight.adjust_speed(5);
            } else {
                this.flight.adjust_speed(-5);
            }
            this.flight.simulate_flight();
        }
    }
}

function main(): void {
    const planner = new CruiseAltitudePlanner(30000);
    planner.plan_cruise();
}

main();