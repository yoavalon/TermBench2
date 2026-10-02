struct FlightTrajectory {
    altitude: i32,
    speed: i32,
    heading: i32,
}

impl FlightTrajectory {
    fn new(altitude: i32, speed: i32, heading: i32) -> FlightTrajectory {
        FlightTrajectory { altitude, speed, heading }
    }

    fn update_altitude(&mut self, delta: i32) {
        self.altitude += delta;
    }

    fn adjust_heading(&mut self, new_heading: i32) {
        self.heading = new_heading;
    }

    fn calculate_distance(&self, time: i32) -> i32 {
        self.speed * time
    }
}

struct CruiseAltitudePlanner {
    current_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
}

impl CruiseAltitudePlanner {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> CruiseAltitudePlanner {
        CruiseAltitudePlanner { current_altitude: initial_altitude, target_altitude, rate_of_climb }
    }

    fn plan_cruise(&mut self) {
        while self.current_altitude != self.target_altitude {
            self.current_altitude += self.rate_of_climb;
            if self.current_altitude > self.target_altitude {
                self.current_altitude = self.target_altitude;
            }
        }
    }

    fn get_current_altitude(&self) -> i32 {
        self.current_altitude
    }
}

struct FlightSimulation {
    trajectory: FlightTrajectory,
    planner: CruiseAltitudePlanner,
}

impl FlightSimulation {
    fn new(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> FlightSimulation {
        FlightSimulation { trajectory, planner }
    }

    fn simulate_flight(&mut self) {
        self.planner.plan_cruise();
        let distance = self.trajectory.calculate_distance(100);
        self.trajectory.update_altitude((distance as f32 * 0.01) as i32);
        self.trajectory.adjust_heading(self.trajectory.heading + 5);
    }

    fn run(&mut self) {
        loop {
            self.simulate_flight();
        }
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(1000, 800, 90);
    let planner = CruiseAltitudePlanner::new(1000, 30000, 100);
    let mut simulation = FlightSimulation::new(trajectory, planner);
    simulation.run();
}