class FlightTrajectory {
    constructor(start_altitude, target_altitude, rate) {
        this.altitude = start_altitude;
        this.target = target_altitude;
        this.rate = rate;
    }

    update_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
            if (this.altitude > this.target) {
                this.altitude = this.target;
            }
        }
        return this.altitude;
    }

    is_at_target() {
        return this.altitude === this.target;
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
        this.steps = 0;
    }

    plan() {
        while (!this.trajectory.is_at_target()) {
            const current_altitude = this.trajectory.update_altitude();
            this.steps += 1;
            console.log(`Step ${this.steps}: Altitude = ${current_altitude}`);
        }
    }
}

function main() {
    const start = 1000;
    const target = 35000;
    const rate = 1500;
    const trajectory = new FlightTrajectory(start, target, rate);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan();
    console.log(`Reached target altitude in ${planner.steps} steps.`);
}

main();