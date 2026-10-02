class FlightTrajectory {
    constructor(initial_altitude, max_altitude, speed) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.speed = speed;
    }

    update_altitude(time) {
        this.altitude += this.speed * time;
        if (this.altitude > this.max_altitude) {
            this.altitude = this.max_altitude;
        }
    }
}

class CruiseAltitudePlanner {
    constructor(trajectory) {
        this.trajectory = trajectory;
        this.target_altitude = trajectory.max_altitude;
    }

    adjust_altitude(current_time) {
        if (this.trajectory.altitude < this.target_altitude) {
            const time_to_adjust = (this.target_altitude - this.trajectory.altitude) / this.trajectory.speed;
            if (current_time >= time_to_adjust) {
                this.trajectory.update_altitude(time_to_adjust);
            }
        }
    }
}

class TerminationChecker {
    constructor(trajectory, target_altitude) {
        this.trajectory = trajectory;
        this.target_altitude = target_altitude;
    }

    check() {
        return this.trajectory.altitude >= this.target_altitude;
    }
}

function main() {
    const initial_altitude = 1000;
    const max_altitude = 30000;
    const speed = 1500;
    const trajectory = new FlightTrajectory(initial_altitude, max_altitude, speed);
    const planner = new CruiseAltitudePlanner(trajectory);
    const checker = new TerminationChecker(trajectory, max_altitude);
    let current_time = 0;
    const time_step = 10;
    while (!checker.check()) {
        planner.adjust_altitude(current_time);
        current_time += time_step;
    }
    console.log('Cruise altitude reached.');
}

main();