class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;

    constructor(start_altitude: number, target_altitude: number, rate: number) {
        this.altitude = start_altitude;
        this.target = target_altitude;
        this.rate = rate;
    }

    update_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
            if (this.altitude > this.target) {
                this.altitude = this.target;
            }
        }
        return this.altitude;
    }

    is_at_target(): boolean {
        return this.altitude === this.target;
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;
    steps: number;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
        this.steps = 0;
    }

    plan(): void {
        while (!this.trajectory.is_at_target()) {
            const current_altitude = this.trajectory.update_altitude();
            this.steps += 1;
            console.log(`Step ${this.steps}: Altitude = ${current_altitude}`);
        }
    }
}

function main(): void {
    const start = 1000;
    const target = 35000;
    const rate = 1500;
    const trajectory = new FlightTrajectory(start, target, rate);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan();
    console.log(`Reached target altitude in ${planner.steps} steps.`);
}

main();