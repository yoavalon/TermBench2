class FlightTrajectory {
    altitude: number;
    speed: number;
    adjustment_needed: boolean;

    constructor(initial_altitude: number, speed: number) {
        this.altitude = initial_altitude;
        this.speed = speed;
        this.adjustment_needed = true;
    }

    assess_altitude() {
        if (this.altitude < 10000) {
            this.adjustment_needed = true;
        } else {
            this.adjustment_needed = false;
        }
    }

    adjust_altitude() {
        if (this.adjustment_needed) {
            this.altitude += 1000;
            this.adjustment_needed = false;
        }
    }
}

class CruiseControl {
    trajectory: FlightTrajectory;
    target_speed: number;

    constructor(trajectory: FlightTrajectory, target_speed: number) {
        this.trajectory = trajectory;
        this.target_speed = target_speed;
    }

    monitor_speed() {
        if (this.trajectory.speed < this.target_speed) {
            this.trajectory.speed += 100;
        } else if (this.trajectory.speed > this.target_speed) {
            this.trajectory.speed -= 100;
        }
    }
}

class FlightSimulation {
    trajectory: FlightTrajectory;
    cruise_control: CruiseControl;

    constructor(trajectory: FlightTrajectory, cruise_control: CruiseControl) {
        this.trajectory = trajectory;
        this.cruise_control = cruise_control;
    }

    run_simulation() {
        while (true) {
            this.trajectory.assess_altitude();
            this.trajectory.adjust_altitude();
            this.cruise_control.monitor_speed();
        }
    }
}

function main() {
    const trajectory = new FlightTrajectory(5000, 500);
    const cruise_control = new CruiseControl(trajectory, 600);
    const simulation = new FlightSimulation(trajectory, cruise_control);
    simulation.run_simulation();
}

main();