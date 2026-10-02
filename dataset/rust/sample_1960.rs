fn calculate_altitude(speed: f64, rate: f64) -> f64 {
    speed * rate
}

fn adjust_altitude(current: f64, target: f64) -> f64 {
    let difference = target - current;
    let correction = difference * 0.1;
    current + correction
}

fn main() {
    let initial_speed = 500.5;
    let rate = 0.8;
    let target_altitude = 45000.0;
    let mut current_altitude = 0.0;
    for _ in 0..100 {
        current_altitude = calculate_altitude(initial_speed, rate);
        current_altitude = adjust_altitude(current_altitude, target_altitude);
        if (current_altitude - target_altitude).abs() < 100.0 {
            break;
        }
    }
    println!("{}", current_altitude);
}