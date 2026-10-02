struct FlightTrajectory {
    altitude: i32,
    target: i32,
    rate: i32,
    status: String,
}

impl FlightTrajectory {
    fn new(start_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> FlightTrajectory {
        FlightTrajectory {
            altitude: start_altitude,
            target: target_altitude,
            rate: rate_of_climb,
            status: String::from("ascending"),
        }
    }

    fn update_altitude(&mut self) -> i32 {
        if self.status == "ascending" {
            self.altitude += self.rate;
            if self.altitude >= self.target {
                self.status = String::from("cruising");
                self.altitude = self.target;
            }
        }
        self.altitude
    }

    fn is_cruising(&self) -> bool {
        self.status == "cruising"
    }
}

fn plan_cruise_altitude(trajectory: &mut FlightTrajectory, max_iterations: i32) -> i32 {
    let mut iteration = 0;
    while iteration < max_iterations && !trajectory.is_cruising() {
        trajectory.update_altitude();
        iteration += 1;
    }
    trajectory.altitude
}

fn main() {
    let start = 1000;
    let target = 35000;
    let rate = 500;
    let max_iter = 1000;
    let mut trajectory = FlightTrajectory::new(start, target, rate);
    let final_altitude = plan_cruise_altitude(&mut trajectory, max_iter);
    println!("Final Cruise Altitude: {}", final_altitude);
}