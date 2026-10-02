class FlightTrajectory {
    constructor(initial_altitude, target_altitude, step) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.step = step;
    }

    adjust_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.step;
        } else {
            this.altitude -= this.step;
        }
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    plan_altitude() {
        while (true) {
            const new_altitude = this.trajectory.adjust_altitude();
            if (Math.abs(new_altitude - this.trajectory.target) < this.trajectory.step) {
                break;
            }
        }
    }
}

class Simulation {
    constructor(planner) {
        this.planner = planner;
    }

    run() {
        while (true) {
            this.planner.plan_altitude();
        }
    }
}

function main() {
    const initial = 10000;
    const target = 30000;
    const step = 1000;
    const trajectory = new FlightTrajectory(initial, target, step);
    const planner = new CruiseAltitudePlanner(trajectory);
    const simulation = new Simulation(planner);
    simulation.run();
}

main();