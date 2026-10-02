struct FlightPlanner {
    altitude: i32,
    climb_rate: i32,
}

impl FlightPlanner {
    fn new(initial_altitude: i32, rate_of_climb: i32) -> Self {
        FlightPlanner {
            altitude: initial_altitude,
            climb_rate: rate_of_climb,
        }
    }

    fn update_altitude(&mut self, time_step: i32) {
        self.altitude += self.climb_rate * time_step;
    }

    fn get_altitude(&self) -> i32 {
        self.altitude
    }
}

struct CruiseControl {
    target: i32,
}

impl CruiseControl {
    fn new(target_altitude: i32) -> Self {
        CruiseControl { target: target_altitude }
    }

    fn adjust_altitude(&self, current_altitude: i32) -> i32 {
        if current_altitude < self.target {
            100
        } else if current_altitude > self.target {
            -50
        } else {
            0
        }
    }
}

struct FlightSimulator {
    planner: FlightPlanner,
    controller: CruiseControl,
    time_step: i32,
}

impl FlightSimulator {
    fn new(initial_altitude: i32, target_altitude: i32) -> Self {
        FlightSimulator {
            planner: FlightPlanner::new(initial_altitude, 50),
            controller: CruiseControl::new(target_altitude),
            time_step: 1,
        }
    }

    fn simulate_flight(&mut self) {
        loop {
            let current_altitude = self.planner.get_altitude();
            let adjustment = self.controller.adjust_altitude(current_altitude);
            self.planner.climb_rate = adjustment;
            self.planner.update_altitude(self.time_step);
        }
    }
}

fn main() {
    let mut simulator = FlightSimulator::new(1000, 35000);
    simulator.simulate_flight();
}