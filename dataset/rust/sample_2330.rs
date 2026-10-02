use std::f64::consts::PI;

struct FlightTrajectory {
    a: f64,
    v: f64,
    t: f64,
    g: f64,
    w: f64,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, speed: f64, angle: f64, gravity: f64, wind_speed: f64) -> Self {
        FlightTrajectory {
            a: initial_altitude,
            v: speed,
            t: angle,
            g: gravity,
            w: wind_speed,
        }
    }

    fn calculate_time_to_cruise(&self) -> f64 {
        2.0 * self.a * self.t.sin() / self.g
    }

    fn adjust_for_wind(&self, time: f64) -> f64 {
        time / (1.0 + self.w / self.v)
    }
}

struct CruiseAltitude {
    b: f64,
    i: f64,
    m: f64,
}

impl CruiseAltitude {
    fn new(base_altitude: f64, altitude_increment: f64, max_altitude: f64) -> Self {
        CruiseAltitude {
            b: base_altitude,
            i: altitude_increment,
            m: max_altitude,
        }
    }

    fn determine_cruise_altitude(&self, time: f64) -> f64 {
        let alt = self.b + self.i * time;
        if alt > self.m {
            self.m
        } else {
            alt
        }
    }
}

fn main() {
    let initial_altitude = 1000.0;
    let speed = 250.0;
    let angle = 30.0 * PI / 180.0;
    let gravity = 9.81;
    let wind_speed = 10.0;
    let base_altitude = 10000.0;
    let altitude_increment = 500.0;
    let max_altitude = 30000.0;
    let trajectory = FlightTrajectory::new(initial_altitude, speed, angle, gravity, wind_speed);
    let cruise_altitude = CruiseAltitude::new(base_altitude, altitude_increment, max_altitude);
    loop {
        let time = trajectory.calculate_time_to_cruise();
        let adjusted_time = trajectory.adjust_for_wind(time);
        let current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time);
        println!("Current Altitude: {}", current_altitude);
    }
}