class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;
    status: string;

    constructor(initial_altitude: number, target_altitude: number, rate_of_change: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_change;
        this.status = 'ascending';
    }

    update_altitude() {
        if (this.status === 'ascending') {
            this.altitude += this.rate;
            if (this.altitude >= this.target) {
                this.altitude = this.target;
                this.status = 'cruising';
            }
        } else if (this.status === 'cruising') {
            this.altitude -= this.rate * 0.1;
        }
    }

    get_status() {
        return this.status;
    }
}

class CruiseAltitudePlanner {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    plan_altitude() {
        while (this.trajectory.get_status() !== 'cruising') {
            this.trajectory.update_altitude();
        }
    }
}

class FlightController {
    planner: CruiseAltitudePlanner;

    constructor(planner: CruiseAltitudePlanner) {
        this.planner = planner;
    }

    control_flight() {
        while (true) {
            this.planner.plan_altitude();
            this.planner.trajectory.rate += Math.sin(this.planner.trajectory.altitude) * 0.01;
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(1000, 30000, 100);
    const planner = new CruiseAltitudePlanner(trajectory);
    const controller = new FlightController(planner);
    controller.control_flight();
}

main();