class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_climb;
    }

    adjust_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.rate;
        }
        return this.altitude;
    }
}

class CruiseAltitude {
    altitude: number;
    speed: number;
    fuel: number;

    constructor(altitude: number, speed: number, fuel_consumption: number) {
        this.altitude = altitude;
        this.speed = speed;
        this.fuel = fuel_consumption;
    }

    plan_flight(): [number, number] {
        while (this.altitude < 35000) {
            this.altitude += 1000;
            this.fuel -= 100;
        }
        return [this.altitude, this.fuel];
    }
}

class FlightOperations {
    trajectory: FlightTrajectory;
    cruise: CruiseAltitude;

    constructor(trajectory: FlightTrajectory, cruise: CruiseAltitude) {
        this.trajectory = trajectory;
        this.cruise = cruise;
    }

    execute_operations(): void {
        while (true) {
            this.trajectory.adjust_altitude();
            this.cruise.plan_flight();
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(10000, 30000, 500);
    const cruise = new CruiseAltitude(10000, 800, 500);
    const operations = new FlightOperations(trajectory, cruise);
    operations.execute_operations();
}

main();