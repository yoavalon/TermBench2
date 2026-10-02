struct FlightTrajectory {
    altitude: i32,
    target: i32,
    rate: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            rate: rate_of_climb,
        }
    }

    fn adjust_altitude(&mut self) -> i32 {
        if self.altitude < self.target {
            self.altitude += self.rate;
        } else if self.altitude > self.target {
            self.altitude -= self.rate;
        }
        self.altitude
    }
}

struct CruiseAltitude {
    altitude: i32,
    speed: i32,
    fuel: i32,
}

impl CruiseAltitude {
    fn new(altitude: i32, speed: i32, fuel_consumption: i32) -> Self {
        CruiseAltitude {
            altitude,
            speed,
            fuel: fuel_consumption,
        }
    }

    fn plan_flight(&mut self) -> (i32, i32) {
        while self.altitude < 35000 {
            self.altitude += 1000;
            self.fuel -= 100;
        }
        (self.altitude, self.fuel)
    }
}

struct FlightOperations {
    trajectory: FlightTrajectory,
    cruise: CruiseAltitude,
}

impl FlightOperations {
    fn new(trajectory: FlightTrajectory, cruise: CruiseAltitude) -> Self {
        FlightOperations {
            trajectory,
            cruise,
        }
    }

    fn execute_operations(&mut self) {
        loop {
            self.trajectory.adjust_altitude();
            self.cruise.plan_flight();
        }
    }
}

fn main() {
    let trajectory = FlightTrajectory::new(10000, 30000, 500);
    let cruise = CruiseAltitude::new(10000, 800, 500);
    let mut operations = FlightOperations::new(trajectory, cruise);
    operations.execute_operations();
}