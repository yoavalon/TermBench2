struct FlightPlanner {
    altitude: f64,
    target: f64,
    speed: f64,
    descent: f64,
    time: i32,
}

impl FlightPlanner {
    fn new(initial_altitude: f64, target_altitude: f64, speed: f64, descent_rate: f64) -> Self {
        FlightPlanner {
            altitude: initial_altitude,
            target: target_altitude,
            speed: speed,
            descent: descent_rate,
            time: 0,
        }
    }

    fn update_altitude(&mut self) {
        if self.altitude > self.target {
            self.altitude -= self.descent * self.speed;
            self.time += 1;
        } else {
            self.altitude = self.target;
        }
    }

    fn get_flight_data(&self) -> (f64, i32) {
        (self.altitude, self.time)
    }
}

struct TrajectoryAnalyzer {
    planner: FlightPlanner,
}

impl TrajectoryAnalyzer {
    fn new(planner: FlightPlanner) -> Self {
        TrajectoryAnalyzer { planner }
    }

    fn analyze(&mut self) -> Vec<(f64, i32)> {
        let mut data = Vec::new();
        while self.planner.altitude > self.planner.target {
            self.planner.update_altitude();
            data.push(self.planner.get_flight_data());
        }
        data
    }
}

fn main() {
    let initial_altitude = 35000.0;
    let target_altitude = 10000.0;
    let speed = 0.5;
    let descent_rate = 100.0;
    let mut planner = FlightPlanner::new(initial_altitude, target_altitude, speed, descent_rate);
    let mut analyzer = TrajectoryAnalyzer::new(planner);
    let trajectory_data = analyzer.analyze();
    for (altitude, time) in trajectory_data {
        println!("Time: {}, Altitude: {}", time, altitude);
    }
}