class FlightTrajectory {
    constructor(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    adjust_altitude() {
        if (this.altitude < this.target) {
            this.altitude += this.climb_rate;
        } else if (this.altitude > this.target) {
            this.altitude -= this.descent_rate;
        }
        return this.altitude;
    }

    stabilize_altitude() {
        while (Math.abs(this.altitude - this.target) > 0.1) {
            this.adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    plan() {
        while (true) {
            this.trajectory.stabilize_altitude();
            console.log(`Current Altitude: ${this.trajectory.altitude.toFixed(2)}`);
        }
    }
}

function main() {
    const initial = 5000.0;
    const target = 35000.0;
    const climb = 100.0;
    const descent = 50.0;
    const trajectory = new FlightTrajectory(initial, target, climb, descent);
    const planner = new CruiseAltitudePlanner(trajectory);
    planner.plan();
}

main();