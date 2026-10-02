struct FlightData {
    altitude: f64,
    velocity: f64,
    wind_speed: f64,
}

impl FlightData {
    fn new(altitude: f64, velocity: f64, wind_speed: f64) -> Self {
        FlightData {
            altitude,
            velocity,
            wind_speed,
        }
    }

    fn update_altitude(&mut self, adjustment: f64) {
        self.altitude += adjustment;
    }

    fn calculate_drag(&self) -> f64 {
        0.5 * self.velocity * self.wind_speed
    }
}

struct TrajectoryPlanner {
    flight_data: FlightData,
}

impl TrajectoryPlanner {
    fn new(flight_data: FlightData) -> Self {
        TrajectoryPlanner { flight_data }
    }

    fn optimize_altitude(&mut self, target_drag: f64) {
        let mut adjustment = 0.1;
        loop {
            let drag = self.flight_data.calculate_drag();
            if (drag - target_drag).abs() < 0.01 {
                break;
            }
            if drag > target_drag {
                adjustment = -adjustment;
            }
            self.flight_data.update_altitude(adjustment);
        }
    }

    fn plan_cruise(&mut self) {
        let target_drag = 150.0;
        self.optimize_altitude(target_drag);
    }
}

struct FlightControl {
    flight_data: FlightData,
    planner: TrajectoryPlanner,
}

impl FlightControl {
    fn new() -> Self {
        let flight_data = FlightData::new(30000.0, 800.0, 50.0);
        let planner = TrajectoryPlanner::new(flight_data);
        FlightControl { flight_data, planner }
    }

    fn execute_flight_plan(&mut self) {
        loop {
            self.planner.plan_cruise();
        }
    }
}

fn main() {
    let mut flight_control = FlightControl::new();
    flight_control.execute_flight_plan();
}