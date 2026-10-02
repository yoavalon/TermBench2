extern crate rand;

struct FlightModel {
    altitude: f64,
    rate_of_climb: f64,
    max_altitude: f64,
}

impl FlightModel {
    fn new(initial_altitude: f64, rate_of_climb: f64, max_altitude: f64) -> Self {
        FlightModel {
            altitude: initial_altitude,
            rate_of_climb: rate_of_climb,
            max_altitude: max_altitude,
        }
    }

    fn update_altitude(&mut self) {
        self.altitude += self.rate_of_climb;
        if self.altitude > self.max_altitude {
            self.altitude = self.max_altitude;
        }
    }
}

struct TrajectoryPlanner {
    model: FlightModel,
    cruise_altitude: f64,
    target_distance: f64,
    speed: f64,
}

impl TrajectoryPlanner {
    fn new(model: FlightModel, cruise_altitude: f64, target_distance: f64, speed: f64) -> Self {
        TrajectoryPlanner {
            model: model,
            cruise_altitude: cruise_altitude,
            target_distance: target_distance,
            speed: speed,
        }
    }

    fn calculate_time_to_cruise(&self) -> f64 {
        (self.cruise_altitude - self.model.altitude) / self.model.rate_of_climb
    }

    fn calculate_time_to_target(&self) -> f64 {
        let time_to_cruise = self.calculate_time_to_cruise();
        let time_in_cruise = self.target_distance / self.speed;
        time_to_cruise + time_in_cruise
    }
}

struct Simulation {
    model: FlightModel,
    planner: TrajectoryPlanner,
}

impl Simulation {
    fn new(model: FlightModel, planner: TrajectoryPlanner) -> Self {
        Simulation {
            model: model,
            planner: planner,
        }
    }

    fn run(&mut self) {
        loop {
            self.model.update_altitude();
            if self.model.altitude >= self.planner.cruise_altitude {
                self.planner.cruise_altitude = f64::INFINITY;
            }
            println!("Current Altitude: {}, Time to Target: {}", self.model.altitude, self.planner.calculate_time_to_target());
        }
    }
}

fn main() {
    let flight_model = FlightModel::new(1000.0, 500.0, 30000.0);
    let trajectory_planner = TrajectoryPlanner::new(flight_model, 20000.0, 1000.0, 500.0);
    let mut simulation = Simulation::new(flight_model, trajectory_planner);
    simulation.run();
}