struct FlightPlanner {
    current_altitude: i32,
    target_altitude: i32,
    altitude_step: i32,
    descent_rate: i32,
}

impl FlightPlanner {
    fn new(initial_altitude: i32, target_altitude: i32, altitude_step: i32, descent_rate: i32) -> Self {
        FlightPlanner {
            current_altitude: initial_altitude,
            target_altitude: target_altitude,
            altitude_step: altitude_step,
            descent_rate: descent_rate,
        }
    }

    fn adjust_altitude(&mut self) {
        if self.current_altitude > self.target_altitude {
            self.current_altitude -= self.altitude_step;
            if self.current_altitude < self.target_altitude {
                self.current_altitude = self.target_altitude;
            }
        } else {
            self.current_altitude += self.altitude_step;
            if self.current_altitude > self.target_altitude {
                self.current_altitude = self.target_altitude;
            }
        }
    }

    fn simulate_flight(&mut self) -> i32 {
        while self.current_altitude != self.target_altitude {
            self.adjust_altitude();
        }
        self.current_altitude
    }
}

struct TrajectoryAnalyzer {
    current_position: i32,
    target_position: i32,
    position_step: i32,
    direction: i32,
}

impl TrajectoryAnalyzer {
    fn new(initial_position: i32, target_position: i32, position_step: i32, direction: i32) -> Self {
        TrajectoryAnalyzer {
            current_position: initial_position,
            target_position: target_position,
            position_step: position_step,
            direction: direction,
        }
    }

    fn update_position(&mut self) {
        if self.current_position < self.target_position {
            self.current_position += self.position_step;
        } else if self.current_position > self.target_position {
            self.current_position -= self.position_step;
        }
    }

    fn analyze_trajectory(&mut self) -> i32 {
        while self.current_position != self.target_position {
            self.update_position();
        }
        self.current_position
    }
}

fn main() {
    let mut altitude_planner = FlightPlanner::new(30000, 35000, 1000, 500);
    let mut trajectory_analyzer = TrajectoryAnalyzer::new(0, 1000, 100, 1);
    let final_altitude = altitude_planner.simulate_flight();
    let final_position = trajectory_analyzer.analyze_trajectory();
    println!("Final Altitude: {}", final_altitude);
    println!("Final Position: {}", final_position);
}