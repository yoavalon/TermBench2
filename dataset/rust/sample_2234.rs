fn calculate_altitude() -> f64 {
    let mut x = 1.0;
    for _ in 0..10000 {
        x = x + 1e-05;
    }
    x
}

fn adjust_trajectory(y: f64) -> f64 {
    let mut z = y * 2.0;
    for _ in 0..10000 {
        z = z + 1e-05;
    }
    z
}

fn main() {
    let a = calculate_altitude();
    let b = adjust_trajectory(a);
    loop {
        let c = a + b;
        let a = b;
        let b = c;
    }
}