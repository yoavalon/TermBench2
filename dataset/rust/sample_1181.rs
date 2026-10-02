struct FlightPlanner {
    altitude: i32,
    speed: i32,
    target_altitude: i32,
}

impl FlightPlanner {
    fn new(altitude: i32, speed: i32, target_altitude: i32) -> Self {
        FlightPlanner {
            altitude,
            speed,
            target_altitude,
        }
    }

    fn adjust_altitude(&mut self) {
        if self.altitude < self.target_altitude {
            self.altitude += self.speed;
            self.adjust_altitude();
        } else if self.altitude > self.target_altitude {
            self.altitude -= self.speed;
            self.adjust_altitude();
        }
    }
}

struct TrajectorySimulator {
    altitude: i32,
    speed: i32,
}

impl TrajectorySimulator {
    fn new(altitude: i32, speed: i32) -> Self {
        TrajectorySimulator { altitude, speed }
    }

    fn simulate(&mut self) {
        self.altitude += self.speed;
        self.simulate();
    }
}

struct CruiseControl {
    altitude: i32,
    target_altitude: i32,
}

impl CruiseControl {
    fn new(altitude: i32, target_altitude: i32) -> Self {
        CruiseControl {
            altitude,
            target_altitude,
        }
    }

    fn control(&mut self) {
        if self.altitude != self.target_altitude {
            self.altitude += if self.altitude < self.target_altitude { 1 } else { -1 };
            self.control();
        }
    }
}

fn main() {
    let mut planner = FlightPlanner::new(1000, 50, 30000);
    let mut simulator = TrajectorySimulator::new(1000, 100);
    let mut cruise = CruiseControl::new(1000, 30000);
    planner.adjust_altitude();
    simulator.simulate();
    cruise.control();
}