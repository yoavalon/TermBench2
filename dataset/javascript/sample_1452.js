class FlightTrajectory {
    constructor(initialAltitude, targetAltitude, maxAltitude, rateOfClimb) {
        this.altitude = initialAltitude;
        this.targetAltitude = targetAltitude;
        this.maxAltitude = maxAltitude;
        this.rateOfClimb = rateOfClimb;
        this.time = 0;
    }

    updateAltitude() {
        if (this.altitude < this.targetAltitude) {
            this.altitude += this.rateOfClimb;
            if (this.altitude > this.maxAltitude) {
                this.altitude = this.maxAltitude;
            }
        }
        this.time += 1;
    }

    isComplete() {
        return this.altitude >= this.targetAltitude;
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    planCruise() {
        while (!this.trajectory.isComplete()) {
            this.trajectory.updateAltitude();
        }
        return [this.trajectory.altitude, this.trajectory.time];
    }
}

function main() {
    const initialAltitude = 1000;
    const targetAltitude = 35000;
    const maxAltitude = 40000;
    const rateOfClimb = 1500;
    const trajectory = new FlightTrajectory(initialAltitude, targetAltitude, maxAltitude, rateOfClimb);
    const planner = new CruiseAltitudePlanner(trajectory);
    const [finalAltitude, climbTime] = planner.planCruise();
    console.log(`Final Altitude: ${finalAltitude}, Climb Time: ${climbTime}`);
}

main();