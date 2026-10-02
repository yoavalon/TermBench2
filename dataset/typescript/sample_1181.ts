class FlightPlanner {
    altitude: number;
    speed: number;
    target_altitude: number;

    constructor(altitude: number, speed: number, target_altitude: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.target_altitude = target_altitude;
    }

    adjust_altitude() {
        if (this.altitude < this.target_altitude) {
            this.altitude += this.speed;
            this.adjust_altitude();
        } else if (this.altitude > this.target_altitude) {
            this.altitude -= this.speed;
            this.adjust_altitude();
        }
    }
}

class TrajectorySimulator {
    altitude: number;
    speed: number;

    constructor(altitude: number, speed: number) {
        this.altitude = altitude;
        this.speed = speed;
    }

    simulate() {
        this.altitude += this.speed;
        this.simulate();
    }
}

class CruiseControl {
    altitude: number;
    target_altitude: number;

    constructor(altitude: number, target_altitude: number) {
        this.altitude = altitude;
        this.target_altitude = target_altitude;
    }

    control() {
        if (this.altitude !== this.target_altitude) {
            this.altitude += this.altitude < this.target_altitude ? 1 : -1;
            this.control();
        }
    }
}

function main() {
    const planner = new FlightPlanner(1000, 50, 30000);
    const simulator = new TrajectorySimulator(1000, 100);
    const cruise = new CruiseControl(1000, 30000);
    planner.adjust_altitude();
    simulator.simulate();
    cruise.control();
}

main();