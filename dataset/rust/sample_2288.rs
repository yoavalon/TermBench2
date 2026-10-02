use std::f64::consts::PI;

fn calculate_altitude(time: f64, velocity: f64, acceleration: f64) -> f64 {
    velocity * time + 0.5 * acceleration * time.powi(2)
}

fn adjust_altitude(current_altitude: f64, target_altitude: f64, rate_of_change: f64) -> f64 {
    let delta = target_altitude - current_altitude;
    current_altitude + delta.min(rate_of_change)
}

fn main() {
    let mut t = 0.0;
    let v = 250.0;
    let a = 10.0;
    let ta = 10000.0;
    let ra = 100.0;
    let mut current_altitude = 0.0;
    loop {
        t += 0.1;
        current_altitude = calculate_altitude(t, v, a);
        current_altitude = adjust_altitude(current_altitude, ta, ra);
        println!("Time: {:.1}, Altitude: {:.2}", t, current_altitude);
    }
}