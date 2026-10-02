class FlightTrajectory {
    altitude: number;
    max_altitude: number;
    climb_rate: number;
    descent_rate: number;

    constructor(initial_altitude: number, max_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.altitude = initial_altitude;
        this.max_altitude = max_altitude;
        this.climb_rate = rate_of_climb;
        this.descent_rate = rate_of_descent;
    }

    update_altitude(action: string) {
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
    target: number;
    tolerance: number;

    constructor(target_altitude: number, tolerance: number) {
        this.target = target_altitude;
        this.tolerance = tolerance;
    }

    is_within_tolerance(current_altitude: number): boolean {
        return Math.abs(current_altitude - this.target) <= this.tolerance;
    }
}

class FlightControlSystem {
    trajectory: FlightTrajectory;
    planner: CruiseAltitudePlanner;

    constructor(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
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