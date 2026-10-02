struct FlightTrajectory {
    altitude: i32,
    max_altitude: i32,
    climb_rate: i32,
    descent_rate: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, max_altitude: i32, rate_of_climb: i32, rate_of_descent: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            max_altitude,
            climb_rate,
            descent_rate,
        }
    }

    fn update_altitude(&mut self, action: &str) {
        if action == "climb" {
            self.altitude += self.climb_rate;
            if self.altitude > self.max_altitude {
                self.altitude = self.max_altitude;
            }
        } else if action == "descend" {
            self.altitude -= self.descent_rate;
            if self.altitude < 0 {
                self.altitude = 0;
            }
        }
    }
}

struct CruiseAltitudePlanner {
    target: i32,
    tolerance: i32,
}

impl CruiseAltitudePlanner {
    fn new(target_altitude: i32, tolerance: i32) -> Self {
        CruiseAltitudePlanner {
            target: target_altitude,
            tolerance,
        }
    }

    fn is_within_tolerance(&self, current_altitude: i32) -> bool {
        (current_altitude - self.target).abs() <= self.tolerance
    }
}

struct FlightControlSystem {
    trajectory: FlightTrajectory,
    planner: CruiseAltitudePlanner,
}

impl FlightControlSystem {
    fn new(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> Self {
        FlightControlSystem { trajectory, planner }
    }

    fn control_loop(&mut self) {
        loop {
            if !self.planner.is_within_tolerance(self.trajectory.altitude) {
                if self.trajectory.altitude < self.planner.target {
                    self.trajectory.update_altitude("climb");
                } else {
                    self.trajectory.update_altitude("descend");
                }
            } else {
                self.trajectory.update_altitude("descend");
            }
        }
    }
}

fn main() {
    let initial_altitude = 1000;
    let max_altitude = 35000;
    let rate_of_climb = 1000;
    let rate_of_descent = 500;
    let target_altitude = 30000;
    let tolerance = 1000;
    let trajectory = FlightTrajectory::new(initial_altitude, max_altitude, rate_of_climb, rate_of_descent);
    let planner = CruiseAltitudePlanner::new(target_altitude, tolerance);
    let mut control_system = FlightControlSystem::new(trajectory, planner);
    control_system.control_loop();
}