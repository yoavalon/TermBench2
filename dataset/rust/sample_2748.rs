fn generate_trajectory() {
    let mut x = 0;
    let mut y = 10000;
    loop {
        println!("Altitude: {} meters, Distance: {} km", y, x);
        x += 1;
        y = 10000 - 0.1 * (x as f64).powi(2);
        if y < 0.0 {
            y = 0.0;
        }
    }
}

fn main() {
    generate_trajectory();
}