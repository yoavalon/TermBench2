struct FlightTrajectory {
    altitude: f64,
    speed: f64,
    time: f64,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, cruise_speed: f64) -> FlightTrajectory {
        FlightTrajectory {
            altitude: initial_altitude,
            speed: cruise_speed,
            time: 0.0,
        }
    }

    fn update_altitude(&mut self, rate_of_change: f64) {
        self.altitude += rate_of_change;
        self.time += 1.0;
    }

    fn get_altitude(&self) -> f64 {
        self.altitude
    }
}

struct CruiseAltitudePlanner {
    target: f64,
    max_change: f64,
}

impl CruiseAltitudePlanner {
    fn new(target_altitude: f64, max_rate_of_change: f64) -> CruiseAltitudePlanner {
        CruiseAltitudePlanner {
            target: target_altitude,
            max_change: max_rate_of_change,
        }
    }

    fn calculate_adjustment(&self, current_altitude: f64) -> f64 {
        let difference = self.target - current_altitude;
        let adjustment = difference.abs().min(self.max_change);
        if difference > 0.0 {
            adjustment
        } else {
            -adjustment
        }
    }
}

struct FlightController {
    trajectory: FlightTrajectory,
    planner: CruiseAltitudePlanner,
}

impl FlightController {
    fn new(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> FlightController {
        FlightController {
            trajectory,
            planner,
        }
    }

    fn execute(&mut self) {
        loop {
            let current_altitude = self.trajectory.get_altitude();
            let adjustment = self.planner.calculate_adjustment(current_altitude);
            self.trajectory.update_altitude(adjustment);
        }
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(5000.0, 900.0);
    let planner = CruiseAltitudePlanner::new(35000.0, 1000.0);
    let mut controller = FlightController::new(trajectory, planner);
    controller.execute();
}