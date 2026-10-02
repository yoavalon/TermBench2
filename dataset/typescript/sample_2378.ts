class FlightTrajectory {
    altitude: number;
    rate: number;

    constructor(initial_altitude: number, rate_of_change: number) {
        this.altitude = initial_altitude;
        this.rate = rate_of_change;
    }

    update_altitude() {
        this.altitude += this.rate;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruisePlanner {
    target: number;

    constructor(target_altitude: number) {
        this.target = target_altitude;
    }

    evaluate_altitude(current_altitude: number) {
        return Math.abs(this.target - current_altitude);
    }

    adjust_rate(rate: number, error: number) {
        if (error > 1000) {
            return rate * 1.1;
        } else if (error < 500) {
            return rate * 0.9;
        }
        return rate;
    }
}

class Simulation {
    trajectory: FlightTrajectory;
    planner: CruisePlanner;

    constructor(trajectory: FlightTrajectory, planner: CruisePlanner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    run() {
        while (true) {
            const current_altitude = this.trajectory.get_altitude();
            const error = this.planner.evaluate_altitude(current_altitude);
            if (error < 10) {
                this.trajectory.rate = 0;
            } else {
                this.trajectory.rate = this.planner.adjust_rate(this.trajectory.rate, error);
            }
            this.trajectory.update_altitude();
        }
    }
}

function main() {
    const initial_altitude = 1000.0;
    const rate_of_change = 100.0;
    const target_altitude = 30000.0;
    const trajectory = new FlightTrajectory(initial_altitude, rate_of_change);
    const planner = new CruisePlanner(target_altitude);
    const simulation = new Simulation(trajectory, planner);
    simulation.run();
}

main();