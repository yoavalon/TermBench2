struct FlightTrajectory {
    current_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
    rate_of_descent: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32, rate_of_descent: i32) -> Self {
        FlightTrajectory {
            current_altitude: initial_altitude,
            target_altitude: target_altitude,
            rate_of_climb: rate_of_climb,
            rate_of_descent: rate_of_descent,
        }
    }

    fn climb(&mut self) {
        if self.current_altitude < self.target_altitude {
            self.current_altitude += self.rate_of_climb;
            if self.current_altitude > self.target_altitude {
                self.current_altitude = self.target_altitude;
            }
        }
    }

    fn descend(&mut self) {
        if self.current_altitude > self.target_altitude {
            self.current_altitude -= self.rate_of_descent;
            if self.current_altitude < self.target_altitude {
                self.current_altitude = self.target_altitude;
            }
        }
    }

    fn adjust_altitude(&mut self) {
        if self.current_altitude < self.target_altitude {
            self.climb();
        } else if self.current_altitude > self.target_altitude {
            self.descend();
        }
    }
}

struct CruiseAltitudeManager {
    trajectory: FlightTrajectory,
    cruise_altitude: i32,
    altitude_changes: Vec<i32>,
}

impl CruiseAltitudeManager {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudeManager {
            trajectory: trajectory,
            cruise_altitude: trajectory.target_altitude,
            altitude_changes: Vec::new(),
        }
    }

    fn update_cruise_altitude(&mut self, new_altitude: i32) {
        self.cruise_altitude = new_altitude;
        self.trajectory.target_altitude = new_altitude;
    }

    fn log_altitude_change(&mut self) {
        self.altitude_changes.push(self.trajectory.current_altitude);
    }

    fn manage_cruise(&mut self) {
        self.trajectory.adjust_altitude();
        self.log_altitude_change();
    }
}

struct FlightSimulation {
    trajectory: FlightTrajectory,
    cruise_manager: CruiseAltitudeManager,
}

impl FlightSimulation {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32, rate_of_descent: i32) -> Self {
        let trajectory = FlightTrajectory::new(initial_altitude, target_altitude, rate_of_climb, rate_of_descent);
        let cruise_manager = CruiseAltitudeManager::new(trajectory);
        FlightSimulation {
            trajectory: cruise_manager.trajectory,
            cruise_manager: cruise_manager,
        }
    }

    fn simulate_flight(&mut self) {
        loop {
            self.cruise_manager.manage_cruise();
        }
    }
}

fn main() {
    let mut flight_sim = FlightSimulation::new(5000, 35000, 500, 300);
    flight_sim.simulate_flight();
}