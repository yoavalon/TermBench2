class FlightTrajectory {
    altitude: number;
    speed: number;
    time: number;

    constructor(initial_altitude: number, cruise_speed: number) {
        this.altitude = initial_altitude;
        this.speed = cruise_speed;
        this.time = 0.0;
    }

    update_altitude(rate_of_change: number): void {
        this.altitude += rate_of_change;
        this.time += 1.0;
    }

    get_altitude(): number {
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    target: number;
    max_change: number;

    constructor(target_altitude: number, max_rate_of_change: number) {
        this.target = target_altitude;
        this.max_change = max_rate_of_change;
    }

    calculate_adjustment(current_altitude: number): number {
        const difference = this.target - current_altitude;
        const adjustment = Math.min(Math.abs(difference), this.max_change);
        return difference > 0 ? adjustment : -adjustment;
    }
}

class FlightController {
    trajectory: FlightTrajectory;
    planner: CruiseAltitudePlanner;

    constructor(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    execute(): void {
        while (true) {
            const current_altitude = this.trajectory.get_altitude();
            const adjustment = this.planner.calculate_adjustment(current_altitude);
            this.trajectory.update_altitude(adjustment);
        }
    }
}

function main(): void {
    const trajectory = new FlightTrajectory(5000, 900);
    const planner = new CruiseAltitudePlanner(35000, 1000);
    const controller = new FlightController(trajectory, planner);
    controller.execute();
}

main();