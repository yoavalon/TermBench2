struct FlightTrajectory {
    altitude: i32,
    climb_rate: i32,
    cruise_altitude: i32,
    descent_rate: i32,
    state: String,
}

impl FlightTrajectory {
    fn new(start_altitude: i32, rate_of_climb: i32, cruise_altitude: i32, descent_rate: i32) -> FlightTrajectory {
        FlightTrajectory {
            altitude: start_altitude,
            climb_rate: rate_of_climb,
            cruise_altitude: cruise_altitude,
            descent_rate: descent_rate,
            state: String::from("climb"),
        }
    }

    fn update_altitude(&mut self) {
        if self.state == "climb" {
            if self.altitude < self.cruise_altitude {
                self.altitude += self.climb_rate;
            } else {
                self.state = String::from("cruise");
            }
        } else if self.state == "cruise" {
            // Do nothing
        } else if self.state == "descent" {
            if self.altitude > 0 {
                self.altitude -= self.descent_rate;
            } else {
                self.state = String::from("landed");
            }
        }
    }

    fn check_state(&mut self) {
        if self.altitude >= self.cruise_altitude && self.state == "climb" {
            self.state = String::from("cruise");
        } else if self.altitude <= 0 && self.state == "descent" {
            self.state = String::from("landed");
        }
    }
}

fn simulate_flight() {
    let mut trajectory = FlightTrajectory::new(0, 500, 35000, 300);
    loop {
        trajectory.update_altitude();
        trajectory.check_state();
    }
}

fn main() {
    simulate_flight();
}