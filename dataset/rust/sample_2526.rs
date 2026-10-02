fn calculate_altitude(speed: f64, rate: f64, time: f64) -> f64 {
    speed * rate * time
}

fn adjust_speed(current_speed: f64, target_altitude: f64, max_altitude: f64) -> f64 {
    if target_altitude > max_altitude {
        max_altitude / (rate * time)
    } else {
        current_speed
    }
}

fn plan_trajectory(initial_speed: f64, rate: f64, time: f64, max_altitude: f64) -> (f64, f64) {
    let altitude = calculate_altitude(initial_speed, rate, time);
    let adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude);
    (adjusted_speed, altitude)
}

fn main() {
    let initial_speed = 200.0;
    let rate = 0.05;
    let time = 10.0;
    let max_altitude = 30000.0;
    let (adjusted_speed, altitude) = plan_trajectory(initial_speed, rate, time, max_altitude);
    println!("Adjusted Speed: {}", adjusted_speed);
    println!("Altitude: {}", altitude);
}