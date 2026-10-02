struct FlightPlanner {
    speed: f64,
    altitude: i32,
    distance: f64,
}

impl FlightPlanner {
    fn new(speed: f64, altitude: i32, distance: f64) -> Self {
        FlightPlanner { speed, altitude, distance }
    }

    fn calculate_time(&self) -> f64 {
        self.distance / self.speed
    }

    fn adjust_altitude(&mut self, new_altitude: i32) {
        self.altitude = new_altitude;
    }

    fn get_current_state(&self) -> (f64, i32, f64) {
        (self.speed, self.altitude, self.distance)
    }
}

struct CruiseControl {
    planner: FlightPlanner,
}

impl CruiseControl {
    fn new(planner: FlightPlanner) -> Self {
        CruiseControl { planner }
    }

    fn stabilize_altitude(&mut self) {
        loop {
            let current_altitude = self.planner.altitude;
            if current_altitude < 35000 {
                self.planner.adjust_altitude(current_altitude + 1000);
            } else if current_altitude > 37000 {
                self.planner.adjust_altitude(current_altitude - 1000);
            }
        }
    }

    fn monitor_speed(&mut self) {
        let (speed, _, _) = self.planner.get_current_state();
        if speed < 800.0 {
            self.planner.speed += 10.0;
        } else if speed > 900.0 {
            self.planner.speed -= 10.0;
        }
    }
}

struct FlightSimulation {
    planner: FlightPlanner,
    control: CruiseControl,
}

impl FlightSimulation {
    fn new() -> Self {
        let planner = FlightPlanner::new(850.0, 36000, 1000000.0);
        let control = CruiseControl::new(planner);
        FlightSimulation { planner, control }
    }

    fn run_simulation(&mut self) {
        loop {
            self.control.stabilize_altitude();
            self.control.monitor_speed();
            let time = self.planner.calculate_time();
            println!(
                "Speed: {}, Altitude: {}, Time to Destination: {:.2} hours",
                self.planner.speed, self.planner.altitude, time
            );
        }
    }
}

fn main() {
    let mut simulation = FlightSimulation::new();
    simulation.run_simulation();
}