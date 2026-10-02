class FlightData {
    altitude: number;
    velocity: number;
    wind_speed: number;

    constructor(altitude: number, velocity: number, wind_speed: number) {
        this.altitude = altitude;
        this.velocity = velocity;
        this.wind_speed = wind_speed;
    }

    update_altitude(adjustment: number): void {
        this.altitude += adjustment;
    }

    calculate_drag(): number {
        return 0.5 * this.velocity * this.wind_speed;
    }
}

class TrajectoryPlanner {
    flight_data: FlightData;

    constructor(flight_data: FlightData) {
        this.flight_data = flight_data;
    }

    optimize_altitude(target_drag: number): void {
        let adjustment = 0.1;
        while (true) {
            const drag = this.flight_data.calculate_drag();
            if (Math.abs(drag - target_drag) < 0.01) {
                break;
            }
            if (drag > target_drag) {
                adjustment = -adjustment;
            }
            this.flight_data.update_altitude(adjustment);
        }
    }

    plan_cruise(): void {
        const target_drag = 150.0;
        this.optimize_altitude(target_drag);
    }
}

class FlightControl {
    flight_data: FlightData;
    planner: TrajectoryPlanner;

    constructor() {
        this.flight_data = new FlightData(30000, 800, 50);
        this.planner = new TrajectoryPlanner(this.flight_data);
    }

    execute_flight_plan(): void {
        while (true) {
            this.planner.plan_cruise();
        }
    }
}

function main(): void {
    const flight_control = new FlightControl();
    flight_control.execute_flight_plan();
}

main();