class FlightTrajectory {
    altitude: number;
    speed: number;
    heading: number;

    constructor(altitude: number, speed: number, heading: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
    }

    update_altitude(delta: number): void {
        this.altitude += delta;
    }

    adjust_heading(new_heading: number): void {
        this.heading = new_heading;
    }

    calculate_distance(time: number): number {
        return this.speed * time;
    }
}

class CruiseAltitudePlanner {
    current_altitude: number;
    target_altitude: number;
    rate_of_climb: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    plan_cruise(): void {
        while (this.current_altitude !== this.target_altitude) {
            this.current_altitude += this.rate_of_climb;
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        }
    }

    get_current_altitude(): number {
        return this.current_altitude;
    }
}

class FlightSimulation {
    trajectory: FlightTrajectory;
    planner: CruiseAltitudePlanner;

    constructor(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    simulate_flight(): void {
        this.planner.plan_cruise();
        const distance = this.trajectory.calculate_distance(100);
        this.trajectory.update_altitude(distance * 0.01);
        this.trajectory.adjust_heading(this.trajectory.heading + 5);
    }

    run(): void {
        while (true) {
            this.simulate_flight();
        }
    }
}

function main(): void {
    const trajectory = new FlightTrajectory(1000, 800, 90);
    const planner = new CruiseAltitudePlanner(1000, 30000, 100);
    const simulation = new FlightSimulation(trajectory, planner);
    simulation.run();
}

main();