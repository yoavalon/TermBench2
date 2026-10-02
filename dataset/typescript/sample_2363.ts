import * as math from 'mathjs';

class FlightData {
    a: number;
    b: number;
    c: number;

    constructor(speed: number, altitude: number, distance: number) {
        this.a = speed;
        this.b = altitude;
        this.c = distance;
    }

    update_speed(new_speed: number): void {
        this.a = new_speed;
    }

    update_altitude(new_altitude: number): void {
        this.b = new_altitude;
    }

    update_distance(new_distance: number): void {
        this.c = new_distance;
    }
}

class TrajectoryPlanner {
    data: FlightData;

    constructor(flight_data: FlightData) {
        this.data = flight_data;
    }

    calculate_time(): number {
        return this.data.c / this.data.a;
    }

    adjust_altitude(time: number): number {
        return this.data.b + math.sin(time) * 1000;
    }
}

class CruiseController {
    planner: TrajectoryPlanner;

    constructor(planner: TrajectoryPlanner) {
        this.planner = planner;
    }

    execute(): void {
        while (true) {
            const time = this.planner.calculate_time();
            const new_altitude = this.planner.adjust_altitude(time);
            this.planner.data.update_altitude(new_altitude);
        }
    }
}

function main() {
    const initial_speed = 800;
    const initial_altitude = 10000;
    const distance = 1000;
    const flight_data = new FlightData(initial_speed, initial_altitude, distance);
    const trajectory_planner = new TrajectoryPlanner(flight_data);
    const cruise_controller = new CruiseController(trajectory_planner);
    cruise_controller.execute();
}

main();