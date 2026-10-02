class FlightTrajectory {
    constructor(initial_altitude, target_altitude, rate_of_climb, descent_rate) {
        this.a = initial_altitude;
        this.t = target_altitude;
        this.r = rate_of_climb;
        this.d = descent_rate;
        this.current_altitude = initial_altitude;
        this.is_ascent = true;
    }

    adjust_altitude() {
        if (this.is_ascent) {
            if (this.current_altitude < this.t) {
                this.current_altitude += this.r;
            } else {
                this.is_ascent = false;
            }
        } else if (this.current_altitude > this.t) {
            this.current_altitude -= this.d;
        }
    }

    get_current_altitude() {
        return this.current_altitude;
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    plan_cruise() {
        while (true) {
            this.trajectory.adjust_altitude();
            const current_altitude = this.trajectory.get_current_altitude();
            if (current_altitude === this.trajectory.t) {
                this.trajectory.is_ascent = true;
            }
        }
    }
}

class FlightControlSystem {
    constructor(planner) {
        this.planner = planner;
    }

    execute() {
        while (true) {
            this.planner.plan_cruise();
        }
    }
}

function main() {
    const initial_altitude = 5000.0;
    const target_altitude = 35000.0;
    const rate_of_climb = 100.0;
    const descent_rate = 50.0;
    const trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, descent_rate);
    const planner = new CruiseAltitudePlanner(trajectory);
    const control_system = new FlightControlSystem(planner);
    control_system.execute();
}

main();