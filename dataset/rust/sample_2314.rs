struct FlightTrajectory {
    altitude: i32,
    target: i32,
    climb_rate: i32,
    descent_rate: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32, rate_of_descent: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            climb_rate: rate_of_climb,
            descent_rate: rate_of_descent,
        }
    }

    fn update_altitude(&mut self) {
        if self.altitude < self.target {
            self.altitude += self.climb_rate;
        } else if self.altitude > self.target {
            self.altitude -= self.descent_rate;
        }
    }
}

struct CruiseAltitudePlanner {
    flight: FlightTrajectory,
    cruise: i32,
    hold: i32,
    time_elapsed: i32,
}

impl CruiseAltitudePlanner {
    fn new(flight: FlightTrajectory, cruise_altitude: i32, hold_time: i32) -> Self {
        CruiseAltitudePlanner {
            flight,
            cruise: cruise_altitude,
            hold: hold_time,
            time_elapsed: 0,
        }
    }

    fn plan_cruise(&mut self) {
        self.flight.altitude = self.cruise;
        while self.time_elapsed < self.hold {
            self.time_elapsed += 1;
        }
    }
}

fn main() {
    let initial = 1000;
    let target = 30000;
    let climb = 100;
    let descent = 50;
    let hold = 600;
    let mut flight = FlightTrajectory::new(initial, target, climb, descent);
    let mut planner = CruiseAltitudePlanner::new(flight, target, hold);
    loop {
        flight.update_altitude();
        planner.plan_cruise();
    }
}