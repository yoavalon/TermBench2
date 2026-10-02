class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_climb;
    }

    update_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
        }
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;
    cruise: number;

    constructor(trajectory: FlightTrajectory, cruise_altitude: number) {
        this.trajectory = trajectory;
        this.cruise = cruise_altitude;
    }

    plan_cruise(): number {
        while (this.trajectory.altitude < this.cruise) {
            this.trajectory.update_altitude();
        }
        return this.cruise;
    }
}

class FlightControl {
    planner: CruiseAltitudePlanner;

    constructor(planner: CruiseAltitudePlanner) {
        this.planner = planner;
    }

    execute_flight(): void {
        while (true) {
            const cruise_altitude = this.planner.plan_cruise();
            console.log(`Cruise altitude reached: ${cruise_altitude} meters`);
        }
    }
}

function main() {
    const initial_altitude = 1000;
    const target_altitude = 8000;
    const rate_of_climb = 150;
    const cruise_altitude = 10000;
    const trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb);
    const planner = new CruiseAltitudePlanner(trajectory, cruise_altitude);
    const flight_control = new FlightControl(planner);
    flight_control.execute_flight();
}

main();