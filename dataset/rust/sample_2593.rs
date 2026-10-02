fn calculate_trajectory(velocity: f64, altitude: f64, time: f64) -> (f64, f64) {
    let gravity = 9.81;
    let distance = velocity * time;
    let altitude_change = velocity * time - 0.5 * gravity * time.powi(2);
    (distance, altitude + altitude_change)
}

fn plan_cruise_altitude(initial_altitude: f64, max_altitude: f64, rate_of_climb: f64, time: f64) -> f64 {
    if initial_altitude < max_altitude {
        let new_altitude = initial_altitude + rate_of_climb * time;
        f64::min(new_altitude, max_altitude)
    } else {
        initial_altitude
    }
}

fn main() {
    let velocity = 250.0;
    let altitude = 5000.0;
    let time = 3600.0;
    let max_altitude = 10000.0;
    let rate_of_climb = 500.0;
    let (distance, new_altitude) = calculate_trajectory(velocity, altitude, time);
    let cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
    println!("Distance covered: {} meters", distance);
    println!("New altitude: {} meters", new_altitude);
    println!("Cruise altitude: {} meters", cruise_altitude);
}