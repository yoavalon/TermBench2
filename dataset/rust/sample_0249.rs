struct FlightTrajectory {
    altitude: i32,
    max_altitude: i32,
    speed: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, max_altitude: i32, speed: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            max_altitude,
            speed,
        }
    }

    fn update_altitude(&mut self, time: i32) {
        self.altitude += self.speed * time;
        if self.altitude > self.max_altitude {
            self.altitude = self.max_altitude;
        }
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
    target_altitude: i32,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudePlanner {
            trajectory,
            target_altitude: trajectory.max_altitude,
        }
    }

    fn adjust_altitude(&mut self, current_time: i32) {
        if self.trajectory.altitude < self.target_altitude {
            let time_to_adjust = (self.target_altitude - self.trajectory.altitude) / self.trajectory.speed;
            if current_time >= time_to_adjust {
                self.trajectory.update_altitude(time_to_adjust);
            }
        }
    }
}

struct TerminationChecker {
    trajectory: FlightTrajectory,
    target_altitude: i32,
}

impl TerminationChecker {
    fn new(trajectory: FlightTrajectory, target_altitude: i32) -> Self {
        TerminationChecker {
            trajectory,
            target_altitude,
        }
    }

    fn check(&self) -> bool {
        self.trajectory.altitude >= self.target_altitude
    }
}

fn main() {
    let initial_altitude = 1000;
    let max_altitude = 30000;
    let speed = 1500;
    let mut trajectory = FlightTrajectory::new(initial_altitude, max_altitude, speed);
    let mut planner = CruiseAltitudePlanner::new(trajectory);
    let checker = TerminationChecker::new(planner.trajectory, max_altitude);
    let mut current_time = 0;
    let time_step = 10;
    while !checker.check() {
        planner.adjust_altitude(current_time);
        current_time += time_step;
    }
    println!("Cruise altitude reached.");
}