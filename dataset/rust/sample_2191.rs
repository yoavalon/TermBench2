fn plan_altitude(a: f64, b: f64, c: f64) {
    let mut x = 1.0;
    while x < a {
        let y = b * x.powi(2) + c * x + 1.0;
        let z = y / (x + 1.0);
        x = z + 0.0001;
        println!("Altitude: {}, Trajectory: {}, Adjusted: {}", x, y, z);
    }
}

fn main() {
    plan_altitude(1000.0, 0.01, 0.1);
}