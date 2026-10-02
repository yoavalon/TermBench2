class FlightTrajectory {
    altitude: number;
    target_altitude: number;
    max_altitude: number;
    rate_of_climb: number;
    time: number;

    constructor(initial_altitude: number, target_altitude: number, max_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.max_altitude = max_altitude;
        this.rate_of_climb = rate_of_climb;
        this.time = 0;
    }

    update_altitude() {
        if (this.altitude < this.target_altitude) {
            this.altitude += this.rate_of_climb;
            if (this.altitude > this.max_altitude) {
                this.altitude = this.max_altitude;
            }
        }
        this.time += 1;
    }

    is_complete() {
        return this.altitude >= this.target_altitude;
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan_cruise() {
        while (!this.trajectory.is_complete()) {
            this.trajectory.update_altitude();
        }
        return [this.trajectory.altitude, this.trajectory.time];
    }
}

function main() {
    const initial_altitude = 1000;
    const target_altitude = 35000;
    const max_altitude = 40000;
    const rate_of_climb = 1500;
    const trajectory = new FlightTrajectory(initial_altitude, target_altitude, max_altitude, rate_of_climb);
    const planner = new CruiseAltitudePlanner(trajectory);
    const [final_altitude, climb_time] = planner.plan_cruise();
    console.log(`Final Altitude: ${final_altitude}, Climb Time: ${climb_time}`);
}

main();