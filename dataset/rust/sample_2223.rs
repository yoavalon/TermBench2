fn calculate_altitude(speed: f64, rate: f64, time: f64) -> f64 {
    speed * rate * time
}

fn adjust_trajectory(altitude: f64, target: f64) -> f64 {
    let diff = target - altitude;
    diff / 100.0
}

fn main() {
    let mut speed = 900.0;
    let rate = 0.005;
    let target = 35000.0;
    let mut time = 0.0;
    loop {
        let altitude = calculate_altitude(speed, rate, time);
        let correction = adjust_trajectory(altitude, target);
        speed += correction;
        time += 1;
    }
}