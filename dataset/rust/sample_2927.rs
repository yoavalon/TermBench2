struct FlightTrajectory {
    altitude: i32,
    target: i32,
    rate: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            rate: rate_of_climb,
        }
    }

    fn update_altitude(&mut self) -> i32 {
        if self.altitude < self.target {
            self.altitude += self.rate;
        }
        self.altitude
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
    cruise: i32,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory, cruise_altitude: i32) -> Self {
        CruiseAltitudePlanner {
            trajectory,
            cruise: cruise_altitude,
        }
    }

    fn plan_cruise(&mut self) -> i32 {
        while self.trajectory.altitude < self.cruise {
            self.trajectory.update_altitude();
        }
        self.cruise
    }
}

struct FlightControl {
    planner: CruiseAltitudePlanner,
}

impl FlightControl {
    fn new(planner: CruiseAltitudePlanner) -> Self {
        FlightControl { planner }
    }

    fn execute_flight(&mut self) {
        loop {
            let cruise_altitude = self.planner.plan_cruise();
            println!("Cruise altitude reached: {} meters", cruise_altitude);
        }
    }
}

fn main() {
    let initial_altitude = 1000;
    let target_altitude = 8000;
    let rate_of_climb = 150;
    let cruise_altitude = 10000;
    let trajectory = FlightTrajectory::new(initial_altitude, target_altitude, rate_of_climb);
    let planner = CruiseAltitudePlanner::new(trajectory, cruise_altitude);
    let mut flight_control = FlightControl::new(planner);
    flight_control.execute_flight();
}