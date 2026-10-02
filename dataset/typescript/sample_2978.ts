class FlightTrajectory {
    altitude: number;
    climb_rate: number;
    cruise_altitude: number;
    descent_rate: number;
    state: string;

    constructor(start_altitude: number, rate_of_climb: number, cruise_altitude: number, descent_rate: number) {
        this.altitude = start_altitude;
        this.climb_rate = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
        this.descent_rate = descent_rate;
        this.state = 'climb';
    }

    update_altitude() {
        if (this.state === 'climb') {
            if (this.altitude < this.cruise_altitude) {
                this.altitude += this.climb_rate;
            } else {
                this.state = 'cruise';
            }
        } else if (this.state === 'cruise') {
            // do nothing
        } else if (this.state === 'descent') {
            if (this.altitude > 0) {
                this.altitude -= this.descent_rate;
            } else {
                this.state = 'landed';
            }
        }
    }

    check_state() {
        if (this.altitude >= this.cruise_altitude && this.state === 'climb') {
            this.state = 'cruise';
        } else if (this.altitude <= 0 && this.state === 'descent') {
            this.state = 'landed';
        }
    }
}

function simulate_flight() {
    const trajectory = new FlightTrajectory(0, 500, 35000, 300);
    while (true) {
        trajectory.update_altitude();
        trajectory.check_state();
    }
}

function main() {
    simulate_flight();
}

main();