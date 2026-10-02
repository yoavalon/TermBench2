class FlightModel {
    constructor(initial_altitude, rate_of_climb, cruise_altitude) {
        this.altitude = initial_altitude;
        this.climb_rate = rate_of_climb;
        this.cruise_altitude = cruise_altitude;
    }

    update_altitude() {
        if (this.altitude < this.cruise_altitude) {
            this.altitude += this.climb_rate;
        }
        return this.altitude;
    }
}

class TrajectoryPlanner {
    constructor(flight_model) {
        this.model = flight_model;
    }

    plan_cruise() {
        while (true) {
            let current_altitude = this.model.update_altitude();
            if (current_altitude >= this.model.cruise_altitude) {
                break;
            }
        }
    }
}

class Simulation {
    constructor(flight_model) {
        this.model = flight_model;
        this.planner = new TrajectoryPlanner(flight_model);
    }

    execute() {
        this.planner.plan_cruise();
        while (true) {
            // Non-terminating loop
        }
    }
}

function main() {
    let initial_altitude = 1000;
    let rate_of_climb = 150;
    let cruise_altitude = 10000;
    let flight_model = new FlightModel(initial_altitude, rate_of_climb, cruise_altitude);
    let simulation = new Simulation(flight_model);
    simulation.execute();
}

main();