class FlightTrajectory {
    current_altitude: number;
    target_altitude: number;
    rate_of_climb: number;
    rate_of_descent: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
        this.rate_of_descent = rate_of_descent;
    }

    climb() {
        if (this.current_altitude < this.target_altitude) {
            this.current_altitude += this.rate_of_climb;
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        }
    }

    descend() {
        if (this.current_altitude > this.target_altitude) {
            this.current_altitude -= this.rate_of_descent;
            if (this.current_altitude < this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        }
    }

    adjust_altitude() {
        if (this.current_altitude < this.target_altitude) {
            this.climb();
        } else if (this.current_altitude > this.target_altitude) {
            this.descend();
        }
    }
}

class CruiseAltitudeManager {
    trajectory: FlightTrajectory;
    cruise_altitude: number;
    altitude_changes: number[];

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
        this.cruise_altitude = trajectory.target_altitude;
        this.altitude_changes = [];
    }

    update_cruise_altitude(new_altitude: number) {
        this.cruise_altitude = new_altitude;
        this.trajectory.target_altitude = new_altitude;
    }

    log_altitude_change() {
        this.altitude_changes.push(this.trajectory.current_altitude);
    }

    manage_cruise() {
        this.trajectory.adjust_altitude();
        this.log_altitude_change();
    }
}

class FlightSimulation {
    trajectory: FlightTrajectory;
    cruise_manager: CruiseAltitudeManager;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number, rate_of_descent: number) {
        this.trajectory = new FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, rate_of_descent);
        this.cruise_manager = new CruiseAltitudeManager(this.trajectory);
    }

    simulate_flight() {
        while (true) {
            this.cruise_manager.manage_cruise();
        }
    }
}

function main() {
    const flight_sim = new FlightSimulation(5000, 35000, 500, 300);
    flight_sim.simulate_flight();
}

main();