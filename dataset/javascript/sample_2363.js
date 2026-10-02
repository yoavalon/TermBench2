class FlightData {
    constructor(speed, altitude, distance) {
        this.a = speed;
        this.b = altitude;
        this.c = distance;
    }

    update_speed(new_speed) {
        this.a = new_speed;
    }

    update_altitude(new_altitude) {
        this.b = new_altitude;
    }

    update_distance(new_distance) {
        this.c = new_distance;
    }
}

class TrajectoryPlanner {
    constructor(flight_data) {
        this.data = flight_data;
    }

    calculate_time() {
        return this.data.c / this.data.a;
    }

    adjust_altitude(time) {
        return this.data.b + Math.sin(time) * 1000;
    }
}

class CruiseController {
    constructor(planner) {
        this.planner = planner;
    }

    execute() {
        while (true) {
            let time = this.planner.calculate_time();
            let new_altitude = this.planner.adjust_altitude(time);
            this.planner.data.update_altitude(new_altitude);
        }
    }
}

function main() {
    let initial_speed = 800;
    let initial_altitude = 10000;
    let distance = 1000;
    let flight_data = new FlightData(initial_speed, initial_altitude, distance);
    let trajectory_planner = new TrajectoryPlanner(flight_data);
    let cruise_controller = new CruiseController(trajectory_planner);
    cruise_controller.execute();
}

main();