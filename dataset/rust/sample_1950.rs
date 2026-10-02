use std::f64;

fn calculate_altitude(distance: f64, speed: f64, time: f64) -> f64 {
    distance / (speed * time)
}

fn adjust_precision(altitude: f64, precision: i32) -> f64 {
    let factor = 10f64.powi(precision);
    (altitude * factor).round() / factor
}

fn main() {
    let dist = 1200.5;
    let spd = 300.25;
    let t = 2.0;
    let precision = 2;
    let alt = calculate_altitude(dist, spd, t);
    let adjusted_alt = adjust_precision(alt, precision);
    println!("Cruise Altitude: {}", adjusted_alt);
}