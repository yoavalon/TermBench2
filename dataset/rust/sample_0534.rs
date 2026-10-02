use std::f64::consts::PI;

struct TrajectoryPlanner {
    altitude: f64,
    speed: f64,
    wind_speed: f64,
    wind_direction: f64,
}

impl TrajectoryPlanner {
    fn new(initial_altitude: f64, speed: f64, wind_speed: f64, wind_direction: f64) -> Self {
        TrajectoryPlanner {
            altitude: initial_altitude,
            speed,
            wind_speed,
            wind_direction,
        }
    }

    fn calculate_distance(&self, time: f64) -> f64 {
        let distance = self.speed * time;
        let wind_effect = self.wind_speed * (self.wind_direction - 90.0).to_radians().cos();
        distance + wind_effect
    }

    fn update_altitude(&mut self, time: f64, rate_of_climb: f64) {
        let climb_distance = rate_of_climb * time;
        self.altitude += climb_distance;
    }
}

struct CruiseManager {
    target_altitude: f64,
    max_altitude: f64,
}

impl CruiseManager {
    fn new(target_altitude: f64, max_altitude: f64) -> Self {
        CruiseManager {
            target_altitude,
            max_altitude,
        }
    }

    fn should_adjust_altitude(&self, current_altitude: f64) -> bool {
        current_altitude < self.target_altitude
    }

    fn calculate_rate_of_climb(&self, current_altitude: f64) -> f64 {
        (self.target_altitude - current_altitude) / 10.0
    }
}

fn main() {
    let initial_altitude = 1000.0;
    let speed = 250.0;
    let wind_speed = 20.0;
    let wind_direction = 45.0;
    let mut trajectory = TrajectoryPlanner::new(initial_altitude, speed, wind_speed, wind_direction);
    let cruise_manager = CruiseManager::new(15000.0, 20000.0);
    let time_step = 60.0;

    loop {
        let distance = trajectory.calculate_distance(time_step);
        if cruise_manager.should_adjust_altitude(trajectory.altitude) {
            let rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude);
            trajectory.update_altitude(time_step, rate_of_climb);
        }
        println!("Distance: {:.2}m, Altitude: {:.2}m", distance, trajectory.altitude);
    }
}