class FlightTrajectory {
    altitude: number;
    rate_of_climb: number;
    cruise_altitude: number;
    descent_rate: number;
    status: string;

    constructor(initial_altitude: number, rate_of_climb: number, cruise_altitude: number, descent_rate: number) {
        this.altitude = initial_altitude;
        this.rate_of_climb = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
        this.descent_rate = descent_rate;
        this.status = 'climbing';
    }

    update_altitude() {
        if (this.status === 'climbing') {
            if (this.altitude + this.rate_of_climb < this.cruise_altitude) {
                this.altitude += this.rate_of_climb;
            } else {
                this.altitude = this.cruise_altitude;
                this.status = 'cruising';
            }
        } else if (this.status === 'cruising') {
            // Do nothing
        } else if (this.status === 'descending') {
            if (this.altitude - this.descent_rate > 0) {
                this.altitude -= this.descent_rate;
            } else {
                this.altitude = 0;
                this.status = 'landed';
            }
        }
    }

    is_landed() {
        return this.status === 'landed';
    }
}

class FlightPlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan_flight() {
        while (!this.trajectory.is_landed()) {
            this.trajectory.update_altitude();
            this.log_status();
        }
    }

    log_status() {
        console.log(`Altitude: ${this.trajectory.altitude}, Status: ${this.trajectory.status}`);
    }
}

function main() {
    const initial_altitude = 0;
    const rate_of_climb = 1000;
    const cruise_altitude = 30000;
    const descent_rate = 500;
    const trajectory = new FlightTrajectory(initial_altitude, rate_of_climb, cruise_altitude, descent_rate);
    const planner = new FlightPlanner(trajectory);
    planner.plan_flight();
}

main();