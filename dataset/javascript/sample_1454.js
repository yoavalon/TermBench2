class FlightTrajectory {
    constructor(start_altitude, target_altitude, rate_of_climb) {
        this.current_altitude = start_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
        this.cruise_altitude = null;
    }

    update_altitude() {
        if (this.current_altitude < this.target_altitude) {
            this.current_altitude += this.rate_of_climb;
            if (this.current_altitude >= this.target_altitude) {
                this.current_altitude = this.target_altitude;
                this.set_cruise_altitude();
            }
        }
    }

    set_cruise_altitude() {
        this.cruise_altitude = this.current_altitude;
    }

    get_current_altitude() {
        return this.current_altitude;
    }

    is_at_target() {
        return this.current_altitude === this.target_altitude;
    }
}

class AltitudePlanner {
    constructor(trajectory, target_altitude) {
        this.trajectory = trajectory;
        this.target_altitude = target_altitude;
    }

    plan_cruise_altitude() {
        while (!this.trajectory.is_at_target()) {
            this.trajectory.update_altitude();
        }
        return this.trajectory.get_current_altitude();
    }
}

function main() {
    const start_altitude = 1000;
    const target_altitude = 35000;
    const rate_of_climb = 500;
    const trajectory = new FlightTrajectory(start_altitude, target_altitude, rate_of_climb);
    const planner = new AltitudePlanner(trajectory, target_altitude);
    const cruise_altitude = planner.plan_cruise_altitude();
    console.log(`Cruise Altitude Set: ${cruise_altitude} feet`);
}

main();