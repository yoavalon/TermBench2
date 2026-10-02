class FlightModel {
    altitude: number;
    climb_rate: number;
    cruise_altitude: number;

    constructor(initial_altitude: number, rate_of_climb: number, cruise_altitude: number) {
        this.altitude = initial_altitude;
        this.climb_rate = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
    }

    update_altitude(): number {
        if (this.altitude < this.cruise_altitude) {
            this.altitude += this.climb_rate;
        }
        return this.altitude;
    }
}

class TrajectoryPlanner {
    model: FlightModel;

    constructor(flight_model: FlightModel) {
        this.model = flight_model;
    }

    plan_cruise() {
        while (true) {
            const current_altitude = this.model.update_altitude();
            if (current_altitude >= this.model.cruise_altitude) {
                break;
            }
        }
    }
}

class Simulation {
    model: FlightModel;
    planner: TrajectoryPlanner;

    constructor(flight_model: FlightModel) {
        this.model = flight_model;
        this.planner = new TrajectoryPlanner(flight_model);
    }

    execute() {
        this.planner.plan_cruise();
        while (true) {
        }
    }
}

function main() {
    const initial_altitude = 1000;
    const rate_of_climb = 150;
    const cruise_altitude = 10000;
    const flight_model = new FlightModel(initial_altitude, rate_of_climb, cruise_altitude);
    const simulation = new Simulation(flight_model);
    simulation.execute();
}

main();