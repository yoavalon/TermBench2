extern crate ndarray;

struct FlightTrajectory {
    altitude: i32,
    target_altitude: i32,
    max_altitude: i32,
    rate_of_climb: i32,
    time: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, max_altitude: i32, rate_of_climb: i32) -> FlightTrajectory {
        FlightTrajectory {
            altitude: initial_altitude,
            target_altitude,
            max_altitude,
            rate_of_climb,
            time: 0,
        }
    }

    fn update_altitude(&mut self) {
        if self.altitude < self.target_altitude {
            self.altitude += self.rate_of_climb;
            if self.altitude > self.max_altitude {
                self.altitude = self.max_altitude;
            }
        }
        self.time += 1;
    }

    fn is_complete(&self) -> bool {
        self.altitude >= self.target_altitude
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> CruiseAltitudePlanner {
        CruiseAltitudePlanner { trajectory }
    }

    fn plan_cruise(&mut self) -> (i32, i32) {
        while !self.trajectory.is_complete() {
            self.trajectory.update_altitude();
        }
        (self.trajectory.altitude, self.trajectory.time)
    }
}

fn main() {
    let initial_altitude = 1000;
    let target_altitude = 35000;
    let max_altitude = 40000;
    let rate_of_climb = 1500;
    let mut trajectory = FlightTrajectory::new(initial_altitude, target_altitude, max_altitude, rate_of_climb);
    let mut planner = CruiseAltitudePlanner::new(trajectory);
    let (final_altitude, climb_time) = planner.plan_cruise();
    println!("Final Altitude: {}, Climb Time: {}", final_altitude, climb_time);
}