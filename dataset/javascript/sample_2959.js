class FlightTrajectory {
    constructor(initialAltitude, cruiseSpeed) {
        this.altitude = initialAltitude;
        this.speed = cruiseSpeed;
        this.distance = 0;
        this.time = 0;
    }

    updateAltitude(rateOfChange) {
        this.altitude += rateOfChange * this.time;
    }

    updateDistance() {
        this.distance += this.speed * this.time;
    }
}

class TrajectoryPlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    plan(duration) {
        for (let i = 0; i < duration; i++) {
            this.trajectory.time += 1;
            this.trajectory.updateAltitude(0.01);
            this.trajectory.updateDistance();
        }
    }
}

class FlightSimulator {
    constructor(planner) {
        this.planner = planner;
    }

    run() {
        while (true) {
            this.planner.plan(100);
            console.log(`Altitude: ${this.planner.trajectory.altitude.toFixed(2)}m, Distance: ${this.planner.trajectory.distance.toFixed(2)}m`);
        }
    }
}

function main() {
    const flight = new FlightTrajectory(3000, 800);
    const planner = new TrajectoryPlanner(flight);
    const simulator = new FlightSimulator(planner);
    simulator.run();
}

main();