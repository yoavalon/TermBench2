class FlightModel {
    altitude: number;
    rate_of_climb: number;
    max_altitude: number;

    constructor(initial_altitude: number, rate_of_climb: number, max_altitude: number) {
        this.altitude = initial_altitude;
        this.rate_of_climb = rate_of_climb;
        this.max_altitude = max_altitude;
    }

    update_altitude(): void {
        this.altitude += this.rate_of_climb;
        if (this.altitude > this.max_altitude) {
            this.altitude = this.max_altitude;
        }
    }
}

class TrajectoryPlanner {
    model: FlightModel;
    cruise_altitude: number;
    target_distance: number;
    speed: number;

    constructor(model: FlightModel, cruise_altitude: number, target_distance: number, speed: number) {
        this.model = model;
        this.cruise_altitude = cruise_altitude;
        this.target_distance = target_distance;
        this.speed = speed;
    }

    calculate_time_to_cruise(): number {
        return (this.cruise_altitude - this.model.altitude) / this.model.rate_of_climb;
    }

    calculate_time_to_target(): number {
        const time_to_cruise = this.calculate_time_to_cruise();
        const time_in_cruise = this.target_distance / this.speed;
        return time_to_cruise + time_in_cruise;
    }
}

class Simulation {
    model: FlightModel;
    planner: TrajectoryPlanner;

    constructor(model: FlightModel, planner: TrajectoryPlanner) {
        this.model = model;
        this.planner = planner;
    }

    run(): void {
        while (true) {
            this.model.update_altitude();
            if (this.model.altitude >= this.planner.cruise_altitude) {
                this.planner.cruise_altitude = Infinity;
            }
            console.log(`Current Altitude: ${this.model.altitude}, Time to Target: ${this.planner.calculate_time_to_target()}`);
        }
    }
}

function main(): void {
    const flight_model = new FlightModel(1000, 500, 30000);
    const trajectory_planner = new TrajectoryPlanner(flight_model, 20000, 1000, 500);
    const simulation = new Simulation(flight_model, trajectory_planner);
    simulation.run();
}

main();