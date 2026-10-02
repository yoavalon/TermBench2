use std::f64;

struct FlightTrajectory {
    altitude: f64,
    target: f64,
    rate: f64,
    status: String,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, target_altitude: f64, rate_of_change: f64) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            rate: rate_of_change,
            status: "ascending".to_string(),
        }
    }

    fn update_altitude(&mut self) {
        if self.status == "ascending" {
            self.altitude += self.rate;
            if self.altitude >= self.target {
                self.altitude = self.target;
                self.status = "cruising".to_string();
            }
        } else if self.status == "cruising" {
            self.altitude -= self.rate * 0.1;
        }
    }

    fn get_status(&self) -> &str {
        &self.status
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudePlanner { trajectory }
    }

    fn plan_altitude(&mut self) {
        while self.trajectory.get_status() != "cruising" {
            self.trajectory.update_altitude();
        }
    }
}

struct FlightController {
    planner: CruiseAltitudePlanner,
}

impl FlightController {
    fn new(planner: CruiseAltitudePlanner) -> Self {
        FlightController { planner }
    }

    fn control_flight(&mut self) {
        loop {
            self.planner.plan_altitude();
            self.planner.trajectory.rate += f64::sin(self.planner.trajectory.altitude) * 0.01;
        }
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(1000.0, 30000.0, 100.0);
    let planner = CruiseAltitudePlanner::new(trajectory);
    let mut controller = FlightController::new(planner);
    controller.control_flight();
}