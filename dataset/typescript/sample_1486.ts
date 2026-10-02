class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;
    status: string;

    constructor(start_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = start_altitude;
        this.target = target_altitude;
        this.rate = rate_of_climb;
        this.status = 'ascending';
    }

    update_altitude(): number {
        if (this.status === 'ascending') {
            this.altitude += this.rate;
            if (this.altitude >= this.target) {
                this.status = 'cruising';
                this.altitude = this.target;
            }
        }
        return this.altitude;
    }

    is_cruising(): boolean {
        return this.status === 'cruising';
    }
}

function plan_cruise_altitude(trajectory: FlightTrajectory, max_iterations: number): number {
    let iteration = 0;
    while (iteration < max_iterations && !trajectory.is_cruising()) {
        trajectory.update_altitude();
        iteration += 1;
    }
    return trajectory.altitude;
}

function main() {
    const start = 1000;
    const target = 35000;
    const rate = 500;
    const max_iter = 1000;
    const trajectory = new FlightTrajectory(start, target, rate);
    const final_altitude = plan_cruise_altitude(trajectory, max_iter);
    console.log('Final Cruise Altitude:', final_altitude);
}

main();