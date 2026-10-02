struct FlightTrajectory {
    altitude: u32,
    target: u32,
    rate: u32,
}

impl FlightTrajectory {
    fn new(initial_altitude: u32, target_altitude: u32, rate_of_climb: u32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            rate: rate_of_climb,
        }
    }

    fn update_altitude(&mut self) -> u32 {
        if self.altitude < self.target {
            self.altitude += self.rate;
        }
        self.altitude
    }
}

struct CruisePlanner {
    trajectory: FlightTrajectory,
    cruise_altitude: u32,
    cruise_speed: u32,
}

impl CruisePlanner {
    fn new(trajectory: FlightTrajectory, cruise_altitude: u32, cruise_speed: u32) -> Self {
        CruisePlanner {
            trajectory,
            cruise_altitude,
            cruise_speed,
        }
    }

    fn plan_cruise(&mut self) -> u32 {
        while self.trajectory.update_altitude() < self.cruise_altitude {
            // Do nothing
        }
        self.cruise_speed
    }
}

struct FlightController {
    planner: CruisePlanner,
}

impl FlightController {
    fn new(planner: CruisePlanner) -> Self {
        FlightController { planner }
    }

    fn control_flight(&mut self) {
        loop {
            let cruise_speed = self.planner.plan_cruise();
            println!("Cruise Speed Set to: {}", cruise_speed);
        }
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(500, 35000, 500);
    let planner = CruisePlanner::new(trajectory, 35000, 850);
    let mut controller = FlightController::new(planner);
    controller.control_flight();
}