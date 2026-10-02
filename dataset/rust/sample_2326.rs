struct FlightParameters {
    speed: f64,
    altitude: f64,
    heading: f64,
    wind_speed: f64,
    wind_heading: f64,
}

impl FlightParameters {
    fn new(speed: f64, altitude: f64, heading: f64, wind_speed: f64, wind_heading: f64) -> Self {
        FlightParameters {
            speed,
            altitude,
            heading,
            wind_speed,
            wind_heading,
        }
    }

    fn calculate_drift(&self) -> (f64, f64) {
        let angle_diff = self.wind_heading - self.heading;
        let drift_x = self.wind_speed * angle_diff.abs() / 360.0;
        let drift_y = self.wind_speed * (90.0 - angle_diff.abs()) / 360.0;
        (drift_x, drift_y)
    }
}

struct TrajectoryPlanner {
    parameters: FlightParameters,
}

impl TrajectoryPlanner {
    fn new(parameters: FlightParameters) -> Self {
        TrajectoryPlanner { parameters }
    }

    fn adjust_altitude(&self, target_altitude: f64) -> f64 {
        let current_alt = self.parameters.altitude;
        if current_alt < target_altitude {
            current_alt + 100.0
        } else if current_alt > target_altitude {
            current_alt - 50.0
        } else {
            current_alt
        }
    }

    fn plan_trajectory(&self, target_x: f64, target_y: f64) -> (f64, f64) {
        let (drift_x, drift_y) = self.parameters.calculate_drift();
        let adjusted_x = target_x - drift_x;
        let adjusted_y = target_y - drift_y;
        (adjusted_x, adjusted_y)
    }
}

struct CruiseControl {
    planner: TrajectoryPlanner,
}

impl CruiseControl {
    fn new(planner: TrajectoryPlanner) -> Self {
        CruiseControl { planner }
    }

    fn execute(&mut self) {
        let target_x = 1000.0;
        let target_y = 2000.0;
        let target_altitude = 30000.0;
        loop {
            self.planner.parameters.altitude = self.planner.adjust_altitude(target_altitude);
            let (x, y) = self.planner.plan_trajectory(target_x, target_y);
            println!("Current Coordinates: ({}, {}), Altitude: {}", x, y, self.planner.parameters.altitude);
        }
    }
}

fn main() {
    let params = FlightParameters::new(500.0, 25000.0, 45.0, 20.0, 90.0);
    let planner = TrajectoryPlanner::new(params);
    let mut cruise_control = CruiseControl::new(planner);
    cruise_control.execute();
}