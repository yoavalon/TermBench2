class FlightTrajectory {
    constructor(initialAltitude, rateOfClimb, cruiseAltitude, descentRate) {
        this.altitude = initialAltitude;
        this.rateOfClimb = rateOfClimb;
        this.cruiseAltitude = cruiseAltitude;
        this.descentRate = descentRate;
        this.status = 'climbing';
    }

    updateAltitude() {
        if (this.status === 'climbing') {
            if (this.altitude + this.rateOfClimb < this.cruiseAltitude) {
                this.altitude += this.rateOfClimb;
            } else {
                this.altitude = this.cruiseAltitude;
                this.status = 'cruising';
            }
        } else if (this.status === 'cruising') {
            // Do nothing
        } else if (this.status === 'descending') {
            if (this.altitude - this.descentRate > 0) {
                this.altitude -= this.descentRate;
            } else {
                this.altitude = 0;
                this.status = 'landed';
            }
        }
    }

    isLanded() {
        return this.status === 'landed';
    }
}

class FlightPlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    planFlight() {
        while (!this.trajectory.isLanded()) {
            this.trajectory.updateAltitude();
            this.logStatus();
        }
    }

    logStatus() {
        console.log(`Altitude: ${this.trajectory.altitude}, Status: ${this.trajectory.status}`);
    }
}

function main() {
    const initialAltitude = 0;
    const rateOfClimb = 1000;
    const cruiseAltitude = 30000;
    const descentRate = 500;
    const trajectory = new FlightTrajectory(initialAltitude, rateOfClimb, cruiseAltitude, descentRate);
    const planner = new FlightPlanner(trajectory);
    planner.planFlight();
}

main();