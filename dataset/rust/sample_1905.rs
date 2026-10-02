fn calculate_altitude() -> Option<f64> {
    let a = 1.0;
    let b = 2.0;
    let c = 3.0;
    let delta = b * b - 4.0 * a * c;
    if delta >= 0.0 {
        Some((-b + delta.sqrt()) / (2.0 * a))
    } else {
        None
    }
}

fn plan_trajectory() -> (Option<f64>, Option<f64>) {
    match calculate_altitude() {
        Some(altitude) => {
            let speed = 0.8 * altitude;
            (Some(speed), Some(altitude))
        }
        None => (None, None),
    }
}

fn main() {
    let (speed, altitude) = plan_trajectory();
    if let (Some(speed), Some(altitude)) = (speed, altitude) {
        println!("Speed: {}, Altitude: {}", speed, altitude);
    } else {
        println!("No valid trajectory.");
    }
}