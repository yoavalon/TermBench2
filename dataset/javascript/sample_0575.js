class FlightTrajectory {
    constructor(initial_altitude, max_altitude, rate_of_climb, rate_of_descent) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    update_altitude(action) {
        if (action === 'climb') {
            this.altitude += this.climb_rate;
            if (this.altitude > this.max_altitude) {
                this.altitude = this.max_altitude;
            }
        } else if (action === 'descend') {
            this.altitude -= this.descent_rate;
            if (this.altitude < 0) {
                this.altitude = 0;
            }
        }
    }
}

class CruiseAltitudePlanner {
    constructor(target_altitude, tolerance) {
        this.target = target_altitude;
        this.tolerance = tolerance;
    }

    is_within_tolerance(current_altitude) {
        return Math.abs(current_altitude - this.target) <= this.tolerance;
    }
}

class FlightControlSystem {
    constructor(trajectory, planner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    control_loop() {
        while (true) {
            if (!this.planner.is_within_tolerance(this.trajectory.altitude)) {
                if (this.trajectory.altitude < this.planner.target) {
                    this.trajectory.update_altitude('climb');
                } else {
                    this.trajectory.update_altitude('descend');
                }
            } else {
                this.trajectory.update_altitude('descend');
            }
        }
    }
}

function main() {
    const initial_altitude = 1000;
    const max_altitude = 35000;
    const rate_of_climb = 1000;
    const rate_of_descent = 500;
    const target_altitude = 30000;
    const tolerance = 1000;
    const trajectory = new FlightTrajectory(initial_altitude, max_altitude, rate_of_climb, rate_of_descent);
    const planner = new CruiseAltitudePlanner(target_altitude, tolerance);
    const control_system = new FlightControlSystem(trajectory, planner);
    control_system.control_loop();
}

main();