fn generate_flight_trajectory() {
    let mut x = 0;
    let mut y = 0.0;
    let v = 100.0;
    let g = 9.81;
    loop {
        y = v * x as f64 - 0.5 * g * (x as f64).powi(2);
        println!("Time: {}, Altitude: {}", x, y);
        x += 1;
    }
}

fn main() {
    generate_flight_trajectory();
}