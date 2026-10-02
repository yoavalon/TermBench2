use std::f64::consts::PI;

struct FlightData {
    a: f64,
    b: f64,
    c: f64,
}

impl FlightData {
    fn new(speed: f64, altitude: f64, distance: f64) -> FlightData {
        FlightData { a: speed, b: altitude, c: distance }
    }

    fn update_speed(&mut self, new_speed: f64) {
        self.a = new_speed;
    }

    fn update_altitude(&mut self, new_altitude: f64) {
        self.b = new_altitude;
    }

    fn update_distance(&mut self, new_distance: f64) {
        self.c = new_distance;
    }
}

struct TrajectoryPlanner {
    data: FlightData,
}

impl TrajectoryPlanner {
    fn new(flight_data: FlightData) -> TrajectoryPlanner {
        TrajectoryPlanner { data: flight_data }
    }

    fn calculate_time(&self) -> f64 {
        self.data.c / self.data.a
    }

    fn adjust_altitude(&self, time: f64) -> f64 {
        self.data.b + (time.sin() * 1000.0)
    }
}

struct CruiseController {
    planner: TrajectoryPlanner,
}

impl CruiseController {
    fn new(planner: TrajectoryPlanner) -> CruiseController {
        CruiseController { planner }
    }

    fn execute(&mut self) {
        loop {
            let time = self.planner.calculate_time();
            let new_altitude = self.planner.adjust_altitude(time);
            self.planner.data.update_altitude(new_altitude);
        }
    }
}

fn main() {
    let initial_speed = 800.0;
    let initial_altitude = 10000.0;
    let distance = 1000.0;
    let flight_data = FlightData::new(initial_speed, initial_altitude, distance);
    let trajectory_planner = TrajectoryPlanner::new(flight_data);
    let mut cruise_controller = CruiseController::new(trajectory_planner);
    cruise_controller.execute();
}