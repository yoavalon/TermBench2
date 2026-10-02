struct FlightTrajectory {
    altitude: i32,
    max_altitude: i32,
    speed: i32,
    climbing: bool,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, max_altitude: i32, speed: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            max_altitude,
            speed,
            climbing: true,
        }
    }

    fn adjust_altitude(&mut self) {
        if self.climbing {
            self.altitude += self.speed;
            if self.altitude >= self.max_altitude {
                self.climbing = false;
            }
        } else {
            self.altitude -= self.speed;
            if self.altitude <= 0 {
                self.climbing = true;
            }
        }
    }

    fn simulate_flight(&mut self) {
        loop {
            self.adjust_altitude();
        }
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
            if self.trajectory.climbing {
                println!("Climbing to {} meters", self.trajectory.altitude);
            } else {
                println!("Descending to {} meters", self.trajectory.altitude);
            }
        }
    }
}

fn main() {
    let mut trajectory = FlightTrajectory::new(1000, 10000, 100);
    let mut planner = CruiseAltitudePlanner::new(trajectory);
    planner.plan_cruise();
}