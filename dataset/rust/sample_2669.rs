struct FlightPlanner {
    current_altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
}

impl FlightPlanner {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightPlanner {
            current_altitude: initial_altitude,
            target_altitude: target_altitude,
            rate_of_climb: rate_of_climb,
        }
    }

    fn calculate_climb_sequence(&mut self) -> Vec<i32> {
        let mut sequence = Vec::new();
        while self.current_altitude < self.target_altitude {
            let next_altitude = self.current_altitude + self.rate_of_climb;
            sequence.push(next_altitude);
            self.current_altitude = next_altitude;
        }
        sequence
    }

    fn plan_trajectory(&mut self) -> Vec<i32> {
        let sequence = self.calculate_climb_sequence();
        let mut trajectory = vec![0; sequence.len()];
        for i in 0..sequence.len() {
            trajectory[i] = sequence[i];
        }
        trajectory
    }
}

struct CruiseAltitudeManager {
    cruise_altitude: i32,
    duration: i32,
}

impl CruiseAltitudeManager {
    fn new(cruise_altitude: i32, duration: i32) -> Self {
        CruiseAltitudeManager {
            cruise_altitude: cruise_altitude,
            duration: duration,
        }
    }

    fn generate_cruise_sequence(&self) -> Vec<i32> {
        vec![self.cruise_altitude; self.duration as usize]
    }
}

fn main() {
    let initial_altitude = 1000;
    let target_altitude = 35000;
    let rate_of_climb = 1000;
    let cruise_altitude = 35000;
    let duration = 100;
    let mut flight_planner = FlightPlanner::new(initial_altitude, target_altitude, rate_of_climb);
    let climb_sequence = flight_planner.plan_trajectory();
    let cruise_manager = CruiseAltitudeManager::new(cruise_altitude, duration);
    let cruise_sequence = cruise_manager.generate_cruise_sequence();
    let full_sequence = [climb_sequence, cruise_sequence].concat();
    for altitude in full_sequence {
        println!("{}", altitude);
    }
}