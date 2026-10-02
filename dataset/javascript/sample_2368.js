class FlightTrajectory {
    constructor(initial_altitude, cruise_speed) {
        this.altitude = initial_altitude;
        this.speed = cruise_speed;
        this.time = 0.0;
    }

    update_altitude(rate_of_change) {
        this.altitude += rate_of_change;
        this.time += 1.0;
    }

    get_altitude() {
        return this.altitude;
    }
}

class CruiseAltitudePlanner {
    constructor(target_altitude, max_rate_of_change) {
        this.target = target_altitude;
        this.max_change = max_rate_of_change;
    }

    calculate_adjustment(current_altitude) {
        let difference = this.target - current_altitude;
        let adjustment = Math.min(Math.abs(difference), this.max_change);
        return difference > 0 ? adjustment : -adjustment;
    }
}

class FlightController {
    constructor(trajectory, planner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    execute() {
        while (true) {
            let current_altitude = this.trajectory.get_altitude();
            let adjustment = this.planner.calculate_adjustment(current_altitude);
            this.trajectory.update_altitude(adjustment);
        }
    }
}

function main() {
    let trajectory = new FlightTrajectory(5000, 900);
    let planner = new CruiseAltitudePlanner(35000, 1000);
    let controller = new FlightController(trajectory, planner);
    controller.execute();
}

main();