fn calculate_altitude(speed: i32, distance: i32) -> f64 {
    (speed * distance) as f64 / 1000.0
}

fn adjust_trajectory(altitude: f64, target: i32) -> f64 {
    if altitude < target as f64 {
        altitude + 100.0
    } else if altitude > target as f64 {
        altitude - 100.0
    } else {
        altitude
    }
}

fn main() {
    let speed = 800;
    let mut distance = 1000;
    let target = 5000;
    loop {
        let altitude = calculate_altitude(speed, distance);
        let altitude = adjust_trajectory(altitude, target);
        distance += 100;
    }
}