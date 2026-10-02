class FlightTrajectory {
    constructor(initial_altitude, target_altitude, rate_of_climb) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_climb;
    }

    adjust_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.rate;
        }
        return this.altitude;
    }
}

class CruiseAltitude {
    constructor(altitude, speed, fuel_consumption) {
        this.altitude = altitude;
        this.speed = speed;
        this.fuel = fuel_consumption;
    }

    plan_flight() {
        while (this.altitude < 35000) {
            this.altitude += 1000;
            this.fuel -= 100;
        }
        return [this.altitude, this.fuel];
    }
}

class FlightOperations {
    constructor(trajectory, cruise) {
        this.trajectory = trajectory;
        this.cruise = cruise;
    }

    execute_operations() {
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