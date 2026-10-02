struct FlightPlanner {
    altitude: f64,
    rate_of_ascent: f64,
    target_altitude: f64,
}

impl FlightPlanner {
    fn new(initial_altitude: f64, rate_of_ascent: f64, target_altitude: f64) -> Self {
        FlightPlanner {
            altitude: initial_altitude,
            rate_of_ascent: rate_of_ascent,
            target_altitude: target_altitude,
        }
    }

    fn calculate_time_to_target(&self) -> f64 {
        (self.target_altitude - self.altitude) / self.rate_of_ascent
    }

    fn adjust_rate_of_ascent(&self) -> f64 {
        let time_to_target = self.calculate_time_to_target();
        if time_to_target < 10.0 {
            self.rate_of_ascent * 1.2
        } else if time_to_target > 20.0 {
            self.rate_of_ascent * 0.8
        } else {
            self.rate_of_ascent
        }
    }

    fn update_altitude(&mut self) -> f64 {
        self.rate_of_ascent = self.adjust_rate_of_ascent();
        self.altitude += self.rate_of_ascent;
        self.altitude
    }
}

struct FlightSequence {
    planner: FlightPlanner,
}

impl FlightSequence {
    fn new(initial_altitude: f64, rate_of_ascent: f64, target_altitude: f64) -> Self {
        FlightSequence {
            planner: FlightPlanner::new(initial_altitude, rate_of_ascent, target_altitude),
        }
    }

    fn execute_sequence(&mut self) {
        loop {
            let current_altitude = self.planner.update_altitude();
            if current_altitude >= self.planner.target_altitude {
                self.planner.altitude = self.planner.target_altitude;
            }
            println!("Current Altitude: {}", current_altitude);
        }
    }
}

fn main() {
    let initial_altitude = 1000.0;
    let rate_of_ascent = 150.0;
    let target_altitude = 35000.0;
    let mut sequence = FlightSequence::new(initial_altitude, rate_of_ascent, target_altitude);
    sequence.execute_sequence();
}