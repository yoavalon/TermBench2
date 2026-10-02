struct FlightTrajectory {
    current_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
    cruise_altitude: Option<i32>,
}

impl FlightTrajectory {
    fn new(start_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightTrajectory {
            current_altitude: start_altitude,
            target_altitude,
            rate_of_climb,
            cruise_altitude: None,
        }
    }

    fn update_altitude(&mut self) {
        if self.current_altitude < self.target_altitude {
            self.current_altitude += self.rate_of_climb;
            if self.current_altitude >= self.target_altitude {
                self.current_altitude = self.target_altitude;
                self.set_cruise_altitude();
            }
        }
    }

    fn set_cruise_altitude(&mut self) {
        self.cruise_altitude = Some(self.current_altitude);
    }

    fn get_current_altitude(&self) -> i32 {
        self.current_altitude
    }

    fn is_at_target(&self) -> bool {
        self.current_altitude == self.target_altitude
    }
}

struct AltitudePlanner {
    trajectory: FlightTrajectory,
    target_altitude: i32,
}

impl AltitudePlanner {
    fn new(trajectory: FlightTrajectory, target_altitude: i32) -> Self {
        AltitudePlanner {
            trajectory,
            target_altitude,
        }
    }

    fn plan_cruise_altitude(&mut self) -> i32 {
        while !self.trajectory.is_at_target() {
            self.trajectory.update_altitude();
        }
        self.trajectory.get_current_altitude()
    }
}

fn main() {
    let start_altitude = 1000;
    let target_altitude = 35000;
    let rate_of_climb = 500;
    let mut trajectory = FlightTrajectory::new(start_altitude, target_altitude, rate_of_climb);
    let mut planner = AltitudePlanner::new(trajectory, target_altitude);
    let cruise_altitude = planner.plan_cruise_altitude();
    println!("Cruise Altitude Set: {} feet", cruise_altitude);
}