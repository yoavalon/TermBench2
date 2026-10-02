class FlightParameters {
    speed: number;
    altitude: number;
    heading: number;
    wind_speed: number;
    wind_heading: number;

    constructor(speed: number, altitude: number, heading: number, wind_speed: number, wind_heading: number) {
        this.speed = speed;
        this.altitude = altitude;
        this.heading = heading;
        this.wind_speed = wind_speed;
        this.wind_heading = wind_heading;
    }

    calculate_drift(): [number, number] {
        let angle_diff = this.wind_heading - this.heading;
        let drift_x = this.wind_speed * Math.abs(angle_diff) / 360;
        let drift_y = this.wind_speed * Math.abs(90 - angle_diff) / 360;
        return [drift_x, drift_y];
    }
}

class TrajectoryPlanner {
    parameters: FlightParameters;

    constructor(parameters: FlightParameters) {
        this.parameters = parameters;
    }

    adjust_altitude(target_altitude: number): number {
        let current_alt = this.parameters.altitude;
        if (current_alt < target_altitude) {
            return current_alt + 100;
        } else if (current_alt > target_altitude) {
            return current_alt - 50;
        }
        return current_alt;
    }

    plan_trajectory(target_x: number, target_y: number): [number, number] {
        let [drift_x, drift_y] = this.parameters.calculate_drift();
        let adjusted_x = target_x - drift_x;
        let adjusted_y = target_y - drift_y;
        return [adjusted_x, adjusted_y];
    }
}

class CruiseControl {
    planner: TrajectoryPlanner;

    constructor(planner: TrajectoryPlanner) {
        this.planner = planner;
    }

    execute(): void {
        let target_x = 1000;
        let target_y = 2000;
        let target_altitude = 30000;
        while (true) {
            this.planner.parameters.altitude = this.planner.adjust_altitude(target_altitude);
            let [x, y] = this.planner.plan_trajectory(target_x, target_y);
            console.log(`Current Coordinates: (${x}, ${y}), Altitude: ${this.planner.parameters.altitude}`);
        }
    }
}

function main(): void {
    let params = new FlightParameters(500, 25000, 45, 20, 90);
    let planner = new TrajectoryPlanner(params);
    let cruise_control = new CruiseControl(planner);
    cruise_control.execute();
}

main();