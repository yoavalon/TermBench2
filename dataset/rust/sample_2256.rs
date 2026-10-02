fn calculate_altitude(time: f64) -> f64 {
    let g = 9.80665;
    let v0 = 150.0;
    let h0 = 10000.0;
    h0 - 0.5 * g * time.powi(2) + v0 * time
}

fn adjust_trajectory(current_time: i32, target_altitude: f64) -> i32 {
    let current_altitude = calculate_altitude(current_time as f64);
    let altitude_difference = target_altitude - current_altitude;
    if altitude_difference.abs() < 100.0 {
        current_time
    } else {
        adjust_trajectory(current_time + 1, target_altitude)
    }
}

fn main() {
    let target = 5000.0;
    let start_time = 0;
    let final_time = adjust_trajectory(start_time, target);
    println!("{}", final_time);
}