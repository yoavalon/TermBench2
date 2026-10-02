class FlightTrajectory {
    altitude: number;
    target: number;
    step: number;

    constructor(initial_altitude: number, target_altitude: number, step: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.step = step;
    }

    adjust_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.step;
        } else {
            this.altitude -= this.step;
        }
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan_altitude(): void {
        while (true) {
            const new_altitude = this.trajectory.adjust_altitude();
            if (Math.abs(new_altitude - this.trajectory.target) < this.trajectory.step) {
                break;
            }
        }
    }
}

class Simulation {
    planner: CruiseAltitudePlanner;

    constructor(planner: CruiseAltitudePlanner) {
        this.planner = planner;
    }

    run(): void {
        while (true) {
            this.planner.plan_altitude();
        }
    }
}

function main(): void {
    const initial = 10000;
    const target = 30000;
    const step = 1000;
    const trajectory = new FlightTrajectory(initial, target, step);
    const planner = new CruiseAltitudePlanner(trajectory);
    const simulation = new Simulation(planner);
    simulation.run();
}

main();