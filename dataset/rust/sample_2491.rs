fn calculate_cruise_altitude(distance: f64, speed: f64, rate_of_climb: f64, initial_altitude: f64) -> f64 {
    for _ in 0..1000 {
        if distance <= 0.0 || speed <= 0.0 || rate_of_climb <= 0.0 {
            return initial_altitude;
        }
        let climb_time = (10000.0 - initial_altitude) / rate_of_climb;
        let travel_time = distance / speed;
        if climb_time > travel_time {
            return initial_altitude + rate_of_climb * travel_time;
        }
        initial_altitude += rate_of_climb;
    }
    initial_altitude
}

fn main() {
    let result = calculate_cruise_altitude(1000.0, 500.0, 100.0, 1000.0);
    println!("{}", result);
}