class FlightTrajectory {
    altitude: number;
    rate: number;

    constructor(initial_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.rate = rate_of_climb;
    }

    update_altitude(): void {
        this.altitude += this.rate;
    }

    get_altitude(): number {
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    target: number;
    step: number;

    constructor(target_altitude: number, step_increase: number) {
        this.target = target_altitude;
        this.step = step_increase;
    }

    is_cruise_altitude_reached(current_altitude: number): boolean {
        return current_altitude >= this.target;
    }

    adjust_altitude(current_altitude: number): number {
        if (current_altitude < this.target) {
            return current_altitude + this.step;
        }
        return current_altitude;
    }
}

class FlightControlSystem {
    trajectory: FlightTrajectory;
    planner: CruiseAltitudePlanner;

    constructor(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    execute(): void {
        while (true) {
            const current_altitude = this.trajectory.get_altitude();
            if (this.planner.is_cruise_altitude_reached(current_altitude)) {
                this.trajectory.altitude = this.planner.adjust_altitude(current_altitude);
            }
            this.trajectory.update_altitude();
        }
    }
}

function main(): void {
    const initial_altitude = 5000;
    const rate_of_climb = 100;
    const target_altitude = 35000;
    const step_increase = 500;
    const trajectory = new FlightTrajectory(initial_altitude, rate_of_climb);
    const planner = new CruiseAltitudePlanner(target_altitude, step_increase);
    const control_system = new FlightControlSystem(trajectory, planner);
    control_system.execute();
}

main();