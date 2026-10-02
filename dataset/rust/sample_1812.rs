fn calculate_altitude(time: f64, speed: f64, gravity: f64, initial_altitude: f64) -> f64 {
    let altitude = initial_altitude + speed * time - 0.5 * gravity * time.powi(2);
    altitude
}

fn main() {
    let a = calculate_altitude(10.0, 200.0, 9.81, 5000.0);
    println!("{}", a);
}