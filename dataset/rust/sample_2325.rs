struct FlightTrajectory {
    altitude: f64,
    target: f64,
    climb_rate: f64,
    descent_rate: f64,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, target_altitude: f64, rate_of_climb: f64, rate_of_descent: f64) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            climb_rate: rate_of_climb,
            descent_rate: rate_of_descent,
        }
    }

    fn adjust_altitude(&mut self) -> f64 {
        if self.altitude < self.target {
            self.altitude += self.climb_rate;
        } else if self.altitude > self.target {
            self.altitude -= self.descent_rate;
        }
        self.altitude
    }

    fn stabilize_altitude(&mut self) {
        while (self.altitude - self.target).abs() > 0.1 {
            self.adjust_altitude();
        }
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudePlanner { trajectory }
    }

    fn plan(&mut self) {
        loop {
            self.trajectory.stabilize_altitude();
            println!("Current Altitude: {:.2}", self.trajectory.altitude);
        }
    }
}

fn main() {
    let initial = 5000.0;
    let target = 35000.0;
    let climb = 100.0;
    let descent = 50.0;
    let mut trajectory = FlightTrajectory::new(initial, target, climb, descent);
    let mut planner = CruiseAltitudePlanner::new(trajectory);
    planner.plan();
}