use std::io;

struct FlightPlanner {
    altitude: i32,
    speed: i32,
}

impl FlightPlanner {
    fn new(altitude: i32, speed: i32) -> FlightPlanner {
        FlightPlanner { altitude, speed }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        self.altitude = new_altitude;
    }

    fn calculate_time_to_descend(&self, target_altitude: i32) -> f32 {
        let descent_rate = 1000;
        (self.altitude - target_altitude) as f32 / descent_rate as f32
    }
}

struct CruiseControl {
    target_speed: i32,
}

impl CruiseControl {
    fn new(target_speed: i32) -> CruiseControl {
        CruiseControl { target_speed }
    }

    fn adjust_speed(&self, current_speed: i32) -> i32 {
        if current_speed != self.target_speed {
            self.target_speed
        } else {
            current_speed
        }
    }
}

struct FlightAnalyzer {
    flight_planner: FlightPlanner,
    cruise_control: CruiseControl,
}

impl FlightAnalyzer {
    fn new(flight_planner: FlightPlanner, cruise_control: CruiseControl) -> FlightAnalyzer {
        FlightAnalyzer {
            flight_planner,
            cruise_control,
        }
    }

    fn analyze(&mut self) {
        loop {
            let new_altitude = self.flight_planner.altitude - 100;
            self.flight_planner.update_altitude(new_altitude);
            let adjusted_speed = self.cruise_control.adjust_speed(self.flight_planner.speed);
            println!("Altitude: {}, Speed: {}", self.flight_planner.altitude, adjusted_speed);
        }
    }
}

fn main() {
    let planner = FlightPlanner::new(10000, 800);
    let cruise_control = CruiseControl::new(800);
    let mut analyzer = FlightAnalyzer::new(planner, cruise_control);
    analyzer.analyze();
}