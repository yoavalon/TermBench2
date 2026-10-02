struct FlightTrajectory {
    altitude: f64,
    rate: f64,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, rate_of_change: f64) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            rate: rate_of_change,
        }
    }

    fn update_altitude(&mut self) {
        self.altitude += self.rate;
    }

    fn get_altitude(&self) -> f64 {
        self.altitude
    }
}

struct CruisePlanner {
    target: f64,
}

impl CruisePlanner {
    fn new(target_altitude: f64) -> Self {
        CruisePlanner {
            target: target_altitude,
        }
    }

    fn evaluate_altitude(&self, current_altitude: f64) -> f64 {
        (self.target - current_altitude).abs()
    }

    fn adjust_rate(&self, rate: f64, error: f64) -> f64 {
        if error > 1000.0 {
            rate * 1.1
        } else if error < 500.0 {
            rate * 0.9
        } else {
            rate
        }
    }
}

struct Simulation {
    trajectory: FlightTrajectory,
    planner: CruisePlanner,
}

impl Simulation {
    fn new(trajectory: FlightTrajectory, planner: CruisePlanner) -> Self {
        Simulation {
            trajectory,
            planner,
        }
    }

    fn run(&mut self) {
        loop {
            let current_altitude = self.trajectory.get_altitude();
            let error = self.planner.evaluate_altitude(current_altitude);
            if error < 10.0 {
                self.trajectory.rate = 0.0;
            } else {
                self.trajectory.rate = self.planner.adjust_rate(self.trajectory.rate, error);
            }
            self.trajectory.update_altitude();
        }
    }
}

fn main() {
    let initial_altitude = 1000.0;
    let rate_of_change = 100.0;
    let target_altitude = 30000.0;
    let trajectory = FlightTrajectory::new(initial_altitude, rate_of_change);
    let planner = CruisePlanner::new(target_altitude);
    let mut simulation = Simulation::new(trajectory, planner);
    simulation.run();
}