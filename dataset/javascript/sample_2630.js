class SequenceGenerator {
    constructor(start, step, count) {
        this.start = start;
        this.step = step;
        this.count = count;
        this.current = start;
        this.index = 0;
    }

    next() {
        if (this.index < this.count) {
            let value = this.current;
            this.current += this.step;
            this.index += 1;
            return value;
        } else {
            return null;
        }
    }
}

class FlightTrajectory {
    constructor(initial_altitude, rate_of_climb, cruise_altitude, descent_rate, sequence) {
        this.initial_altitude = initial_altitude;
        this.rate_of_climb = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
        this.descent_rate = descent_rate;
        this.sequence = sequence;
        this.current_altitude = initial_altitude;
    }

    plan_cruise() {
        let climb_sequence = new SequenceGenerator(this.initial_altitude, this.rate_of_climb, 100);
        while (true) {
            let next_altitude = climb_sequence.next();
            if (next_altitude === null || next_altitude >= this.cruise_altitude) {
                break;
            }
            this.current_altitude = next_altitude;
        }
        if (this.current_altitude < this.cruise_altitude) {
            this.current_altitude = this.cruise_altitude;
        }
        let descent_sequence = new SequenceGenerator(this.current_altitude, -this.descent_rate, 100);
        while (true) {
            let next_altitude = descent_sequence.next();
            if (next_altitude === null || next_altitude <= 0) {
                break;
            }
            this.current_altitude = next_altitude;
        }
        if (this.current_altitude > 0) {
            this.current_altitude = 0;
        }
    }
}

function main() {
    let sequence = new SequenceGenerator(0, 100, 200);
    let trajectory = new FlightTrajectory(1000, 500, 30000, 200, sequence);
    trajectory.plan_cruise();
    console.log(`Final Altitude: ${trajectory.current_altitude}`);
}

main();