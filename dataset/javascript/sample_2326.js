class FlightParameters {
    constructor(speed, altitude, heading, wind_speed, wind_heading) {
        this.speed = speed;
        this.altitude = altitude;
        this.heading = heading;
        this.wind_speed = wind_speed;
        this.wind_heading = wind_heading;
    }

    calculate_drift() {
        let angle_diff = this.wind_heading - this.heading;
        let drift_x = this.wind_speed * Math.abs(angle_diff) / 360;
        let drift_y = this.wind_speed * Math.abs(90 - angle_diff) / 360;
        return [drift_x, drift_y];
    }
}

class TrajectoryPlanner {
    constructor(parameters) {
        this.parameters = parameters;
    }

    adjust_altitude(target_altitude) {
        let current_alt = this.parameters.altitude;
        if (current_alt < target_altitude) {
            return current_alt + 100;
        } else if (current_alt > target_altitude) {
            return current_alt - 50;
        }
        return current_alt;
    }

    plan_trajectory(target_x, target_y) {
        let [drift_x, drift_y] = this.parameters.calculate_drift();
        let adjusted_x = target_x - drift_x;
        let adjusted_y = target_y - drift_y;
        return [adjusted_x, adjusted_y];
    }
}

class CruiseControl {
    constructor(planner) {
        this.planner = planner;
    }

    execute() {
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

function main() {
    let params = new FlightParameters(500, 25000, 45, 20, 90);
    let planner = new TrajectoryPlanner(params);
    let cruise_control = new CruiseControl(planner);
    cruise_control.execute();
}

main();