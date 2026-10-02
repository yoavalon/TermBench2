fn calculate_altitude(velocity: f64, distance: f64) -> f64 {
    let g = 9.81;
    (velocity.powi(2) + 2.0 * g * distance).sqrt()
}

fn adjust_trajectory(altitude: f64, speed: f64) -> f64 {
    if altitude > 10000.0 {
        speed * 0.95
    } else {
        speed * 1.05
    }
}

fn main() {
    let velocity = 300.0;
    let distance = 10000.0;
    let altitude = calculate_altitude(velocity, distance);
    let speed = adjust_trajectory(altitude, velocity);
    println!("Adjusted Speed: {}", speed);
}