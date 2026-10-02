struct FlightTrajectory {
    altitude: i32,
    target: i32,
    rate: i32,
}

impl FlightTrajectory {
    fn new(start_altitude: i32, target_altitude: i32, rate: i32) -> FlightTrajectory {
        FlightTrajectory {
            altitude: start_altitude,
            target: target_altitude,
            rate: rate,
        }
    }

    fn update_altitude(&mut self) -> i32 {
        if self.altitude < self.target {
            self.altitude += self.rate;
            if self.altitude > self.target {
                self.altitude = self.target;
            }
        }
        self.altitude
    }

    fn is_at_target(&self) -> bool {
        self.altitude == self.target
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
    steps: i32,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> CruiseAltitudePlanner {
        CruiseAltitudePlanner {
            trajectory: trajectory,
            steps: 0,
        }
    }

    fn plan(&mut self) {
        while !self.trajectory.is_at_target() {
            let current_altitude = self.trajectory.update_altitude();
            self.steps += 1;
            println!("Step {}: Altitude = {}", self.steps, current_altitude);
        }
    }
}

fn main() {
    let start = 1000;
    let target = 35000;
    let rate = 1500;
    let mut trajectory = FlightTrajectory::new(start, target, rate);
    let mut planner = CruiseAltitudePlanner::new(trajectory);
    planner.plan();
    println!("Reached target altitude in {} steps.", planner.steps);
}