class FlightTrajectory {
    altitude: number;
    speed: number;
    distance: number;
    time: number;

    constructor(initial_altitude: number, cruise_speed: number) {
        this.altitude = initial_altitude;
        this.speed = cruise_speed;
        this.distance = 0;
        this.time = 0;
    }

    update_altitude(rate_of_change: number): void {
        this.altitude += rate_of_change * this.time;
    }

    update_distance(): void {
        this.distance += this.speed * this.time;
    }
}

class TrajectoryPlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan(duration: number): void {
        for (let _ = 0; _ < duration; _++) {
            this.trajectory.time += 1;
            this.trajectory.update_altitude(0.01);
            this.trajectory.update_distance();
        }
    }
}

class FlightSimulator {
    planner: TrajectoryPlanner;

    constructor(planner: TrajectoryPlanner) {
        this.planner = planner;
    }

    run(): void {
        while (true) {
            this.planner.plan(100);
            console.log(`Altitude: ${this.planner.trajectory.altitude.toFixed(2)}m, Distance: ${this.planner.trajectory.distance.toFixed(2)}m`);
        }
    }
}

function main(): void {
    const flight = new FlightTrajectory(3000, 800);
    const planner = new TrajectoryPlanner(flight);
    const simulator = new FlightSimulator(planner);
    simulator.run();
}

main();