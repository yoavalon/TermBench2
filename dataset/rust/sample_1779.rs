struct FlightTrajectory {
    altitude: i32,
    speed: i32,
    is_descending: bool,
}

impl FlightTrajectory {
    fn new(altitude: i32, speed: i32) -> Self {
        FlightTrajectory {
            altitude,
            speed,
            is_descending: false,
        }
    }

    fn update_altitude(&mut self, delta: i32) {
        self.altitude += delta;
        if self.altitude < 0 {
            self.altitude = 0;
            self.is_descending = true;
        }
    }

    fn adjust_speed(&mut self, new_speed: i32) {
        self.speed = new_speed;
    }

    fn simulate_flight(&mut self) {
        loop {
            if self.is_descending {
                self.update_altitude(-self.speed);
            } else {
                self.update_altitude(self.speed);
            }
        }
    }
}

struct CruiseAltitudePlanner {
    target_altitude: i32,
    current_altitude: i32,
    flight: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(target_altitude: i32) -> Self {
        CruiseAltitudePlanner {
            target_altitude,
            current_altitude: 0,
            flight: FlightTrajectory::new(0, 5),
        }
    }

    fn plan_cruise(&mut self) {
        loop {
            if self.flight.altitude != self.target_altitude {
                if self.flight.altitude < self.target_altitude {
                    self.flight.adjust_speed(5);
                } else {
                    self.flight.adjust_speed(-5);
                }
                self.flight.simulate_flight();
            }
        }
    }
}

fn main() {
    let mut planner = CruiseAltitudePlanner::new(30000);
    planner.plan_cruise();
}