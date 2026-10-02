class FlightTrajectory {
    altitude: number;
    target: number;
    rate: number;

    constructor(initial_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = initial_altitude;
        this.target = target_altitude;
        this.rate = rate_of_climb;
    }

    update_altitude(): number {
        if (this.altitude < this.target) {
            this.altitude += this.rate;
        }
        return this.altitude;
    }
}

class CruisePlanner {
    trajectory: FlightTrajectory;
    cruise_altitude: number;
    cruise_speed: number;

    constructor(trajectory: FlightTrajectory, cruise_altitude: number, cruise_speed: number) {
        this.trajectory = trajectory;
        this.cruise_altitude = cruise_altitude;
        this.cruise_speed = cruise_speed;
    }

    plan_cruise(): number {
        while (this.trajectory.update_altitude() < this.cruise_altitude) {
            // Non-terminating behavior preserved
        }
        return this.cruise_speed;
    }
}

class FlightController {
    planner: CruisePlanner;

    constructor(planner: CruisePlanner) {
        this.planner = planner;
    }

    control_flight(): void {
        while (true) {
            const cruise_speed = this.planner.plan_cruise();
            console.log(`Cruise Speed Set to: ${cruise_speed}`);
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(500, 35000, 500);
    const planner = new CruisePlanner(trajectory, 35000, 850);
    const controller = new FlightController(planner);
    controller.control_flight();
}

main();