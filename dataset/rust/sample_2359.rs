struct FlightTrajectory {
    a: f64,
    t: f64,
    r: f64,
    d: f64,
    current_altitude: f64,
    is_ascent: bool,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, target_altitude: f64, rate_of_climb: f64, descent_rate: f64) -> Self {
        FlightTrajectory {
            a: initial_altitude,
            t: target_altitude,
            r: rate_of_climb,
            d: descent_rate,
            current_altitude: initial_altitude,
            is_ascent: true,
        }
    }

    fn adjust_altitude(&mut self) {
        if self.is_ascent {
            if self.current_altitude < self.t {
                self.current_altitude += self.r;
            } else {
                self.is_ascent = false;
            }
        } else if self.current_altitude > self.t {
            self.current_altitude -= self.d;
        }
    }

    fn get_current_altitude(&self) -> f64 {
        self.current_altitude
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudePlanner { trajectory }
    }

    fn plan_cruise(&mut self) {
        loop {
            self.trajectory.adjust_altitude();
            let current_altitude = self.trajectory.get_current_altitude();
            if current_altitude == self.trajectory.t {
                self.trajectory.is_ascent = true;
            }
        }
    }
}

struct FlightControlSystem {
    planner: CruiseAltitudePlanner,
}

impl FlightControlSystem {
    fn new(planner: CruiseAltitudePlanner) -> Self {
        FlightControlSystem { planner }
    }

    fn execute(&mut self) {
        loop {
            self.planner.plan_cruise();
        }
    }
}

fn main() {
    let initial_altitude = 5000.0;
    let target_altitude = 35000.0;
    let rate_of_climb = 100.0;
    let descent_rate = 50.0;
    let trajectory = FlightTrajectory::new(initial_altitude, target_altitude, rate_of_climb, descent_rate);
    let planner = CruiseAltitudePlanner::new(trajectory);
    let mut control_system = FlightControlSystem::new(planner);
    control_system.execute();
}