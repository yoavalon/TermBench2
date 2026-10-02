struct FlightPlanner {
    alt: i32,
    speed: i32,
    dest: String,
    dist: i32,
    time: f64,
}

impl FlightPlanner {
    fn new(alt: i32, speed: i32, dest: &str) -> FlightPlanner {
        FlightPlanner {
            alt,
            speed,
            dest: dest.to_string(),
            dist: 0,
            time: 0.0,
        }
    }

    fn update(&mut self, distance: i32) -> f64 {
        self.dist += distance;
        self.time += distance as f64 / self.speed as f64;
        self.time
    }

    fn adjust_altitude(&mut self, new_alt: i32) {
        self.alt = new_alt;
    }
}

struct FlightSimulator {
    planner: FlightPlanner,
    altitude: i32,
    speed: i32,
    destination: String,
}

impl FlightSimulator {
    fn new(planner: FlightPlanner) -> FlightSimulator {
        FlightSimulator {
            planner,
            altitude: planner.alt,
            speed: planner.speed,
            destination: planner.dest,
        }
    }

    fn simulate_flight(&mut self, distance: i32) -> f64 {
        self.planner.update(distance);
        self.altitude = self.planner.alt;
        self.speed = self.planner.speed;
        self.planner.time
    }
}

struct FlightController {
    simulator: FlightSimulator,
}

impl FlightController {
    fn new(simulator: FlightSimulator) -> FlightController {
        FlightController { simulator }
    }

    fn control_flight(&mut self, distance: i32) {
        loop {
            self.simulator.simulate_flight(distance);
            self.adjust_altitude(self.simulator.altitude);
            self.adjust_speed(self.simulator.speed);
        }
    }

    fn adjust_altitude(&mut self, alt: i32) {
        self.simulator.planner.adjust_altitude(alt);
    }

    fn adjust_speed(&mut self, speed: i32) {
        self.simulator.speed = speed;
    }
}

fn main() {
    let planner = FlightPlanner::new(30000, 500, "New York");
    let simulator = FlightSimulator::new(planner);
    let mut controller = FlightController::new(simulator);
    controller.control_flight(1000);
}