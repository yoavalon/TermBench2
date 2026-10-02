struct FlightTrajectory {
    speed: f64,
    altitude: f64,
    distance: f64,
}

impl FlightTrajectory {
    fn new(speed: f64, altitude: f64, distance: f64) -> Self {
        FlightTrajectory { speed, altitude, distance }
    }

    fn calculate_time(&self) -> f64 {
        self.distance / self.speed
    }

    fn adjust_altitude(&mut self, new_altitude: f64) {
        self.altitude = new_altitude;
    }
}

struct CruiseAltitudePlanner {
    max_altitude: f64,
    min_altitude: f64,
    step: f64,
}

impl CruiseAltitudePlanner {
    fn new(max_altitude: f64, min_altitude: f64, step: f64) -> Self {
        CruiseAltitudePlanner { max_altitude, min_altitude, step }
    }

    fn suggest_altitudes(&self) -> Vec<f64> {
        let mut altitudes = Vec::new();
        let mut current = self.min_altitude;
        while current <= self.max_altitude {
            altitudes.push(current);
            current += self.step;
        }
        altitudes
    }
}

fn optimize_flight_plan(trajectory: &mut FlightTrajectory, planner: &CruiseAltitudePlanner) -> (f64, f64) {
    let altitudes = planner.suggest_altitudes();
    let mut best_time = f64::INFINITY;
    let mut best_altitude = 0.0;
    for altitude in altitudes {
        trajectory.adjust_altitude(altitude);
        let time = trajectory.calculate_time();
        if time < best_time {
            best_time = time;
            best_altitude = altitude;
        }
    }
    trajectory.adjust_altitude(best_altitude);
    (trajectory.altitude, trajectory.calculate_time())
}

fn main() {
    let mut trajectory = FlightTrajectory::new(800.0, 30000.0, 1000.0);
    let planner = CruiseAltitudePlanner::new(40000.0, 20000.0, 5000.0);
    let (best_altitude, best_time) = optimize_flight_plan(&mut trajectory, &planner);
    println!("Best Altitude: {} meters", best_altitude);
    println!("Time to Destination: {} hours", best_time);
}