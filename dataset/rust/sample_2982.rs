use std::fmt;

struct FlightTrajectory {
    altitude: i32,
    rate_of_climb: i32,
    cruise_altitude: i32,
    descent_rate: i32,
    status: String,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, rate_of_climb: i32, cruise_altitude: i32, descent_rate: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            rate_of_climb,
            cruise_altitude,
            descent_rate,
            status: String::from("climbing"),
        }
    }

    fn update_altitude(&mut self) {
        if self.status == "climbing" {
            if self.altitude + self.rate_of_climb < self.cruise_altitude {
                self.altitude += self.rate_of_climb;
            } else {
                self.altitude = self.cruise_altitude;
                self.status = String::from("cruising");
            }
        } else if self.status == "cruising" {
        } else if self.status == "descending" {
            if self.altitude - self.descent_rate > 0 {
                self.altitude -= self.descent_rate;
            } else {
                self.altitude = 0;
                self.status = String::from("landed");
            }
        }
    }

    fn is_landed(&self) -> bool {
        self.status == "landed"
    }
}

struct FlightPlanner {
    trajectory: FlightTrajectory,
}

impl FlightPlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        FlightPlanner { trajectory }
    }

    fn plan_flight(&mut self) {
        while !self.trajectory.is_landed() {
            self.trajectory.update_altitude();
            self.log_status();
        }
    }

    fn log_status(&self) {
        println!("Altitude: {}, Status: {}", self.trajectory.altitude, self.trajectory.status);
    }
}

fn main() {
    let initial_altitude = 0;
    let rate_of_climb = 1000;
    let cruise_altitude = 30000;
    let descent_rate = 500;
    let mut trajectory = FlightTrajectory::new(initial_altitude, rate_of_climb, cruise_altitude, descent_rate);
    let mut planner = FlightPlanner::new(trajectory);
    planner.plan_flight();
}