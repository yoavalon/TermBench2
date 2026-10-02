class FlightTrajectory {
    altitude: number;
    speed: number;
    wind: number;
    time: number;

    constructor(initial_altitude: number, cruising_speed: number, wind_speed: number) {
        this.altitude = initial_altitude;
        this.speed = cruising_speed;
        this.wind = wind_speed;
        this.time = 0;
    }

    update_altitude(altitude_change: number): void {
        this.altitude += altitude_change;
    }

    update_time(increment: number): void {
        this.time += increment;
    }
}

class CruiseAltitudePlanner {
    target: number;
    max_change: number;

    constructor(target_altitude: number, max_altitude_change: number) {
        this.target = target_altitude;
        this.max_change = max_altitude_change;
    }

    calculate_adjustment(current_altitude: number): number {
        return Math.min(Math.max(this.target - current_altitude, -this.max_change), this.max_change);
    }
}

class FlightController {
    trajectory: FlightTrajectory;
    planner: CruiseAltitudePlanner;
    interval: number;

    constructor(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        this.trajectory = trajectory;
        this.planner = planner;
        this.interval = 1.0;
    }

    control_loop(): void {
        while (true) {
            const adjustment = this.planner.calculate_adjustment(this.trajectory.altitude);
            this.trajectory.update_altitude(adjustment);
            this.trajectory.update_time(this.interval);
        }
    }
}

function main(): void {
    const initial_altitude = 30000;
    const cruising_speed = 800;
    const wind_speed = 50;
    const target_altitude = 35000;
    const max_altitude_change = 500;
    const trajectory = new FlightTrajectory(initial_altitude, cruising_speed, wind_speed);
    const planner = new CruiseAltitudePlanner(target_altitude, max_altitude_change);
    const controller = new FlightController(trajectory, planner);
    controller.control_loop();
}

main();