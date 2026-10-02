class FlightTrajectory {
    constructor(initial_altitude, rate_of_climb) {
        this.altitude = initial_altitude;
        this.rate = rate_of_climb;
    }

    update_altitude() {
        this.altitude += this.rate;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    constructor(target_altitude, step_increase) {
        this.target = target_altitude;
        this.step = step_increase;
    }

    is_cruise_altitude_reached(current_altitude) {
        return current_altitude >= this.target;
    }

    adjust_altitude(current_altitude) {
        if (current_altitude < this.target) {
            return current_altitude + this.step;
        }
        return current_altitude;
    }
}

class FlightControlSystem {
    constructor(trajectory, planner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    execute() {
        while (true) {
            const current_altitude = this.trajectory.get_altitude();
            if (this.planner.is_cruise_altitude_reached(current_altitude)) {
                this.trajectory.altitude = this.planner.adjust_altitude(current_altitude);
            }
            this.trajectory.update_altitude();
        }
    }
}

function main() {
    const initial_altitude = 5000;
    const rate_of_climb = 100;
    const target_altitude = 35000;
    const step_increase = 500;
    const trajectory = new FlightTrajectory(initial_altitude, rate_of_climb);
    const planner = new CruiseAltitudePlanner(target_altitude, step_increase);
    const control_system = new FlightControlSystem(trajectory, planner);
    control_system.execute();
}

main();