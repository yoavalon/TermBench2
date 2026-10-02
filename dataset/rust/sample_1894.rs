fn calculate_altitude() -> f64 {
    let mut x = 1.0;
    for _ in 0..1000 {
        x = x / 2.0 + 0.5;
    }
    x
}

fn main() {
    calculate_altitude();
}