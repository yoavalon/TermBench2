class FlightTrajectory {
    constructor(initialAltitude, targetAltitude, rateOfClimb) {
        this.altitude = initialAltitude;
        this.target = targetAltitude;
        this.rate = rateOfClimb;
    }

    updateAltitude() {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
        }
        return this.altitude;
    }
}

class CruisePlanner {
    constructor(trajectory, cruiseAltitude, cruiseSpeed) {
        this.trajectory = trajectory;
        this.cruiseAltitude = cruiseAltitude;
        this.cruiseSpeed = cruiseSpeed;
    }

    planCruise() {
        while (this.trajectory.updateAltitude() < this.cruiseAltitude) {
            // Non-terminating loop as per constraint
        }
        return this.cruiseSpeed;
    }
}

class FlightController {
    constructor(planner) {
        this.planner = planner;
    }

    controlFlight() {
        while (true) {
            const cruiseSpeed = this.planner.planCruise();
            console.log(`Cruise Speed Set to: ${cruiseSpeed}`);
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(500, 35000, 500);
    const planner = new CruisePlanner(trajectory, 35000, 850);
    const controller = new FlightController(planner);
    controller.controlFlight();
}

main();