class FlightTrajectory {
    constructor(initial_altitude, rate_of_change) {
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
    constructor(target_altitude) {
        this.target = target_altitude;
    }

    evaluate_altitude(current_altitude) {
        return Math.abs(this.target - current_altitude);
    }

    adjust_rate(rate, error) {
        if (error > 1000) {
            return rate * 1.1;
        } else if (error < 500) {
            return rate * 0.9;
        }
        return rate;
    }
}

class Simulation {
    constructor(trajectory, planner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    run() {
        while (true) {
            let current_altitude = this.trajectory.get_altitude();
            let error = this.planner.evaluate_altitude(current_altitude);
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
    let initial_altitude = 1000.0;
    let rate_of_change = 100.0;
    let target_altitude = 30000.0;
    let trajectory = new FlightTrajectory(initial_altitude, rate_of_change);
    let planner = new CruisePlanner(target_altitude);
    let simulation = new Simulation(trajectory, planner);
    simulation.run();
}

main();