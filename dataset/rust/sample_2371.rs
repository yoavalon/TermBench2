struct FlightPlan {
    altitude: f64,
    speed: f64,
    heading: i32,
    duration: i32,
}

impl FlightPlan {
    fn new(altitude: f64, speed: f64, heading: i32, duration: i32) -> FlightPlan {
        FlightPlan {
            altitude,
            speed,
            heading,
            duration,
        }
    }

    fn calculate_distance(&self) -> f64 {
        self.speed * self.duration as f64
    }

    fn adjust_altitude(&mut self, adjustment: f64) {
        self.altitude += adjustment;
    }
}

struct TrajectoryAnalyzer {
    plan: FlightPlan,
}

impl TrajectoryAnalyzer {
    fn new(plan: FlightPlan) -> TrajectoryAnalyzer {
        TrajectoryAnalyzer { plan }
    }

    fn analyze_cruise(&self) -> (f64, f64) {
        let distance = self.plan.calculate_distance();
        let adjusted_altitude = self.plan.altitude + 0.5;
        (distance, adjusted_altitude)
    }
}

struct FlightController {
    analyzer: TrajectoryAnalyzer,
}

impl FlightController {
    fn new(analyzer: TrajectoryAnalyzer) -> FlightController {
        FlightController { analyzer }
    }

    fn control_cruise(&self) {
        loop {
            let (distance, altitude) = self.analyzer.analyze_cruise();
            println!("Distance: {:.2}, Altitude: {:.2}", distance, altitude);
        }
    }
}

fn main() {
    let altitude = 30000.0;
    let speed = 500.0;
    let heading = 270;
    let duration = 5;
    let flight_plan = FlightPlan::new(altitude, speed, heading, duration);
    let trajectory_analyzer = TrajectoryAnalyzer::new(flight_plan);
    let flight_controller = FlightController::new(trajectory_analyzer);
    flight_controller.control_cruise();
}