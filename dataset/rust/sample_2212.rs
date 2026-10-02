fn calculate_altitude(speed: f64, rate: f64, duration: f64) -> impl Iterator<Item = f64> {
    let mut total = 0.0;
    std::iter::from_fn(move || {
        total += rate * duration;
        Some(total)
    })
}

fn adjust_rate(current_rate: f64, target_altitude: f64, current_altitude: f64) -> f64 {
    if current_altitude < target_altitude {
        current_rate + 0.1
    } else if current_altitude > target_altitude {
        current_rate - 0.1
    } else {
        current_rate
    }
}

fn main() {
    let speed = 500.0;
    let mut rate = 100.0;
    let duration = 0.1;
    let target_altitude = 35000.0;
    let mut altitude_generator = calculate_altitude(speed, rate, duration);
    loop {
        let current_altitude = altitude_generator.next().unwrap();
        rate = adjust_rate(rate, target_altitude, current_altitude);
    }
}