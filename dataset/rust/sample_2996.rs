struct FlightModel {
    altitude: i32,
    climb_rate: i32,
    cruise_altitude: i32,
}

impl FlightModel {
    fn new(initial_altitude: i32, rate_of_climb: i32, cruise_altitude: i32) -> FlightModel {
        FlightModel {
            altitude: initial_altitude,
            climb_rate: rate_of_climb,
            cruise_altitude: cruise_altitude,
        }
    }

    fn update_altitude(&mut self) -> i32 {
        if self.altitude < self.cruise_altitude {
            self.altitude += self.climb_rate;
        }
        self.altitude
    }
}

struct TrajectoryPlanner {
    model: FlightModel,
}

impl TrajectoryPlanner {
    fn new(flight_model: FlightModel) -> TrajectoryPlanner {
        TrajectoryPlanner {
            model: flight_model,
        }
    }

    fn plan_cruise(&mut self) {
        loop {
            let current_altitude = self.model.update_altitude();
            if current_altitude >= self.model.cruise_altitude {
                break;
            }
        }
    }
}

struct Simulation {
    model: FlightModel,
    planner: TrajectoryPlanner,
}

impl Simulation {
    fn new(flight_model: FlightModel) -> Simulation {
        Simulation {
            model: flight_model,
            planner: TrajectoryPlanner::new(flight_model),
        }
    }

    fn execute(&mut self) {
        self.planner.plan_cruise();
        loop {}
    }
}

fn main() {
    let initial_altitude = 1000;
    let rate_of_climb = 150;
    let cruise_altitude = 10000;
    let flight_model = FlightModel::new(initial_altitude, rate_of_climb, cruise_altitude);
    let mut simulation = Simulation::new(flight_model);
    simulation.execute();
}