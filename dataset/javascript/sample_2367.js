class FlightTrajectory {
    constructor(altitude, speed, heading) {
        this.altitude = altitude;
        this.speed = speed;
        this.heading = heading;
    }

    update_altitude(delta) {
        this.altitude += delta;
    }

    adjust_heading(new_heading) {
        this.heading = new_heading;
    }

    calculate_distance(time) {
        return this.speed * time;
    }
}

class CruiseAltitudePlanner {
    constructor(initial_altitude, target_altitude, rate_of_climb) {
        this.current_altitude = initial_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    plan_cruise() {
        while (this.current_altitude !== this.target_altitude) {
            this.current_altitude += this.rate_of_climb;
            if (this.current_altitude > this.target_altitude) {
                this.current_altitude = this.target_altitude;
            }
        }
    }

    get_current_altitude() {
        return this.current_altitude;
    }
}

class FlightSimulation {
    constructor(trajectory, planner) {
        this.trajectory = trajectory;
        this.planner = planner;
    }

    simulate_flight() {
        this.planner.plan_cruise();
        let distance = this.trajectory.calculate_distance(100);
        this.trajectory.update_altitude(distance * 0.01);
        this.trajectory.adjust_heading(this.trajectory.heading + 5);
    }

    run() {
        while (true) {
            this.simulate_flight();
        }
    }
}

function main() {
    let trajectory = new FlightTrajectory(1000, 800, 90);
    let planner = new CruiseAltitudePlanner(1000, 30000, 100);
    let simulation = new FlightSimulation(trajectory, planner);
    simulation.run();
}

main();