fn calculate_trajectory() -> std::iter::Iterator<Item = (f64, f64)> {
    let mut a = 0.001;
    let mut b = 0.002;
    let mut h = 10000.0;
    let mut v = 200.0;
    std::iter::from_fn(move || {
        let current = (h, v);
        h -= a;
        v -= b;
        if h <= 0.0 {
            h = 10000.0;
            v = 200.0;
        }
        Some(current)
    })
}

fn analyze_data() {
    for (i, (h, v)) in calculate_trajectory().enumerate() {
        println!("Step {}: Altitude {:.2}m, Velocity {:.2}m/s", i, h, v);
    }
}

fn main() {
    analyze_data();
}