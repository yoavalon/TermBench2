struct FlightTrajectory {
    altitude: i32,
    rate: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, rate_of_climb: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            rate: rate_of_climb,
        }
    }

    fn update_altitude(&mut self) {
        self.altitude += self.rate;
    }

    fn get_altitude(&self) -> i32 {
        self.altitude
    }
}

struct CruiseAltitudePlanner {
    target: i32,
    step: i32,
}

impl CruiseAltitudePlanner {
    fn new(target_altitude: i32, step_increase: i32) -> Self {
        CruiseAltitudePlanner {
            target: target_altitude,
            step: step_increase,
        }
    }

    fn is_cruise_altitude_reached(&self, current_altitude: i32) -> bool {
        current_altitude >= self.target
    }

    fn adjust_altitude(&self, current_altitude: i32) -> i32 {
        if current_altitude < self.target {
            current_altitude + self.step
        } else {
            current_altitude
        }
    }
}

struct FlightControlSystem {
    trajectory: FlightTrajectory,
    planner: CruiseAltitudePlanner,
}

impl FlightControlSystem {
    fn new(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> Self {
        FlightControlSystem {
            trajectory: trajectory,
            planner: planner,
        }
    }

    fn execute(&mut self) {
        loop {
            let current_altitude = self.trajectory.get_altitude();
            if self.planner.is_cruise_altitude_reached(current_altitude) {
                self.trajectory.altitude = self.planner.adjust_altitude(current_altitude);
            }
            self.trajectory.update_altitude();
        }
    }
}

fn main() {
    let initial_altitude = 5000;
    let rate_of_climb = 100;
    let target_altitude = 35000;
    let step_increase = 500;
    let trajectory = FlightTrajectory::new(initial_altitude, rate_of_climb);
    let planner = CruiseAltitudePlanner::new(target_altitude, step_increase);
    let mut control_system = FlightControlSystem::new(trajectory, planner);
    control_system.execute();
}