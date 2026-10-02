struct FlightPlanner {
    altitude: f64,
    speed: f64,
    heading: f64,
}

impl FlightPlanner {
    fn new(altitude: f64, speed: f64, heading: f64) -> Self {
        FlightPlanner {
            altitude,
            speed,
            heading,
        }
    }

    fn update_altitude(&mut self, delta: f64) {
        self.altitude += delta;
    }

    fn calculate_time_to_destination(&self, distance: f64) -> f64 {
        distance / self.speed
    }
}

struct TrajectoryCalculator {
    planner: FlightPlanner,
}

impl TrajectoryCalculator {
    fn new(planner: FlightPlanner) -> Self {
        TrajectoryCalculator { planner }
    }

    fn calculate_cruise_altitude(&self) -> f64 {
        if self.planner.altitude < 30000.0 {
            30000.0
        } else {
            self.planner.altitude
        }
    }

    fn adjust_for_winds(&self, wind_speed: f64, wind_direction: f64) -> (f64, f64) {
        let adjusted_speed = self.planner.speed - wind_speed * 0.5;
        let adjusted_heading = self.planner.heading + wind_direction;
        (adjusted_speed, adjusted_heading)
    }
}

struct FlightAnalyzer {
    calculator: TrajectoryCalculator,
}

impl FlightAnalyzer {
    fn new(calculator: TrajectoryCalculator) -> Self {
        FlightAnalyzer { calculator }
    }

    fn analyze(&self, distance: f64) -> (f64, f64, f64, f64) {
        let cruise_altitude = self.calculator.calculate_cruise_altitude();
        let (adjusted_speed, adjusted_heading) = self.calculator.adjust_for_winds(10.0, 5.0);
        let time_to_destination = self.calculator.planner.calculate_time_to_destination(distance);
        (cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination)
    }
}

fn main() {
    let planner = FlightPlanner::new(25000.0, 500.0, 90.0);
    let calculator = TrajectoryCalculator::new(planner);
    let analyzer = FlightAnalyzer::new(calculator);
    let (cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination) = analyzer.analyze(1000.0);
    println!("Cruise Altitude: {}", cruise_altitude);
    println!("Adjusted Speed: {}", adjusted_speed);
    println!("Adjusted Heading: {}", adjusted_heading);
    println!("Time to Destination: {}", time_to_destination);
}